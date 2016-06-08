/*
** my_spipe.c for 42sh in /home/andrea_j/rendu/Shell_Programming/PSU_2015_42sh
** 
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
** 
** Started on  Sun Jun  5 23:28:05 2016 Julien Andreani
** Last update Sun Jun  5 23:46:53 2016 Julien Andreani
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int	my_spipe2(t_mysh *mysh, int pid, t_elem **tmp, int *pfd)
{
  if (pid == 0)
    {
      close(pfd[0]);
      if (dup2(pfd[1], 1) < 0)
	return (at_exit_1(ERR_DUP2));
      if (execve(tmp[0]->command[0], tmp[0]->command, mysh->env) < 0)
	return (at_exit_mysh_err(ERR_EXECVE, mysh));
    }
  else
    {
      close(pfd[1]);
      if (dup2(pfd[0], 0) < 0)
	return (at_exit_1(ERR_DUP2));
      if (execve(tmp[1]->command[0], tmp[1]->command, mysh->env) < 0)
	return (at_exit_mysh_err(ERR_EXECVE, mysh));
    }
  return (0);
}

static void	my_wait(t_mysh *mysh)
{
  int		sig;

  wait(&sig);
  if (WIFSIGNALED(sig))
    err_execve(sig);
  sig == 0 ? mysh->value.last_command = 0 : 0;
}

int		my_spipe(t_mysh *mysh)
{
  int		pfd[2];
  int		pid1;
  int		pid2;
  t_elem	*tmp[2];

  tmp[0] = mysh->commands.head;
  tmp[1] = mysh->commands.tail;
  if ((pid1 = fork()) < 0)
    return (at_exit_1(ERR_FORK));
  else if (pid1 == 0)
    {
      if (pipe(pfd) < 0)
	return (at_exit_1(ERR_PIPE));
      if ((pid2 = fork()) < 0)
	return (at_exit_1(ERR_FORK));
      else
	if (my_spipe2(mysh, pid2, tmp, pfd))
	  return (1);
    }
  else
    my_wait(mysh);
  return (0);
}
