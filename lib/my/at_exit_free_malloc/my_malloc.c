/*
** my_malloc.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 17:13:50 2016 Pierre Chauchoy
** Last update Sun May 22 13:52:49 2016 Pierre Chauchoy
*/

#include <stdlib.h>

void			*xmalloc(int sizeof_alloc)
{
  void			*a;

  if ((a = malloc(sizeof_alloc)) == NULL)
    {
      my_fprintf(2, "Malloc failed.\n");
      return (NULL);
    }
  return (a);
}
