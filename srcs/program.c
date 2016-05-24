/*
** program.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 13:05:32 2016 Pierre Chauchoy
** Last update Tue May 24 18:31:23 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int		simple_exec(t_mysh *mysh)
{
  if (access(mysh->command[0], X_OK) == F_OK)
    {
      if (exec_prgm(mysh, mysh->command[0]))
	return (1);
    }
  else
    my_printf("%s: %s.\n", mysh->command[0], ERR_CMD);
  return (0);
}

static int	        exec_with_path(t_mysh *mysh)
{
  int			i;
  char			*bin;

  i = -1;
  while (mysh->path && mysh->path[++i])
    {
      if (!(bin = my_strstr("%s/%s", mysh->path[i], mysh->command[0])))
	return (at_exit_mysh_1(mysh));
      if (access(bin, X_OK) == F_OK)
	{
	  if (exec_prgm(mysh, bin))
	    return (1);
	  free(bin);
	  break ;
	}
      my_free_str(&bin);
    }
  if (!mysh->path || !mysh->path[i])
    if (simple_exec(mysh))
      return (1);
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
