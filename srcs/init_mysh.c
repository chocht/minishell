/*
** init_mysh.c for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:27:48 2016 Pierre Chauchoy
** Last update Sun Jun  5 19:32:33 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"
#include "my.h"

static void		fill_builtins(t_mysh *mysh)
{
  mysh->bi[0] = CD;
  mysh->bi[1] = ENV;
  mysh->bi[2] = SETENV;
  mysh->bi[3] = UNSETENV;
  mysh->bi[4] = EXIT;
  mysh->bi[5] = ECHO;
  mysh->bi[6] = NULL;
  mysh->prgm[0] = &my_cd;
  mysh->prgm[1] = &my_env;
  mysh->prgm[2] = &my_setenv;
  mysh->prgm[3] = &my_unsetenv;
  mysh->prgm[4] = &my_exit;
  mysh->prgm[5] = &my_echo;
  mysh->prgm[6] = NULL;
}

static void		fill_separators(t_mysh *mysh)
{
  mysh->sep[0] = SEMICOLON;
  mysh->sep[1] = DB_AMP;
  mysh->sep[2] = DB_PIPE;
  mysh->sep[3] = PIPE;
  mysh->sep[4] = NULL;
  mysh->psf_sep[0] = &my_semicolon;
  mysh->psf_sep[1] = &my_db_amp;
  mysh->psf_sep[2] = &my_db_pipe;
  mysh->psf_sep[3] = &my_pipe;
  mysh->psf_sep[4] = NULL;
}

static void		fill_redirections(t_mysh *mysh)
{
  mysh->red[0] = LEFTRD;
  mysh->red[1] = DB_LEFTRD;
  mysh->red[2] = RIGHTRD;
  mysh->red[3] = DB_RIGHTRD;
  mysh->red[4] = NULL;
  mysh->psf_red[0] = &my_leftrd;
  mysh->psf_red[1] = &my_db_leftrd;
  mysh->psf_red[2] = &my_rightrd;
  mysh->psf_red[3] = &my_db_rightrd;
  mysh->psf_red[4] = NULL;
}

int			init_mysh(t_mysh *mysh, char **env)
{
  memset(mysh, 0, sizeof(t_mysh));
  mysh->value.last_command = -1;
  mysh->value.entree = -1;
  mysh->value.sortie = -1;
  fill_builtins(mysh);
  fill_separators(mysh);
  fill_redirections(mysh);
  if (!(mysh->env = my_wordtab_dup(env)))
    return (1);
  if (reload_path(mysh))
    return (at_exit_mysh_1(mysh));
  if (!(mysh->dir.home = my_strdup(find_env(mysh->env, "HOME="))))
    if (!(mysh->dir.home = my_strdup(".")))
      return (at_exit_mysh_1(mysh));
  mysh->dir.cur = my_strdup(find_env(mysh->env, "PWD="));
  return (0);
}
