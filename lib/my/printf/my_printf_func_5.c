/*
** my_printf_func_5.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:12 2016 Pierre Chauchoy
** Last update Tue May 17 13:30:45 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

void		my_show_tab_printf(char **tab, t_printf *printf)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    {
      my_putstr_printf(tab[i], printf);
      my_putchar_printf('\n', printf);
    }
}
