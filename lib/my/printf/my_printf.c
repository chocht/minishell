/*
** my_printf.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:52:43 2016 Pierre Chauchoy
** Last update Tue May 24 11:16:42 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

void		my_display(t_disp_printf *display, t_printf *printf)
{
  int		c;

  c = -1;
  printf->p++;
  while (printf->letters[++c] && printf->letters[c] != printf->s[printf->p]);
  if (printf->letters[c])
    if (display[c] != NULL)
      display[c](printf);
}

char		*my_sprintf(const char *s, ...)
{
  t_disp_printf	display[PRINTF_NB_LET];
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.sprintf = 1;
  if (!(printf.dest = xmalloc(sizeof(char) * 1)))
    return (NULL);
  printf.dest[0] = '\0';
  fill_display(display);
  while (s[++printf.p])
    {
      if (s[printf.p] == PERCENT && s[printf.p + 1])
	my_display(display, &printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.dest);
}

int		my_fprintf(int fd, const char *s, ...)
{
  t_disp_printf	display[PRINTF_NB_LET];
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.fd = fd;
  printf.sprintf = 0;
  fill_display(display);
  while (s[++printf.p])
    {
      if (s[printf.p] == PERCENT && s[printf.p + 1])
	my_display(display, &printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.len);
}

int		my_printf(const char *s, ...)
{
  t_disp_printf	display[PRINTF_NB_LET];
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.fd = 1;
  printf.sprintf = 0;
  fill_display(display);
  while (s[++printf.p])
    {
      if (s[printf.p] == PERCENT && s[printf.p + 1])
	my_display(display, &printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.len);
}
