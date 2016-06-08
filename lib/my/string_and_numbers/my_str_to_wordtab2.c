/*
** my_str_to_wordtab2.c for lib in /home/chauch_p/librairie/samples/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu Jun  2 11:50:17 2016 Pierre Chauchoy
** Last update Thu Jun  2 11:50:17 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "my.h"

static int	size_height(char *s, char *letters)
{
  int		i;
  int		height;

  i = 0;
  height = 0;
  while (s[i] && my_is_in_str(s[i], letters) == 1)
    i = i + 1;
  while (s[i])
    {
      while (s[i] && my_is_in_str(s[i], letters) == 0)
	i = i + 1;
      height++;
      while (s[i] && my_is_in_str(s[i], letters) == 1)
	i = i + 1;
    }
  return (height);
}

static int	size_width(char *s, int *i, char *letters)
{
  int		width;
  int		x;

  width = 0;
  while (s[*i] && my_is_in_str(s[*i], letters) == 1)
    *i = *i + 1;
  x = *i - 1;
  while (s[++x] && my_is_in_str(s[x], letters) == 0)
    width++;
  return (width);
}

static int	fill_lines_of_tab(char **tab, char *s, int height,
				  char *letters)
{
  int		x;
  int		y;
  int		i;
  int		width;

  y = -1;
  i = 0;
  while (++y < height)
    {
      x = -1;
      width = size_width(s, &i, letters);
      if (!(tab[y] = xmalloc(sizeof(char) * (width + 1))))
	return (1);
      while (++x < width)
	tab[y][x] = s[i++];
      tab[y][x] = '\0';
    }
  tab[y] = NULL;
  return (0);
}

char		**my_str_to_wordtab2(char *s, char *letters)
{
  char		**tab;
  int		height;

  height = size_height(s, letters);
  if (!(tab = xmalloc(sizeof(char*) * (height + 1))))
    return (NULL);
  if (fill_lines_of_tab(tab, s, height, letters))
    return (NULL);
  return (tab);
}
