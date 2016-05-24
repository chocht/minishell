/*
** my_is_in_inttab.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu May 19 13:48:11 2016 Pierre Chauchoy
** Last update Thu May 19 13:48:53 2016 Pierre Chauchoy
*/

int		my_is_in_inttab(int nb, int *tab, int len)
{
  int		i;

  i = -1;
  while (++i < len)
    if (nb == tab[i])
      return (0);
  return (1);
}
