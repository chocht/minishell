/*
** my_is_in_str.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu May 19 13:42:21 2016 Pierre Chauchoy
** Last update Thu May 19 13:43:09 2016 Pierre Chauchoy
*/

int		my_is_in_str(char c, char *s)
{
  int		i;

  i = -1;
  while (s[++i])
    if (c == s[i])
      return (0);
  return (1);
}
