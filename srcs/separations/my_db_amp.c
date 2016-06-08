/*
** my_db_amp.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Jun  3 15:34:56 2016 Pierre Chauchoy
** Last update Fri Jun  3 22:07:36 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int		my_db_amp(t_mysh *mysh)
{
  if (mysh->value.last_command == -1)
    {
      while (mysh->separator[mysh->value.index] &&
	     my_strcmp(mysh->separator[mysh->value.index], DB_AMP) == 0)
	mysh->value.index++;
    }
  mysh->value.index++;
  return (0);
}
