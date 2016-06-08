/*
** exec_prgm.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:43:08 2016 Pierre Chauchoy
** Last update Sun Jun  5 23:38:59 2016 Pierre Chauchoy
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int		check_fd(t_mysh *mysh)
{
  if (mysh->value.sortie != -1)
    {
      if (dup2(mysh->value.sortie, 1) == -1)
	return (at_exit_1(ERR_DUP2));
    }
  if (mysh->value.entree != -1)
    {
      if (dup2(mysh->value.entree, 0) == -1)
	return (at_exit_1(ERR_DUP2));
    }
  return (0);
}

static void		default_fd(t_mysh *mysh)
{
  if (mysh->value.entree != -1)
    {
      close(mysh->value.entree);
      mysh->value.entree = -1;
    }
  if (mysh->value.sortie != -1)
    {
      close(mysh->value.sortie);
      mysh->value.sortie = -1;
    }
}

void			err_execve(int sig)
{
  if (WTERMSIG(sig) == SIGSEGV)
    my_printf("%s\n", ERR_SEGFAULT);
  else if (WTERMSIG(sig) == SIGFPE)
    my_printf("%s\n", ERR_FLOATING);
  else if (WTERMSIG(sig) == SIGABRT)
    my_printf("%s\n", ERR_ABORT);
}

int			exec_prgm(t_mysh *mysh, char *s)
{
  pid_t			pid;
  int			sig;

  if (mysh->commands.len == 0)
    {
      if ((pid = fork()) == -1)
	return (at_exit_mysh_err(ERR_FORK, mysh));
      if (pid == 0)
	{
	  if (check_fd(mysh))
	    return (at_exit_mysh_1(mysh));
	  if (execve(s, mysh->command, mysh->env) == -1)
	    return (at_exit_mysh_err(ERR_EXECVE, mysh));
	}
      else
	wait(&sig);
      default_fd(mysh);
      if (WIFSIGNALED(sig))
	err_execve(sig);
      sig == 0 ? mysh->value.last_command = 0 : 0;
    }
  return (0);
}
