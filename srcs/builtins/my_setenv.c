/*
** my_setenv.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 18:55:30 2016 Pierre Chauchoy
** Last update Fri Jun  3 15:08:38 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int		modify_env(t_mysh *mysh, int i)
{
  int			len;

  my_free_str(&mysh->env[i]);
  if ((len = my_len_wordtab(mysh->command)) == 2)
    {
      if (!(mysh->env[i] = my_strstr("%s=", mysh->command[1])))
	return (1);
    }
  else if (len == 3)
    if (!(mysh->env[i] =
	  my_strstr("%s=%s", mysh->command[1], mysh->command[2])))
      return (1);
  return (0);
}

static int		add_env(t_mysh *mysh)
{
  int			len;
  char			*add;
  char			**tmp;

  add = NULL;
  if ((len = my_len_wordtab(mysh->command)) == 2)
    {
      if (!(add = my_strstr("%s=", mysh->command[1])))
	return (1);
    }
  else if (!(add = my_strstr("%s=%s", mysh->command[1], mysh->command[2])))
    return (1);
  if (!(tmp = my_wordtab_dup(mysh->env)))
    return (at_exit_free(&add));
  my_free_wordtab(&mysh->env);
  mysh->env = NULL;
  if (!(mysh->env = my_wordtabcat_string(tmp, add)))
    return (at_exit_free(&add));
  my_free_wordtab(&tmp);
  tmp = NULL;
  my_free_str(&add);
  return (0);
}

static int		my_setenv_line(t_mysh *mysh)
{
  int			i;
  int			len;

  i = -1;
  len = my_strlen(mysh->command[1]);
  while (mysh->env[++i] &&
	 (my_strncmp(mysh->env[i], mysh->command[1], len) == 0 ?
	  (mysh->env[i][len] == EQUAL ? 0 : 1) : 1));
  if (!(mysh->env[i]))
    {
      if (add_env(mysh))
	return (1);
    }
  else
    if (modify_env(mysh, i))
      return (1);
  if (my_strcmp(mysh->command[1], SHPATH) == 0)
    if (reload_path(mysh))
      return (1);
  return (0);
}

int			my_setenv(t_mysh *mysh)
{
  if (my_len_wordtab(mysh->command) == 1)
    my_show_wordtab(mysh->env);
  else
    if (my_setenv_line(mysh))
      return (1);
  mysh->value.last_command = 0;
  return (0);
}
