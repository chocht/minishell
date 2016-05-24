/*
** my_strlen.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:50:04 2016 Pierre Chauchoy
** Last update Tue May 17 13:03:27 2016 Pierre Chauchoy
*/

int		my_strlen(char *s)
{
  int		i;

  i = -1;
  while (s[++i]);
  return (i);
}
