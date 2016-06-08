/*
** mysh.h for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:02:57 2016 Pierre Chauchoy
** Last update Sun Jun  5 23:52:09 2016 Julien Andreani
*/

#ifndef MYSH_H_
# define MYSH_H_

#include		"define.h"
#include		"struct.h"

enum			e_opt_echo
  {
    N,
    E,
    E_M
  };

/*
** builtins
** redirections
** separations
*/

int			update_old_and_cur_dir(t_mysh*, char*);
int			my_cd(t_mysh*);
int			my_env(t_mysh*);
int			my_setenv(t_mysh*);
int			my_unsetenv(t_mysh*);
int			my_exit(t_mysh*);
int			my_echo(t_mysh*);

void			echo_bs_b(t_echo*, int*);
void			echo_bs_t(t_echo*, int*);
void			echo_bs_v(t_echo*, int*);
void			echo_bs_a(t_echo*, int*);
void			echo_bs_bs(t_echo*, int*);
void			echo_bs_n(t_echo*, int*);
void			echo_bs_f(t_echo*, int*);
void			echo_bs_r(t_echo*, int*);
void			echo_bs_0(t_echo*, int*);
void			init_opt(t_echo*);
int			check_options(char**, int, t_echo*);
int			dest_alloc(t_echo*, int, char**);
void			dest_free(t_echo*);

int			open_file_create(char*);
int			open_file_concat(char*);
int			open_file_read(char*);
int			my_leftrd(t_mysh*);
int			my_db_leftrd(t_mysh*);
int			my_rightrd(t_mysh*);
int			my_db_rightrd(t_mysh*);

int			my_pipe(t_mysh*);
int			my_semicolon(t_mysh*);
int			my_db_amp(t_mysh*);
int			my_db_pipe(t_mysh*);

/*
** functions
*/

int			prompt();

int			reload_path(t_mysh*);
char			*find_env(char**, char*);
int			exec_prgm(t_mysh*, char*);

void			err_execve(int);
int			my_spipe(t_mysh*);
int			my_mpipe(t_mysh*);

/*
** list
*/

void			init_list(t_list*);
void			show_list(t_list*);
int			add_list(t_list*, char**, int, int);
int			free_list(t_list*);

/*
** at_exit_mysh and at_exit_perso
*/

int			at_exit_mysh_1(t_mysh*);
int			at_exit_mysh_err(char*, t_mysh*);
int			at_exit_mysh_msg(char*, t_mysh*);

int			at_exit_free(char**);
void			*at_exit_free_n(char**);
int			at_exit_free_wt(char***);

/*
** mysh
*/

int			between_separators(t_mysh*);
int			organize_between(t_mysh*);
int			program(t_mysh*);
int			init_mysh(t_mysh*, char**);
int			go_parse_this(t_mysh*, char*);
int			minishell(char**);

#endif /* !MYSH_H_ */
