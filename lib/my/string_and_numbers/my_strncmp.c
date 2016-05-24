/*
** my_strncmp.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:50:28 2016 Pierre Chauchoy
** Last update Tue May 17 12:50:28 2016 Pierre Chauchoy
*/

int		my_strncmp(char *s1, char *s2, int n)
{
  while (n-- > 0)
    if (*s1++ != *s2++)
      return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
  return (0);
}
