/*
** my_strcmp_overflow.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:10 2016 Pierre Chauchoy
** Last update Tue May 17 13:02:28 2016 Pierre Chauchoy
*/

int		my_strcmp_overflow(char *s1, char *big)
{
  int		i;

  i = -1;
  if (my_strlen(big) < my_strlen(s1))
    return (1);
  if (my_strlen(big) > my_strlen(s1))
    return (0);
  while (big[++i])
    if (s1[i] > big[i])
      return (1);
  return (0);
}
