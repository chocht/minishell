/*
** my_echo2.c for 42sh in /home/andrea_j/rendu/Shell_Programming/PSU_2015_42sh
** 
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
** 
** Started on  Sun Jun  5 09:16:47 2016 Julien Andreani
** Last update Sun Jun  5 23:51:06 2016 Julien Andreani
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void		init_opt(t_echo *echo)
{
  echo->opt_ref[0] = ECHO_N;
  echo->opt_ref[1] = ECHO_E;
  echo->opt_ref[2] = ECHO_EM;
  echo->opt_ref[3] = NULL;
  echo->opt = 0;
  echo->opt |= 1 << E_M;
  echo->bs_ref[0] = ECHO_BS_B;
  echo->bs_ref[1] = ECHO_BS_T;
  echo->bs_ref[2] = ECHO_BS_V;
  echo->bs_ref[3] = ECHO_BS_A;
  echo->bs_ref[4] = ECHO_BS_BS;
  echo->bs_ref[5] = ECHO_BS_N;
  echo->bs_ref[6] = ECHO_BS_F;
  echo->bs_ref[7] = ECHO_BS_R;
  echo->bs_ref[8] = ECHO_BS_0;
  echo->bs_ref[9] = 0;
  echo->ptr_bs[0] = &echo_bs_b;
  echo->ptr_bs[1] = &echo_bs_t;
  echo->ptr_bs[2] = &echo_bs_v;
  echo->ptr_bs[3] = &echo_bs_a;
  echo->ptr_bs[4] = &echo_bs_bs;
  echo->ptr_bs[5] = &echo_bs_n;
  echo->ptr_bs[6] = &echo_bs_f;
  echo->ptr_bs[7] = &echo_bs_r;
  echo->ptr_bs[8] = &echo_bs_0;
}

int		check_options(char **tab, int len, t_echo *echo)
{
  int		i;
  int		j;
  char		t;

  i = 0;
  while (++i < len)
    {
      t = 0;
      j = -1;
      while (++j < ECHO_OPT_NB)
	if (my_strcmp(echo->opt_ref[j], tab[i]) == 0)
	  {
	    t = 1;
	    echo->opt |= 1 << j;
	  }
      if (t == 0)
	return (i);
    }
  return (len);
}

int		dest_alloc(t_echo *echo, int h, char **cmd)
{
  int		i;

  echo->d_len = 0;
  if (h > 1)
    {
      i = 0;
      while (++i < h)
	echo->d_len += my_strlen(cmd[i]);
    }
  echo->d_len += h + 32;
  if (!(echo->dest = xmalloc(sizeof(char) * (echo->d_len + 1))))
    return (1);
  echo->dest[echo->d_len] = 0;
  return (0);
}

void		dest_free(t_echo *echo)
{
  echo->dest[echo->d_len] = 0;
  echo->d_len++;
  while (--echo->d_len >= 0)
    echo->dest[echo->d_len] = 42;
  free(echo->dest);
}
