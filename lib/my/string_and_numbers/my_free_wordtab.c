/*
** my_free_wordtab.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:07 2016 Pierre Chauchoy
** Last update Tue May 17 12:48:07 2016 Pierre Chauchoy
*/

#include <stdlib.h>

void			my_free_wordtab(char **tab)
{
  int			i;

  if (!(tab))
    return ;
  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
