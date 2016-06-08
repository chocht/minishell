/*
** my_cd.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 18:55:35 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:51:05 2016 Pierre Chauchoy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int		change_dir_or_error(char *s)
{
  struct stat		sb;

  if (stat(s, &sb) == -1)
    {
      my_fprintf(2, "%s: %s.\n", s, ERR_NOTHING);
      return (1);
    }
  if (!(sb.st_mode & S_IRUSR) || !(sb.st_mode & S_IRGRP) ||
      !(sb.st_mode & S_IROTH))
    {
      my_fprintf(2, "%s: %s.\n", s, ERR_PERM);
      return (1);
    }
  if (chdir(s) == -1)
    {
      my_fprintf(2, "%s: %s.\n", s, ERR_NOT_DIR);
      return (1);
    }
  return (0);
}

static int	        update_pwd_in_path(t_mysh *mysh, char *dir)
{
  char			*line;

  if (!(line = my_strstr("setenv %s %s", "PWD", dir)))
    return (1);
  my_free_wordtab(&mysh->command);
  mysh->command = NULL;
  if (!(mysh->command = my_str_to_wordtab(line, SEP_CMD)))
    return (at_exit_free(&line));
  my_free_str(&line);
  if (my_setenv(mysh))
    return (1);
  return (0);
}

int			update_old_and_cur_dir(t_mysh *mysh, char *s)
{
  char			dir[LEN_GETCWD];

  if (!(getcwd(dir, LEN_GETCWD)))
    return (1);
  if (change_dir_or_error(s))
    return (0);
  if (mysh->dir.old)
    my_free_str(&mysh->dir.old);
  if (!(mysh->dir.old = my_strdup(dir)))
    return (1);
  if (!(getcwd(dir, LEN_GETCWD)))
    return (1);
  if (mysh->dir.cur)
    my_free_str(&mysh->dir.cur);
  if (!(mysh->dir.cur = my_strdup(dir)))
    return (1);
  my_printf("%s %s\n", MSG_DIR, dir);
  if (update_pwd_in_path(mysh, dir))
    return (1);
  mysh->value.last_command = 0;
  return (0);
}

int			my_cd(t_mysh *mysh)
{
  int			len;

  if ((len = my_len_wordtab(mysh->command)) > 2)
    my_fprintf(2, "%s: %s.\n", CD, ERR_MANYARGS);
  else if (len == 1 || (len == 2 && my_strcmp(mysh->command[1], TILDE) == 0))
    {
      if (update_old_and_cur_dir(mysh, mysh->dir.home))
	return (1);
    }
  else if (my_strcmp(mysh->command[1], MINUSS) == 0)
    {
      if (update_old_and_cur_dir(mysh, mysh->dir.old))
	return (1);
    }
  else
    {
      if (update_old_and_cur_dir(mysh, mysh->command[1]))
	return (1);
    }
  return (0);
}
