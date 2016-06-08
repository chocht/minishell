/*
** minishell.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:02:28 2016 Pierre Chauchoy
** Last update Tue Jun  7 10:59:47 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

/*
** JOLI PROMPT:
** if (prompt())
**   return (at_exit_mysh_err(ERR_GETCWD, mysh));
*/

static int	loop_mysh(t_mysh *mysh)
{
  while (42)
    {
      if (prompt())
	return (at_exit_mysh_err(ERR_GETCWD, mysh));
      if (!(mysh->s = get_next_line(0)))
	{
	  at_exit_mysh_1(mysh);
	  return (mysh->value.last_command);
	}
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
