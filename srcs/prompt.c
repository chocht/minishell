/*
** prompt.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:37:35 2016 Pierre Chauchoy
** Last update Tue May 24 12:42:52 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int			prompt(char **env)
{
  char			*s;

  if (!(s = find_env(env, "PWD=")))
    return (1);
  my_printf("%s > ", s);
  return (0);
}
