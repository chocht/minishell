/*
** my_strstr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:50:35 2016 Pierre Chauchoy
** Last update Thu May 26 18:21:31 2016 Pierre Chauchoy
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char		*my_strcat_word(char *dest, char *add)
{
  char		*tmp;
  int		i;
  int		j;

  if (!(tmp = xmalloc(sizeof(char) * (my_strlen(dest) + my_strlen(add) + 1))))
    return (NULL);
  i = -1;
  while (dest[++i])
    tmp[i] = dest[i];
  free(dest);
  j = -1;
  while (add[++j])
    tmp[i++] = add[j];
  tmp[i] = '\0';
  return (tmp);
}

char		*my_strstr(char *s, ...)
{
  int		i;
  va_list	ap;
  char		*dest;

  i = -1;
  if (!(dest = xmalloc(sizeof(char) * 1)))
    return (NULL);
  dest[0] = '\0';
  va_start(ap, s);
  while (++i < my_strlen(s))
    {
      if (s[i] == LIB_PERCENT)
	{
	  if (s[++i] == 's')
	    if (!(dest = my_strcat_word(dest, va_arg(ap, char*))))
	      return (NULL);
	}
      else
	if (!(dest = my_strcat_char(dest, s[i])))
	  return (NULL);
    }
  va_end(ap);
  return (dest);
}
