/*
** init_mysh.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:27:48 2016 Pierre Chauchoy
** Last update Tue May 24 19:37:53 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void			fill_builtins(t_mysh *mysh)
{
  mysh->bi[0] = CD;
  mysh->bi[1] = ENV;
  mysh->bi[2] = SETENV;
  mysh->bi[3] = UNSETENV;
  mysh->bi[4] = EXIT;
  mysh->bi[5] = ECHO;
  mysh->bi[6] = NULL;
  mysh->prgm[0] = &my_cd;
  mysh->prgm[1] = &my_env;
  mysh->prgm[2] = &my_setenv;
  mysh->prgm[3] = &my_unsetenv;
  mysh->prgm[4] = &my_exit;
  mysh->prgm[5] = NULL;/* &my_echo; */
  mysh->prgm[6] = NULL;
}

int			init_mysh(t_mysh *mysh, char **env)
{
  fill_builtins(mysh);
  mysh->dir.old = NULL;
  mysh->dir.cur = NULL;
  mysh->dir.home = NULL;
  mysh->env = NULL;
  mysh->command = NULL;
  mysh->separator = NULL;
  mysh->path = NULL;
  mysh->s = NULL;
  if (!(mysh->env = my_wordtab_dup(env)))
    return (1);
  if (reload_path(mysh))
    return (1);
  if (!(mysh->dir.home = my_strdup(find_env(mysh->env, "HOME="))))
    if (!(mysh->dir.home = my_strdup(".")))
      return (1);
  mysh->dir.cur = my_strdup(find_env(mysh->env, "PWD="));
  return (0);
}
