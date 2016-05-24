/*
** my_strcat_char.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:03 2016 Pierre Chauchoy
** Last update Tue May 24 11:18:24 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

char		*my_strcat_char(char *s, char c)
{
  char		*tmp;
  int		i;

  if (!(tmp = xmalloc(sizeof(char) * (my_strlen(s) + 1 + 1))))
    return (NULL);
  i = -1;
  while (s[++i])
    tmp[i] = s[i];
  free(s);
  tmp[i++] = c;
  tmp[i] = '\0';
  return (tmp);
}
