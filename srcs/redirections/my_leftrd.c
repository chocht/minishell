/*
** my_leftrd.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Jun  3 22:27:49 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:37:30 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int	my_leftrd(t_mysh *mysh)
{
  if (!(mysh->between[mysh->value.index_between]))
    return (at_exit_1("Expected file line after <"));
  mysh->value.entree =
    open_file_read(mysh->between[mysh->value.index_between]);
  return (0);
}
