/*
** my_is_in_wordtab.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu May 19 13:46:49 2016 Pierre Chauchoy
** Last update Thu May 19 13:47:35 2016 Pierre Chauchoy
*/

int		my_is_in_wordtab(char *s, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    if (my_strcmp(s, tab[i]) == 0)
      return (0);
  return (1);
}
