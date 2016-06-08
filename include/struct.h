/*
** struct.h for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sun Jun  5 23:01:12 2016 Pierre Chauchoy
** Last update Sun Jun  5 23:52:49 2016 Julien Andreani
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_elem
{
  char			**command;
  int			entree;
  int			sortie;
  struct s_elem		*prev;
  struct s_elem		*next;
}			t_elem;

typedef struct		s_list
{
  int			len;
  struct s_elem		*head;
  struct s_elem		*tail;
}			t_list;

typedef struct		s_echo
{
  char			opt;
  char			*opt_ref[ECHO_OPT_NB + 1];
  char			bs_ref[10];
  void			(*ptr_bs[9])(struct s_echo*, int*);
  char			*dest;
  int			d_len;
  int			flag;
  char			code[5];
  int			k;
}			t_echo;

typedef struct		s_dir
{
  char			*old;
  char			*cur;
  char			*home;
}			t_dir;

typedef struct		s_value
{
  int			last_command;
  int			entree;
  int			sortie;
  int		        index;
  int		        index_between;
  int			launch_pipe_prgm;
}			t_value;

typedef struct		s_mysh
{
  char			**env;
  char			**path;
  char			*bi[BUILTINS + 1];
  int			(*prgm[BUILTINS + 1])(struct s_mysh*);
  char			**command;
  t_list		commands;
  char			*sep[NB_SEP + 1];
  int			(*psf_sep[NB_SEP + 1])(struct s_mysh*);
  char			**tokens;
  char			**separator;
  char			*red[REDIRECTION + 1];
  int			(*psf_red[REDIRECTION + 1])(struct s_mysh*);
  char			**redirection;
  char			**between;
  char			*s;
  t_dir			dir;
  t_value		value;
}			t_mysh;

#endif /* !STRUCT_H_ */
