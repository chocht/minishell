/*
** get_next_line.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:53:25 2016 Pierre Chauchoy
** Last update Tue May 24 11:16:31 2016 Pierre Chauchoy
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static char	*my_strcat_read(char *line, char rd)
{
  char		*tmp;
  static int	len = 0;
  int		i;

  if (!(tmp = xmalloc(sizeof(char) * (len + 2))))
    return (NULL);
  i = -1;
  len++;
  while (line[++i])
    tmp[i] = line[i];
  tmp[i++] = rd;
  tmp[i++] = '\0';
  free(line);
  return (tmp);
}

char		*get_next_line(const int fd)
{
  char		rd;
  char		*line;
  static int	len = 1;

  if (!(line = xmalloc(sizeof(char) * 1)))
    return (NULL);
  line[0] = '\0';
  while (1)
    {
      if ((len = read(fd, &rd, 1)) < 0)
	return (NULL);
      if (len == 0 && !line[0])
	{
	  free(line);
	  return (NULL);
	}
      if (len == 0 || rd == BACK_N)
	return (line);
      if (!(line = my_strcat_read(line, rd)))
	return (NULL);
    }
  return (NULL);
}
