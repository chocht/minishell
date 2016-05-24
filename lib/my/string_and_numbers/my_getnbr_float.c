/*
** my_getnbr_float.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:17 2016 Pierre Chauchoy
** Last update Tue May 17 13:31:40 2016 Pierre Chauchoy
*/

#include "my.h"

void		my_getnbr_f_dec(char *s, int i, double *nb)
{
  double	j;

  j = 10;
  while (s[i])
    {
      *nb = *nb + (s[i] - 48) / j;
      i++;
      j *= 10;
    }
}

double		my_getnbr_f(char *s)
{
  double	nb;
  int		i;

  nb = 0;
  i = 0;
  if (s[0] == MINUS)
    i++;
  while (s[i] && s[i] != DOT)
    {
      nb = nb * 10 + (s[i] - 48);
      i++;
    }
  if (s[i] == DOT)
    my_getnbr_f_dec(s, ++i, &nb);
  if (s[0] == MINUS)
    return (-nb);
  return (nb);
}
