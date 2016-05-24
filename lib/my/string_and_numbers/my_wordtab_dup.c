/*
** my_wordtab_dup.c for lib in /home/chauch_p/librairie/samples/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:08:27 2016 Pierre Chauchoy
** Last update Tue May 24 11:32:57 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

char			**my_wordtab_dup(char **tab)
{
  char			**new;
  int			i;

  i = -1;
  if (!(new = xmalloc(sizeof(char*) * (my_len_wordtab(tab) + 1 + 1))))
    return (NULL);
  while (tab[++i])
    if (!(new[i] = my_strdup(tab[i])))
      return (NULL);
  new[i] = NULL;
  return (new);
}
