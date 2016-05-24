/*
** my_wordtabcat_string.c for lib in /home/chauch_p/librairie/samples/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:10:14 2016 Pierre Chauchoy
** Last update Tue May 24 11:32:59 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

char			**my_wordtabcat_string(char **tab, char *s)
{
  char			**new;
  int			i;

  i = -1;
  if (!(new = xmalloc(sizeof(char*) * (my_len_wordtab(tab) + 1 + 1))))
    return (NULL);
  while (tab[++i])
    if (!(new[i] = my_strdup(tab[i])))
      return (NULL);
  if (!(new[i] = my_strdup(s)))
    return (NULL);
  new[++i] = NULL;
  return (new);
}
