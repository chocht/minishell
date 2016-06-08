/*
** prompt.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:37:35 2016 Pierre Chauchoy
** Last update Thu Jun  2 10:18:12 2016 Pierre Chauchoy
*/

#include <unistd.h>
#include "mysh.h"
#include "my.h"

int		prompt()
{
  char		s[LEN_GETCWD];

  if (!(getcwd(s, LEN_GETCWD)))
    return (1);
  my_printf("%s > ", s);
  return (0);
}
