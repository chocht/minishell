/*
** at_exit_mysh.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:24:49 2016 Pierre Chauchoy
** Last update Tue May 24 19:37:33 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int			at_exit_mysh_1(t_mysh *mysh)
{
  mysh->dir.old ? my_free_str(&mysh->dir.old) : 0;
  mysh->dir.cur ? my_free_str(&mysh->dir.cur) : 0;
  mysh->dir.home ? my_free_str(&mysh->dir.home) : 0;
  mysh->s ? my_free_str(&mysh->s) : 0;
  my_free_wordtab(mysh->separator);
  my_free_wordtab(mysh->command);
  my_free_wordtab(mysh->env);
  my_free_wordtab(mysh->path);
  return (1);
}

int			at_exit_mysh_err(char *msg, t_mysh *mysh)
{
  mysh->dir.old ? my_free_str(&mysh->dir.old) : 0;
  mysh->dir.cur ? my_free_str(&mysh->dir.cur) : 0;
  mysh->dir.home ? my_free_str(&mysh->dir.home) : 0;
  mysh->s ? my_free_str(&mysh->s) : 0;
  my_free_wordtab(mysh->separator);
  my_free_wordtab(mysh->command);
  my_free_wordtab(mysh->env);
  my_free_wordtab(mysh->path);
  my_fprintf(2, "Error -> %s.\n", msg);
  return (1);
}

int			at_exit_mysh_msg(char *msg, t_mysh *mysh)
{
  mysh->dir.old ? my_free_str(&mysh->dir.old) : 0;
  mysh->dir.cur ? my_free_str(&mysh->dir.cur) : 0;
  mysh->dir.home ? my_free_str(&mysh->dir.home) : 0;
  mysh->s ? my_free_str(&mysh->s) : 0;
  my_free_wordtab(mysh->separator);
  my_free_wordtab(mysh->command);
  my_free_wordtab(mysh->env);
  my_free_wordtab(mysh->path);
  my_fprintf(2, "%s\n", msg);
  return (1);
}
