/*
** my_pipe.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Jun  3 22:27:52 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:29:27 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int	my_pipe(t_mysh *mysh)
{
  if (add_list(&mysh->commands, mysh->command,
	       mysh->value.entree, mysh->value.sortie))
    return (1);
  mysh->value.index++;
  return (0);
}
