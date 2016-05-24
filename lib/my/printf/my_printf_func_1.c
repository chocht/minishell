/*
** my_printf_func_1.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:01 2016 Pierre Chauchoy
** Last update Tue May 17 13:30:29 2016 Pierre Chauchoy
*/

#include "my.h"

void		fill_display(t_disp_printf *display)
{
  display[0] = &printf_dec;
  display[1] = &printf_dec;
  display[2] = &printf_oct;
  display[3] = &printf_uint;
  display[4] = &printf_uhex;
  display[5] = &printf_uhex;
  display[6] = &printf_char;
  display[7] = &printf_str;
  display[8] = &printf_str_np;
  display[9] = &printf_ptr;
  display[10] = &printf_bin;
  display[11] = &printf_tab;
}

void		fill_printf(const char *s, t_printf *printf)
{
  printf->letters = PRINTF_LETTERS;
  printf->p = -1;
  printf->s = s;
  printf->len = 0;
}

void		printf_dec(t_printf *printf)
{
  my_put_nbr_printf(va_arg(printf->ap, int), 10, printf);
}

void		printf_oct(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned int), 8, printf);
}

void		printf_uint(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned int), 10, printf);
}
