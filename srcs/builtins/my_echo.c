/*
** my_echo.c for 42sh in /home/andrea_j/rendu/Shell_Programming/PSU_2015_42sh
** 
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
** 
** Started on  Thu Jun  2 13:45:46 2016 Julien Andreani
** Last update Sun Jun  5 14:57:05 2016 Julien Andreani
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static void	my_echo5(t_echo *echo, char *s, int i, int *j)
{
  if (s[i] >= '0' && s[i] <= '9')
    echo->code[echo->k++] = s[i];
  else
    {
      echo->code[echo->k] = 0;
      echo->dest[(*j)++] = (char)my_getnbr_base(echo->code, "01234567");
      if (s[i] == '\\')
	echo->flag = 1;
      else
	{
	  echo->dest[(*j)++] = s[i];
	  echo->flag = 0;
	}
    }
}

static void	my_echo4(t_echo *echo, char *s, int i, int *j)
{
  int		l;

  l = -1;
  while (echo->bs_ref[++l] && echo->bs_ref[l] != s[i]);
  if (echo->bs_ref[l])
    {
      if (echo->ptr_bs[l])
	echo->ptr_bs[l](echo, j);
      else
	{
	  echo->dest[(*j)++] = '\\';
	  echo->dest[(*j)++] = s[i];
	}
    }
}

static void	my_echo3(t_echo *echo, char *s, int i, int *j)
{
  if (echo->flag == 0)
    {
      if (s[i] != '\\')
	echo->dest[(*j)++] = s[i];
      else
	echo->flag = 1;
    }
  else if (echo->flag == 1)
    {
      my_echo4(echo, s, i, j);
      echo->flag == 1 ? echo->flag = 0 : 0;
    }
  else if (echo->flag == 2)
    my_echo5(echo, s, i, j);
}

static void	my_echo2(char *s, t_echo *echo)
{
  int		i;
  int		j;

  if (!(echo->opt & 1 << E))
    {
      my_strcpy(echo->dest, s);
      echo->dest[my_strlen(s)] = 0;
      return ;
    }
  i = -1;
  j = 0;
  echo->flag = 0;
  while (++i < my_strlen(s))
    my_echo3(echo, s, i, &j);
  if (echo->flag == 2)
    {
      echo->code[echo->k] = 0;
      echo->dest[j++] = (char)my_getnbr_base(echo->code, "01234567");
    }
  echo->dest[j] = 0;
}

int		my_echo(t_mysh *mysh)
{
  t_echo	echo;
  int		pos;
  int		len;

  init_opt(&echo);
  len = my_len_wordtab(mysh->command);
  if (dest_alloc(&echo, len, mysh->command))
    return (1);
  pos = check_options(mysh->command, len, &echo);
  pos--;
  while (++pos < len)
    {
      my_echo2(mysh->command[pos], &echo);
      my_printf("%s", echo.dest);
      if (pos + 1 < len)
	my_printf(" ");
    }
  if (!(echo.opt & 1 << N))
    my_printf("\n");
  dest_free(&echo);
  mysh->value.last_command = 0;
  return (0);
}
