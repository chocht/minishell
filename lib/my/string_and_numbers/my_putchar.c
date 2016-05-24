/*
** my_putchar.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:34 2016 Pierre Chauchoy
** Last update Tue May 17 12:48:34 2016 Pierre Chauchoy
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
