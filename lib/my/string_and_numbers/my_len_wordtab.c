/*
** my_len_wordtab.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:27 2016 Pierre Chauchoy
** Last update Tue May 17 13:01:34 2016 Pierre Chauchoy
*/

int		my_len_wordtab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}
