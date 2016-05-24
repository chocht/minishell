/*
** mysh.h for mysh in /home/chauch_p/Repositories/other/minishell
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 24 11:02:57 2016 Pierre Chauchoy
** Last update Tue May 24 19:37:13 2016 Pierre Chauchoy
*/

#ifndef MYSH_H_
# define MYSH_H_

# define BUILTINS	6
# define CD		"cd"
# define ENV		"env"
# define SETENV		"setenv"
# define UNSETENV	"unsetenv"
# define EXIT		"exit"
# define ECHO		"echo"

# define SHPATH		"PATH"

# define POINT_COMA	";"
# define EQUAL		'='
# define SEPARATION	" \t"
# define SEP_PATH	":"
# define MINUSS		"-"
# define TILDE		"~"
# define LEN_GETCWD	1024

# define ERR_EXECVE	"execve failed"
# define ERR_FORK	"fork failed"
# define ERR_SIG	"signal failed"
# define ERR_GETCWD	"getcwd failed"
# define ERR_SEGFAULT	"Segmentation fault"
# define ERR_FLOATING	"Floating exception"
# define ERR_ABORT	"Abort"
# define ERR_CMD	"command not found"
# define ERR_FEWARGS	"Too few arguments"
# define ERR_MANYARGS	"Too many arguments"
# define ERR_SYNTAX	"Expression Syntax"
# define ERR_NOTHING	"No such file or directory"
# define ERR_NOT_DIR	"Not a directory"
# define MSG_DIR	"Directory:"

typedef struct		s_dir
{
  char			*old;
  char			*cur;
  char			*home;
}			t_dir;

typedef struct		s_mysh
{
  char			*bi[BUILTINS + 1];
  int			(*prgm[BUILTINS + 1])(struct s_mysh*);
  char			**env;
  char			**command;
  char			**separator;
  char			**path;
  char			*s;
  t_dir			dir;
}			t_mysh;

/*
** builtins
*/

int			my_cd(t_mysh*);
int			my_env(t_mysh*);
int			my_setenv(t_mysh*);
int			my_unsetenv(t_mysh*);
int			my_exit(t_mysh*);
int			my_echo(t_mysh*);

/*
** functions
*/

int			prompt(char**);

int			reload_path(t_mysh*);
char			*find_env(char**, char*);
int			exec_prgm(t_mysh*, char*);

/*
** at_exit_mysh and at_exit_perso
*/

int			at_exit_mysh_1(t_mysh*);
int			at_exit_mysh_err(char*, t_mysh*);
int			at_exit_mysh_msg(char*, t_mysh*);

int			at_exit_free(char**);
int			at_exit_free_wt(char***);

/*
** mysh
*/

int			program(t_mysh*);
int			init_mysh(t_mysh*, char**);
int			minishell(char**);

#endif /* !MYSH_H_ */
