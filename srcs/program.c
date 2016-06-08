/*
** program.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 13:05:32 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:46:31 2016 Pierre Chauchoy
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int		is_in_dir(char *dir, char *s)
{
  DIR			*dirp;
  struct dirent		*dp;

  if (!dir)
    return (1);
  if (!(dirp = opendir(dir)))
    return (1);
  while ((dp = readdir(dirp)))
    if (my_strcmp(dp->d_name, s) == 0)
      {
	closedir(dirp);
	return (0);
      }
  closedir(dirp);
  return (1);
}

static int		simple_exec(t_mysh *mysh)
{
  if (is_in_dir(mysh->dir.cur, mysh->command[0]) == 0)
    {
      my_printf("%s: %s.\n", mysh->command[0], ERR_CMD);
      return (0);
    }
  else if (my_strlen(mysh->command[0]) >= 2 &&
	   is_in_dir(mysh->dir.cur, &mysh->command[0][2]) == 0 &&
	   mysh->command[0][0] != POINT && mysh->command[0][1] == SLASH)
    {
      my_printf("%s: %s.\n", mysh->command[0], ERR_CMD);
      return (0);
    }
  else if (access(mysh->command[0], X_OK) == F_OK)
    {
      if (exec_prgm(mysh, mysh->command[0]))
	return (1);
    }
  else
    my_printf("%s: %s.\n", mysh->command[0], ERR_CMD);
  return (0);
}

static int		exec_with_path2(t_mysh *mysh, int i)
{
  if (!mysh->path || !mysh->path[i])
    if (simple_exec(mysh))
      return (1);
  return (0);
}

static int		exec_with_path(t_mysh *mysh)
{
  int			i;
  char			*bin;

  i = -1;
  bin = NULL;
  while (mysh->path && mysh->path[++i])
    {
      if (mysh->command[0][0] == POINT && mysh->command[0][1] == SLASH)
	continue ;
      if (!(bin = my_strstr("%s/%s", mysh->path[i], mysh->command[0])))
	return (at_exit_mysh_1(mysh));
      if (access(bin, X_OK) == F_OK)
	{
	  if (exec_prgm(mysh, bin))
	    return (at_exit_free(&bin));
	  my_free_str(&bin);
	  break ;
	}
      my_free_str(&bin);
    }
  if (exec_with_path2(mysh, i))
    return (1);
  bin ? my_free_str(&bin) : 0;
  return (0);
}

int			program(t_mysh *mysh)
{
  int			i;

  if (!mysh->command[0])
    return (0);
  i = -1;
  while (mysh->bi[++i] && my_strcmp(mysh->bi[i], mysh->command[0]));
  if (mysh->prgm[i])
    {
      if (mysh->prgm[i](mysh))
	return (at_exit_mysh_1(mysh));
    }
  else if (exec_with_path(mysh))
    return (1);
  return (0);
}
