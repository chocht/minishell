/*
** reload_path.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:40:35 2016 Pierre Chauchoy
** Last update Sat Jun  4 17:43:26 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int			reload_path(t_mysh *mysh)
{
  char			*path;

  my_free_wordtab(&mysh->path);
  if (!(path = find_env(mysh->env, "PATH=")))
    return (0);
  if (!(mysh->path = my_str_to_wordtab(path, SEP_PATH)))
    return (at_exit_mysh_1(mysh));
  return (0);
}
