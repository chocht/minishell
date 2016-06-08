/*
** my_str_isnum.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:25 2016 Pierre Chauchoy
** Last update Thu May 26 18:19:52 2016 Pierre Chauchoy
*/

#include "my.h"

int		my_str_isnum(char *s)
{
  int		i;

  i = 0;
  if (s[i] == LIB_MINUS)
    i = i + 1;
  if (!s[i])
    return (1);
  while (s[i])
    {
      if (s[i] > 57 || s[i] < 48)
	return (1);
      i = i + 1;
    }
  return (0);
}
