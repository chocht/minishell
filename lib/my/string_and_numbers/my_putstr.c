/*
** my_putstr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:43 2016 Pierre Chauchoy
** Last update Tue May 17 12:48:43 2016 Pierre Chauchoy
*/

#include <unistd.h>

void		my_putstr(char *s)
{
  int		i;

  i = -1;
  while (s[++i])
    my_putchar(s[i]);
}
