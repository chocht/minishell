/*
** my_printf_func_3.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:04 2016 Pierre Chauchoy
** Last update Tue May 17 13:30:37 2016 Pierre Chauchoy
*/

#include "my.h"

void		printf_bin(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, int), 2, printf);
}

void		printf_tab(t_printf *printf)
{
  my_show_tab_printf(va_arg(printf->ap, char**), printf);
}
