/*
** my_unsetenv.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 19:25:17 2016 Pierre Chauchoy
** Last update Fri Jun  3 15:09:00 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static char		**remove_env(char **env_to_copy, char *s)
{
  char			**env;
  int			len;
  int			i;
  int			j;

  env = NULL;
  i = -1;
  len = my_strlen(s);
  while (env_to_copy[++i] &&
	 (my_strncmp(env_to_copy[i], s, len) == 0 ?
	  (env_to_copy[i][len] == EQUAL ? 0 : 1) : 1));
  if (!(env_to_copy[i]))
    return (env_to_copy);
  if (!(env = malloc(sizeof(char*) * (my_len_wordtab(env_to_copy)))))
    return (NULL);
  i = -1;
  j = 0;
  while (env_to_copy[++i])
    if ((my_strncmp(env_to_copy[i], s, len) == 0 ?
	 (env_to_copy[i][len] == EQUAL ? 0 : 1) : 1))
      if (!(env[j++] = my_strdup(env_to_copy[i])))
	return (NULL);
  env[j] = NULL;
  my_free_wordtab(&env_to_copy);
  return (env);
}

int			my_unsetenv(t_mysh *mysh)
{
  int			i;

  if (my_len_wordtab(mysh->command) < 2)
    {
      my_fprintf(2, "%s: %s.\n", UNSETENV, ERR_FEWARGS);
      return (0);
    }
  i = 0;
  while (mysh->command[++i])
    {
      if (!(mysh->env = remove_env(mysh->env, mysh->command[i])))
	return (1);
      if (my_strcmp(mysh->command[i], SHPATH) == 0)
	if (reload_path(mysh))
	  return (1);
    }
  mysh->value.last_command = 0;
  return (0);
}
