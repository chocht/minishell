/*
** minishell3.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sun Jun  5 22:31:18 2016 Pierre Chauchoy
** Last update Sun Jun  5 22:31:52 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

static int	go_psf_redirection(t_mysh *mysh)
{
  int		i;
  int		j;

  i = -1;
  while (mysh->redirection[++i])
    {
      j = -1;
      while (mysh->red[++j] && my_strcmp(mysh->red[j], mysh->redirection[i]));
      if (mysh->psf_red[j])
	{
	  mysh->value.index_between++;
	  if (!mysh->between[mysh->value.index_between])
	    return (1);
	  if (organize_between(mysh))
	    return (1);
	  if (mysh->psf_red[j](mysh))
	    return (1);
	}
      else
	return (at_exit_1(mysh->redirection[i]));
    }
  return (0);
}

int		between_separators(t_mysh *mysh)
{
  if (!(mysh->between =
	my_str_to_wordtab(mysh->tokens[mysh->value.index], SEP_RED)))
    return (at_exit_mysh_1(mysh));
  if (!(mysh->redirection =
	my_str_to_wordtab2(mysh->tokens[mysh->value.index], SEP_RED)))
    return (at_exit_mysh_1(mysh));
  mysh->value.index_between = 0;
  mysh->value.last_command = -1;
  mysh->value.entree = -1;
  mysh->value.sortie = -1;
  if (go_psf_redirection(mysh))
    {
      my_free_wordtab(&mysh->redirection);
      my_free_wordtab(&mysh->between);
      return (0);
    }
  if (!(mysh->command =
	my_str_to_wordtab(mysh->between[0], SEP_CMD)))
    return (at_exit_mysh_1(mysh));
  if (mysh->value.launch_pipe_prgm == 0)
    if (program(mysh))
      return (1);
  my_free_wordtab(&mysh->between);
  my_free_wordtab(&mysh->redirection);
  return (0);
}
