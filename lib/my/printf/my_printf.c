/*
** my_printf.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:52:43 2016 Pierre Chauchoy
** Last update Thu May 26 18:22:17 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

static void	my_display(t_printf *printf)
{
  int		i;

  i = -1;
  printf->p++;
  while (printf->letters[++i] && printf->letters[i] != printf->s[printf->p]);
  if (printf->display[i])
    printf->display[i](printf);
}

char		*my_sprintf(const char *s, ...)
{
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.sprintf = 1;
  if (!(printf.dest = xmalloc(sizeof(char) * 1)))
    return (NULL);
  printf.dest[0] = '\0';
  while (s[++printf.p])
    {
      if (s[printf.p] == LIB_PERCENT && s[printf.p + 1])
	my_display(&printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.dest);
}

int		my_fprintf(int fd, const char *s, ...)
{
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.fd = fd;
  printf.sprintf = 0;
  while (s[++printf.p])
    {
      if (s[printf.p] == LIB_PERCENT && s[printf.p + 1])
	my_display(&printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.len);
}

int		my_printf(const char *s, ...)
{
  t_printf	printf;

  va_start(printf.ap, s);
  fill_printf(s, &printf);
  printf.fd = 1;
  printf.sprintf = 0;
  while (s[++printf.p])
    {
      if (s[printf.p] == LIB_PERCENT && s[printf.p + 1])
	my_display(&printf);
      else
	my_putchar_printf(s[printf.p], &printf);
    }
  va_end(printf.ap);
  return (printf.len);
}
