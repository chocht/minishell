/*
** minishell2.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sat Jun  4 15:11:29 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:43:13 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int	go_psf_separator(t_mysh *mysh)
{
  int		i;

  i = -1;
  if (!mysh->separator[mysh->value.index])
    {
      mysh->value.index++;
      return (0);
    }
  while (mysh->sep[++i] &&
	 my_strcmp(mysh->sep[i], mysh->separator[mysh->value.index]));
  if (mysh->psf_sep[i])
    {
      if (mysh->psf_sep[i](mysh))
	return (at_exit_mysh_1(mysh));
    }
  else
    mysh->value.index++;
  return (0);
}

static void	check_if_pipe(t_mysh *mysh)
{
  if (!mysh->separator[mysh->value.index] ||
      my_strcmp(mysh->separator[mysh->value.index], PIPE))
    {
      if (mysh->value.index >= 1 &&
	  mysh->separator[mysh->value.index - 1] != NULL)
	{
	  if (my_strcmp(mysh->separator[mysh->value.index - 1], PIPE) == 0)
	    mysh->value.launch_pipe_prgm = 2;
	}
      else
	mysh->value.launch_pipe_prgm = 0;
    }
  else
    mysh->value.launch_pipe_prgm = 1;
}

static int	launch_pipe_prgm(t_mysh *mysh)
{
  if (mysh->value.launch_pipe_prgm == 2)
    {
      if (add_list(&mysh->commands, mysh->command,
		   mysh->value.entree, mysh->value.sortie))
	return (at_exit_mysh_1(mysh));
      if (program(mysh))
	return (1);
    }
  return (0);
}

int		go_parse_this(t_mysh *mysh, char *s)
{
  int		len;

  if (!(mysh->tokens = my_str_to_wordtab(s, SEPARATOR)))
    return (at_exit_mysh_1(mysh));
  len = my_len_wordtab(mysh->tokens);
  if (!(mysh->separator = my_str_to_wordtab2(s, SEPARATOR)))
    return (at_exit_mysh_1(mysh));
  mysh->value.index = 0;
  init_list(&mysh->commands);
  while (mysh->value.index < len)
    {
      check_if_pipe(mysh);
      if (between_separators(mysh))
	return (1);
      if (go_psf_separator(mysh))
	return (1);
      if (launch_pipe_prgm(mysh))
	return (1);
      mysh->command ? my_free_wordtab(&mysh->command) : 0;
    }
  free_list(&mysh->commands);
  my_free_wordtab(&mysh->tokens);
  my_free_wordtab(&mysh->separator);
  return (0);
}
