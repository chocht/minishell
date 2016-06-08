/*
** organize_between.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sun Jun  5 18:30:42 2016 Pierre Chauchoy
** Last update Sun Jun  5 23:22:13 2016 Pierre Chauchoy
*/

#include "mysh.h"
#include "my.h"

static int	organize_between2(t_mysh *mysh, int i, char **tmp)
{
  char		*s;

  while (tmp[++i])
    {
      if (!(s = my_strstr("%s %s", mysh->between[0], tmp[i])))
	return (1);
      my_free_str(&mysh->between[0]);
      if (!(mysh->between[0] = my_strdup(s)))
	return (1);
      my_free_str(&s);
    }
  return (0);
}

int		organize_between(t_mysh *mysh)
{
  char		**tmp;
  int		i;

  if (!(tmp =
	my_str_to_wordtab(mysh->between[mysh->value.index_between], " \t")))
    return (1);
  my_free_str(&mysh->between[mysh->value.index_between]);
  i = 0;
  if (!tmp[i])
    {
      my_fprintf(2, "No file after a redirection\n");
      if (!(mysh->between[mysh->value.index_between] = my_strdup("")))
	return (1);
      my_free_wordtab(&tmp);
      return (1);
    }
  if (!(mysh->between[mysh->value.index_between] = my_strdup(tmp[0])))
    return (1);
  if (organize_between2(mysh, i, tmp))
    return (1);
  my_free_wordtab(&tmp);
  return (0);
}
