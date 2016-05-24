/*
** my_show_wordtab.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:53 2016 Pierre Chauchoy
** Last update Tue May 17 13:02:04 2016 Pierre Chauchoy
*/

#include <unistd.h>

void		my_show_wordtab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    {
      write(1, tab[i], my_strlen(tab[i]));
      write(1, "\n", 1);
    }
}
