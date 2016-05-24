/*
** minishell.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:02:28 2016 Pierre Chauchoy
** Last update Tue May 24 19:36:46 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int		go_parse_this(t_mysh *mysh, char *s)
{
  int		i;

  if (!(mysh->separator = my_str_to_wordtab(s, POINT_COMA)))
    return (at_exit_mysh_1(mysh));
  i = -1;
  while (mysh->separator[++i])
    {
      if (!(mysh->command = my_str_to_wordtab(mysh->separator[i], SEPARATION)))
	return (at_exit_mysh_1(mysh));
      if (program(mysh))
	return (1);
      my_free_wordtab(mysh->command);
      mysh->command = NULL;
    }
  my_free_wordtab(mysh->separator);
  mysh->separator = NULL;
  return (0);
}

int		loop_mysh(t_mysh *mysh)
{
  while (42)
    {
      if (prompt(mysh->env))
	return (at_exit_1("no pwd"));
      if (!(mysh->s = get_next_line(0)))
	return (at_exit_mysh_msg(EXIT, mysh));
      if (go_parse_this(mysh, mysh->s))
	return (1);
      if (mysh->s)
	my_free_str(&mysh->s);
    }
  return (0);
}

int		minishell(char **env)
{
  t_mysh	mysh;

  if (init_mysh(&mysh, env))
    return (1);
  if (loop_mysh(&mysh))
    return (1);
  at_exit_mysh_1(&mysh);
  return (0);
}
