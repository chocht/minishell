/*
** my_free.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 17:11:54 2016 Pierre Chauchoy
** Last update Tue May 17 17:13:27 2016 Pierre Chauchoy
*/

#include <stdlib.h>

void		my_free_str(char **s)
{
  if (*s)
    free(*s);
  *s = NULL;
}
