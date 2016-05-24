/*
** my_str_isnum_pos.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:28 2016 Pierre Chauchoy
** Last update Tue May 17 13:03:16 2016 Pierre Chauchoy
*/

int		my_str_isnum_pos(char *s)
{
  int		i;

  i = 0;
  if (!s[i])
    return (1);
  while (s[i])
    {
      if (s[i] > 57 || s[i] < 48)
	return (1);
      i = i + 1;
    }
  return (0);
}
