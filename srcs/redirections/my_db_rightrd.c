/*
** my_db_rightrd.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Jun  3 22:27:45 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:37:15 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int	my_db_rightrd(t_mysh *mysh)
{
  if (!(mysh->between[mysh->value.index_between]))
    return (at_exit_1("Expected file line after >>"));
  mysh->value.sortie =
    open_file_concat(mysh->between[mysh->value.index_between]);
  return (0);
}
