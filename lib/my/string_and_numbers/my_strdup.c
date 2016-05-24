/*
** my_strdup.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:16 2016 Pierre Chauchoy
** Last update Tue May 24 11:18:33 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(char *s)
{
  int		i;
  char		*new;

  if (!(s))
    return (NULL);
  if (!(new = xmalloc(sizeof(char) * ((my_strlen(s)) + 1))))
    return (NULL);
  i = -1;
  while (s[++i])
    new[i] = s[i];
  new[i] = '\0';
  return (new);
}
