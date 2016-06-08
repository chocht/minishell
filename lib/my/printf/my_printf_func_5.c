/*
** my_printf_func_5.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:12 2016 Pierre Chauchoy
** Last update Thu May 26 18:38:42 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

void		my_show_tab_printf(char **tab, t_printf *printf)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    {
      my_putstr_printf(tab[i], printf);
      my_putchar_printf('\n', printf);
    }
}

void		my_put_nbr_float_printf(double nb, t_printf *printf)
{
  int		i;
  int		l;

  l = 0;
  nb < 0 ? my_putchar_printf(LIB_MINUS, printf) : 0;
  nb < 1 && nb > -1 ? my_putchar_printf(LIB_ZERO, printf) : 0;
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
      my_putchar_printf((int)nb % 10 + 48, printf);
    }
  if (l == 0)
    my_putchar_printf(LIB_DOT, printf);
  while (++i < LIB_FLOAT_PREC)
    {
      nb *= 10;
      my_putchar_printf((int)nb % 10 + 48, printf);
    }
}
