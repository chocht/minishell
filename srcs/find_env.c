/*
** find_env.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:41:11 2016 Pierre Chauchoy
** Last update Tue May 24 19:43:44 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char			*find_env(char **env, char *s)
{
  int			i;
  int			len;

  len = my_strlen(s);
  i = -1;
  while (env[++i])
    if (my_strncmp(env[i], s, len) == 0 && env[i][len] != EQUAL)
      return (&env[i][len]);
  return (NULL);
}
