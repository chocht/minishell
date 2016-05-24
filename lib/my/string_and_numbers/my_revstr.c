/*
** my_revstr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:46 2016 Pierre Chauchoy
** Last update Tue May 24 11:18:19 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

char		*my_revstr(char *str)
{
  char		*s;
  int		j;
  int		len;

  len = my_strlen(str);
  if (!(s = xmalloc(sizeof(char) * (len + 1))))
    return (NULL);
  s[len] = '\0';
  j = 0;
  while (--len >= 0)
    s[len] = str[j++];
  return (s);
}
