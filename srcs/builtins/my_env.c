/*
** my_env.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:40:06 2016 Pierre Chauchoy
** Last update Fri Jun  3 15:07:25 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int			my_env(t_mysh *mysh)
{
  my_show_wordtab(mysh->env);
  mysh->value.last_command = 0;
  return (0);
}
