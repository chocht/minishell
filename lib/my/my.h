/*
** my.h<2> for lib in /home/chauch_p/librairie/samples
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri May 20 14:29:33 2016 Pierre Chauchoy
** Last update Tue May 24 11:30:46 2016 Pierre Chauchoy
*/

#ifndef MY_H_
# define MY_H_

# include		<stdarg.h>

# define SPACE		' '
# define TAB		'\t'
# define MINUS		'-'
# define DOT		'.'
# define PLUS		'+'
# define PERCENT	'%'
# define BACK_N		'\n'

/*
** string and numbers
*/

void			my_putchar(char);
int			my_putstr(char*);
int			my_strlen(char*);
void			my_put_nbr(int);
void			my_putnbr_base(int, int);
int			my_getnbr(char*);
int			my_getnbr_base(char*, char*);
double			my_getnbr_f(char*);
int			my_power_rec(int, int);

char			**my_str_to_wordtab(char*, char*);
int			my_len_wordtab(char**);
void			my_show_wordtab(char**);
void			my_free_wordtab(char**);
char			**my_wordtab_dup(char**);
char			**my_wordtabcat_string(char**, char*);

char			*my_revstr(char*);
char			*my_strdup(char*);
char			*my_strcpy(char*, char*);
char			*my_strstr(char*, ...);
char			*my_strcat_char(char*, char);

int			my_strcmp(char*, char*);
int			my_strcmp_overflow(char*, char*);
int			my_strncmp(char*, char*, int);
int			my_str_isalpha(char*);
int			my_str_isnum_pos(char*);
int			my_str_isnum(char*);
int			my_is_in_str(char, char*);
int			my_is_in_wordtab(char*, char**);
int			my_is_in_inttab(int, int*, int);

/*
** printf
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# define PRINTF_NB_LET	12
# define PRINTF_LETTERS	"diouxXcsSpbt"

typedef struct		s_printf
{
  char			*letters;
  va_list		ap;
  int			p;
  const char		*s;
  int			fd;
  int			len;
  char			*dest;
  int			sprintf;
}			t_printf;

typedef void		(*t_disp_printf)(t_printf*);

int			my_printf(const char*, ...);
int			my_fprintf(int, const char*, ...);
char			*my_sprintf(const char*, ...);

void			printf_dec(t_printf*);
void			printf_oct(t_printf*);
void			printf_uint(t_printf*);
void			printf_uhex(t_printf*);
void			printf_char(t_printf*);
void			printf_str(t_printf*);
void			printf_str_np(t_printf*);
void			printf_ptr(t_printf*);
void			printf_bin(t_printf*);
void			printf_tab(t_printf*);

#endif /* !MY_PRINTF_H_ */

/*
** at_exit , free and malloc
*/

void			*xmalloc(int);
void			my_free_str(char**);
int			at_exit_m1(char*);
int			at_exit_1(char*);
void			*at_exit_null(char*);
int			at_exit_free_1(char*, char*);
void			*at_exit_free_null(char*, char*);

/*
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char			*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */

#endif /* !MY_H_ */
