/*
** my_printf_func_2.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:52:58 2016 Pierre Chauchoy
** Last update Tue May 17 13:30:33 2016 Pierre Chauchoy
*/

#include "my.h"

void		printf_uhex(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned int), 16, printf);
}

void		printf_char(t_printf *printf)
{
  my_putchar_printf(va_arg(printf->ap, int), printf);
}

void		printf_str(t_printf *printf)
{
  my_putstr_printf(va_arg(printf->ap, char*), printf);
}

void		printf_str_np(t_printf *printf)
{
  my_putstr_np_printf(va_arg(printf->ap, char*), printf);
}

void		printf_ptr(t_printf *printf)
{
  my_putstr_printf("0x", printf);
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned long), 16, printf);
}
