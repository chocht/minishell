/*
** at_exit_perso.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:12:20 2016 Pierre Chauchoy
** Last update Tue May 24 19:26:18 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

int			at_exit_free(char **s)
{
  my_free_str(s);
  return (1);
}

int			at_exit_free_wt(char ***s)
{
  int			i;

  i = -1;
  while (*s && (*s)[++i])
    my_free_str(&(*s)[i]);
  return (1);
}
