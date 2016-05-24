/*
** my_getnbr_base.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:10 2016 Pierre Chauchoy
** Last update Tue May 17 13:31:32 2016 Pierre Chauchoy
*/

#include "my.h"

int		pos_in_base(char *s, char c)
{
  int		i;

  i = -1;
  while (s[++i] && s[i] != c);
  if (!(s[i]))
    return (-1);
  return (i);
}

int		my_getnbr_base(char *str, char *base)
{
  int		len;
  int		nb;
  int		i;
  int		dec;
  int		pos;

  len = my_strlen(base);
  nb = 0;
  i = my_strlen(str);
  dec = 1;
  while (--i >= 0)
    {
      if (str[i] == MINUS)
	return (-nb);
      if ((pos = pos_in_base(base, str[i])) == -1)
	return (-1);
      nb += pos * dec;
      dec *= len;
    }
  return (nb);
}
