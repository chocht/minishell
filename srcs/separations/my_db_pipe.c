/*
** my_db_pipe.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Jun  3 15:35:42 2016 Pierre Chauchoy
** Last update Fri Jun  3 16:38:00 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int		my_db_pipe(t_mysh *mysh)
{
  if (mysh->value.last_command == 0)
    while (mysh->separator[mysh->value.index] &&
	   my_strcmp(mysh->separator[mysh->value.index], DB_PIPE) == 0)
      mysh->value.index++;
  mysh->value.index++;
  return (0);
}
