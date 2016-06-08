/*
** main.c for minishell in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:01:55 2016 Pierre Chauchoy
** Last update Sat Jun  4 17:40:56 2016 Pierre Chauchoy
*/

#include <signal.h>
#include "mysh.h"
#include "my.h"

void		sig(int sig)
{
}

int		main(int argc, char **argv, char **env)
{
  if (!env)
    return (at_exit_1(ERR_ENV));
  if (signal(SIGINT, sig) == SIG_ERR)
    return (at_exit_1(ERR_SIG));
  if (minishell(env))
    return (1);
  return (0);
}
