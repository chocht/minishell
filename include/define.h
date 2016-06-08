/*
** define.h for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sun Jun  5 23:00:04 2016 Pierre Chauchoy
** Last update Sun Jun  5 23:38:09 2016 Pierre Chauchoy
*/

#ifndef DEFINE_H_
# define DEFINE_H_

# define BUILTINS	6
# define CD		"cd"
# define ENV		"env"
# define SETENV		"setenv"
# define UNSETENV	"unsetenv"
# define EXIT		"exit"
# define ECHO		"echo"

# define NB_SEP		4
# define SEPARATOR	";&|"
# define SEMICOLON	";"
# define DB_AMP		"&&"
# define DB_PIPE	"||"
# define PIPE		"|"
# define SEP_CMD	" \t"
# define SEP_PATH	":"

# define REDIRECTION	4
# define SEP_RED	"<>|"
# define LEFTRD		"<"
# define DB_LEFTRD	"<<"
# define RIGHTRD	">"
# define DB_RIGHTRD	">>"

# define SHPATH		"PATH"
# define MINUSS		"-"
# define TILDE		"~"
# define SLASH		'/'
# define POINT		'.'
# define EQUAL		'='
# define SPACE		' '
# define TAB		'\t'
# define LEN_GETCWD	1024

# define ECHO_OPT_NB	3
# define ECHO_N		"-n"
# define ECHO_E		"-e"
# define ECHO_EM	"-E"
# define ECHO_BS_B	'b'
# define ECHO_BS_T	't'
# define ECHO_BS_V	'v'
# define ECHO_BS_A	'a'
# define ECHO_BS_BS	'\\'
# define ECHO_BS_0	'0'
# define ECHO_BS_N	'\n'
# define ECHO_BS_F	'\f'
# define ECHO_BS_R	'\r'

# define ERR_EXECVE	"execve failed"
# define ERR_FORK	"fork failed"
# define ERR_SIG	"signal failed"
# define ERR_GETCWD	"getcwd failed"
# define ERR_SEGFAULT	"Segmentation fault"
# define ERR_FLOATING	"Floating exception"
# define ERR_ABORT	"Abort"
# define ERR_CMD	"Command not found"
# define ERR_FEWARGS	"Too few arguments"
# define ERR_MANYARGS	"Too many arguments"
# define ERR_SYNTAX	"Expression Syntax"
# define ERR_NOTHING	"No such file or directory"
# define ERR_NOT_DIR	"Not a directory"
# define ERR_DUP2	"dup2 failed"
# define ERR_PIPE	"pipe failed"
# define ERR_STAT	"stat failed"
# define ERR_PERM	"Permission denied"
# define MSG_DIR	"Directory:"
# define ERR_READ_DIR	"you tried to open a directory"
# define ERR_OPEN	"open failed"
# define ERR_ENV	"No environment"

#endif /* !DEFINE_H_ */
