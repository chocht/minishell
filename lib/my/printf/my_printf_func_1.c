/*
** my_printf_func_1.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:01 2016 Pierre Chauchoy
** Last update Thu May 26 18:38:35 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

void		fill_printf(const char *s, t_printf *printf)
{
  printf->letters = PRINTF_LETTERS;
  printf->p = -1;
  printf->s = s;
  printf->len = 0;
  printf->display[0] = &printf_dec;
  printf->display[1] = &printf_dec;
  printf->display[2] = &printf_oct;
  printf->display[3] = &printf_uint;
  printf->display[4] = &printf_uhex;
  printf->display[5] = &printf_uhex;
  printf->display[6] = &printf_char;
  printf->display[7] = &printf_str;
  printf->display[8] = &printf_str_np;
  printf->display[9] = &printf_ptr;
  printf->display[10] = &printf_bin;
  printf->display[11] = &printf_tab;
  printf->display[12] = &printf_float;
  printf->display[13] = NULL;
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

void		printf_uhex(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, unsigned int), 16, printf);
}
