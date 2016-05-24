/*
** my_put_nbr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:40 2016 Pierre Chauchoy
** Last update Tue May 17 13:31:56 2016 Pierre Chauchoy
*/

#include "my.h"

void		my_put_nbr(int nb)
{
  int		l;

  l = 0;
  if (nb < 0)
    {
      my_putchar(MINUS);
      if (nb == -2147483648)
	{
	  nb = -2147483647;
	  l = 1;
	}
      nb = -nb;
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48 + l);
}
