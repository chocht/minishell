/*
** my_env.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:40:06 2016 Pierre Chauchoy
** Last update Tue May 24 19:40:18 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int			my_env(t_mysh *mysh)
{
  my_show_wordtab(mysh->env);
  return (0);
}
