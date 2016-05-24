/*
** my_printf_func_4.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:08 2016 Pierre Chauchoy
** Last update Tue May 17 13:30:41 2016 Pierre Chauchoy
*/

#include <unistd.h>
#include "my.h"

void		my_putchar_printf(char c, t_printf *printf)
{
  if (printf->sprintf == 0)
    write(printf->fd, &c, 1);
  else
    if (!(printf->dest = my_strcat_char(printf->dest, c)))
      return ;
  printf->len++;
}

void		my_putstr_printf(char *s, t_printf *printf)
{
  int		i;

  i = -1;
  while (s[++i] != '\0')
    my_putchar_printf(s[i], printf);
}

void		my_putstr_np_printf(char *s, t_printf *printf)
{
  int		i;

  i = -1;
  while (s[++i] != '\0')
    {
      if (s[i] >= 32 && s[i] < 127)
	my_putchar_printf(s[i], printf);
      else
	{
	  my_putchar_printf('\\', printf);
	  if (s[i] < 64)
	    my_putchar_printf('0', printf);
	  if (s[i] < 8)
	    my_putchar_printf('0', printf);
	  my_put_nbr_printf(s[i], 8, printf);
	}
    }
}

int		my_put_unsigned_nbr_printf(unsigned int nb,
					   unsigned int base,
					   t_printf *printf)
{
  if (nb >= base)
    my_put_unsigned_nbr_printf(nb / base, base, printf);
  if (nb % base > 9)
    my_putchar_printf(nb % base + 66, printf);
  else
    my_putchar_printf(nb % base + 48, printf);
  return (0);
}

int		my_put_nbr_printf(int nb, int base, t_printf *printf)
{
  if (base < 1)
    return (-1);
  if (nb < 0)
    {
      my_putchar_printf('-', printf);
      nb = -nb;
    }
  if (nb >= base)
    my_put_nbr_printf(nb / base, base, printf);
  if (nb % base > 9)
    my_putchar_printf(nb % base + 66, printf);
  else
    my_putchar_printf(nb % base + 48, printf);
  return (0);
}
