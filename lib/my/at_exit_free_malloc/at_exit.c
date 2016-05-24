/*
** at_exit.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 17:03:40 2016 Pierre Chauchoy
** Last update Tue May 17 17:07:36 2016 Pierre Chauchoy
*/

#include <stdlib.h>

int		at_exit_m1(char *msg)
{
  my_fprintf(2, "Error -> %s.\n", msg);
  return (-1);
}

int		at_exit_1(char *msg)
{
  my_fprintf(2, "Error -> %s.\n", msg);
  return (1);
}

void		*at_exit_null(char *msg)
{
  my_fprintf(2, "Error -> %s.\n", msg);
  return (NULL);
}

int		at_exit_free_1(char *msg, char *s)
{
  if (s)
    my_free_str(&s);
  my_fprintf(2, "Error -> %s.\n", msg);
  return (1);
}

void		*at_exit_free_null(char *msg, char *s)
{
  if (s)
    my_free_str(&s);
  my_fprintf(2, "Error -> %s.\n", msg);
  return (NULL);
}
