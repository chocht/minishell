/*
** my_put_nbr_float.c for lib in /home/chauch_p/librairie/samples/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu May 26 18:09:38 2016 Pierre Chauchoy
** Last update Thu May 26 18:13:50 2016 Pierre Chauchoy
*/

#include "my.h"

void		my_put_nbr_float(double nb)
{
  int		i;
  int		l;

  l = 0;
  nb < 0 ? my_putchar(LIB_MINUS) : 0;
  nb < 1 && nb > -1 ? my_putchar(LIB_ZERO) : 0;
  nb < 0 ? nb = -nb : 0;
  i = 0;
  nb *= 10;
  while ((nb = nb / 10) >= 1)
    i++;
  if (i == 0 && nb == (int)nb)
    l = 1;
  while (i-- > 0)
    {
      nb = nb * 10;
      my_putchar((int)nb % 10 + 48);
    }
  if (l == 0)
    my_putchar('.');
  while (++i < LIB_FLOAT_PREC)
    {
      nb *= 10;
      my_putchar((int)nb % 10 + 48);
    }
}
