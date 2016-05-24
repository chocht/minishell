/*
** my_strcpy.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:49:13 2016 Pierre Chauchoy
** Last update Tue May 17 13:02:33 2016 Pierre Chauchoy
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  return (dest);
}
