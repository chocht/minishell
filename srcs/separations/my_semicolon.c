/*
** my_semicolon.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Jun  3 15:36:03 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:49:34 2016 Pierre Chauchoy
*/

#include "mysh.h"

int		my_semicolon(t_mysh *mysh)
{
  mysh->value.index++;
  return (0);
}
