/*
** exec_prgm.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:43:08 2016 Pierre Chauchoy
** Last update Tue May 24 19:44:47 2016 Pierre Chauchoy
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

int			exec_prgm(t_mysh *mysh, char *s)
{
  pid_t			pid;
  int			sig;

  if ((pid = fork()) == -1)
    return (at_exit_mysh_err(ERR_FORK, mysh));
  wait(&sig);
  if (pid == 0)
    {
      if (execve(s, mysh->command, mysh->env) == -1)
	return (at_exit_mysh_err(ERR_EXECVE, mysh));
    }
  if (WIFSIGNALED(sig))
    {
      if (WTERMSIG(sig) == SIGSEGV)
	my_printf(ERR_SEGFAULT);
      if (WTERMSIG(sig) == SIGFPE)
	my_printf(ERR_FLOATING);
      if (WTERMSIG(sig) == SIGABRT)
	my_printf(ERR_ABORT);
    }
  return (0);
}
