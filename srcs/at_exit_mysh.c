/*
** at_exit_mysh.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:24:49 2016 Pierre Chauchoy
** Last update Sat Jun  4 14:28:51 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

int			at_exit_mysh_1(t_mysh *mysh)
{
  mysh->env ? my_free_wordtab(&mysh->env) : 0;
  mysh->path ? my_free_wordtab(&mysh->path) : 0;
  mysh->command ? my_free_wordtab(&mysh->command) : 0;
  mysh->tokens ? my_free_wordtab(&mysh->tokens) : 0;
  mysh->separator ? my_free_wordtab(&mysh->separator) : 0;
  mysh->redirection ? my_free_wordtab(&mysh->redirection) : 0;
  mysh->between ? my_free_wordtab(&mysh->between) : 0;
  mysh->s ? my_free_str(&mysh->s) : 0;
  mysh->dir.old ? my_free_str(&mysh->dir.old) : 0;
  mysh->dir.cur ? my_free_str(&mysh->dir.cur) : 0;
  mysh->dir.home ? my_free_str(&mysh->dir.home) : 0;
  return (1);
}

int			at_exit_mysh_err(char *msg, t_mysh *mysh)
{
  mysh->env ? my_free_wordtab(&mysh->env) : 0;
  mysh->path ? my_free_wordtab(&mysh->path) : 0;
  mysh->command ? my_free_wordtab(&mysh->command) : 0;
  mysh->tokens ? my_free_wordtab(&mysh->tokens) : 0;
  mysh->separator ? my_free_wordtab(&mysh->separator) : 0;
  mysh->redirection ? my_free_wordtab(&mysh->redirection) : 0;
  mysh->between ? my_free_wordtab(&mysh->between) : 0;
  mysh->s ? my_free_str(&mysh->s) : 0;
  mysh->dir.old ? my_free_str(&mysh->dir.old) : 0;
  mysh->dir.cur ? my_free_str(&mysh->dir.cur) : 0;
  mysh->dir.home ? my_free_str(&mysh->dir.home) : 0;
  my_fprintf(2, "Error -> %s.\n", msg);
  return (1);
}

int			at_exit_mysh_msg(char *msg, t_mysh *mysh)
{
  mysh->env ? my_free_wordtab(&mysh->env) : 0;
  mysh->path ? my_free_wordtab(&mysh->path) : 0;
  mysh->command ? my_free_wordtab(&mysh->command) : 0;
  mysh->tokens ? my_free_wordtab(&mysh->tokens) : 0;
  mysh->separator ? my_free_wordtab(&mysh->separator) : 0;
  mysh->redirection ? my_free_wordtab(&mysh->redirection) : 0;
  mysh->between ? my_free_wordtab(&mysh->between) : 0;
  mysh->s ? my_free_str(&mysh->s) : 0;
  mysh->dir.old ? my_free_str(&mysh->dir.old) : 0;
  mysh->dir.cur ? my_free_str(&mysh->dir.cur) : 0;
  mysh->dir.home ? my_free_str(&mysh->dir.home) : 0;
  my_fprintf(2, "%s\n", msg);
  return (1);
}
