/*
** my_exit.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:32:03 2016 Pierre Chauchoy
** Last update Tue May 24 19:34:45 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int			my_exit(t_mysh *mysh)
{
  int			len;
  int			i;

  if ((len = my_len_wordtab(mysh->command)) > 2)
    my_fprintf(2, "%s: %s.\n", EXIT, ERR_SYNTAX);
  else if (len == 2 && my_str_isnum(mysh->command[1]))
    my_fprintf(2, "%s: %s.\n", EXIT, ERR_SYNTAX);
  else
    {
      if (len == 2)
	i = my_getnbr(mysh->command[1]);
      else
	i = 0;
      at_exit_mysh_msg(EXIT, mysh);
      exit(i);
    }
  return (0);
}
