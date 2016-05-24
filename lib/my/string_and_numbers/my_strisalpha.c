/*
** my_strisalpha.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:19 2016 Pierre Chauchoy
** Last update Tue May 17 13:02:41 2016 Pierre Chauchoy
*/

int		my_str_isalpha(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] > 122 || str[i] < 65 || (str[i] < 97 && str[i] > 90))
      return (0);
  return (1);
}
