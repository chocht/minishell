/*
** my_mpipe.c for 42sh in /home/andrea_j/rendu/Shell_Programming/PSU_2015_42sh
** 
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
** 
** Started on  Sun Jun  5 23:27:48 2016 Julien Andreani
** Last update Sun Jun  5 23:47:28 2016 Julien Andreani
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int	in_parent(t_mysh *mysh, int *pfd, int *fd_in, t_elem *tmp)
{
  int		sig;

  close(pfd[1]);
  wait(&sig);
  if (WIFSIGNALED(sig))
    err_execve(sig);
  sig == 0 ? mysh->value.last_command = 0 : 0;
  *fd_in = pfd[0];
  tmp = tmp->next;
  return (0);
}

static int	in_child(t_mysh *mysh, int *pfd, int *fd_in, t_elem *tmp)
{
  close(pfd[0]);
  if (dup2(*fd_in, 0) < 0)
    return (at_exit_1(ERR_DUP2));
  if (tmp->next)
    if (dup2(pfd[1], 1) < 0)
      return (at_exit_1(ERR_DUP2));
  if (execve(tmp->command[0], tmp->command, mysh->env) < 0)
    return (at_exit_mysh_err(ERR_EXECVE, mysh));
  return (0);
}

int		my_mpipe(t_mysh *mysh)
{
  pid_t		pid;
  int		pfd[2];
  int		fd_in;
  t_elem	*tmp;

  tmp = mysh->commands.head;
  fd_in = 0;
  if (tmp->entree != -1)
    fd_in = tmp->entree;
  while (tmp)
    {
      if (pipe(pfd) < 0)
	return (at_exit_1(ERR_PIPE));
      if ((pid = fork()) < 0)
	return (at_exit_1(ERR_FORK));
      else if (pid == 0)
	{
	  if (in_child(mysh, pfd, &fd_in, tmp))
	    return (1);
	}
      else
	if (in_parent(mysh, pfd, &fd_in, tmp))
	  return (1);
    }
  return (0);
}
