/*
** my_echo4.c for 42sh in /home/andrea_j/rendu/Shell_Programming/PSU_2015_42sh
** 
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
** 
** Started on  Sun Jun  5 10:12:48 2016 Julien Andreani
** Last update Sun Jun  5 23:51:42 2016 Julien Andreani
*/

#include "mysh.h"

void		echo_bs_0(t_echo *echo, int *j)
{
  echo->flag = 2;
  echo->k = 0;
  echo->code[echo->k++] = 48;
}

void		echo_bs_n(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\n';
}

void		echo_bs_f(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\f';
}

void		echo_bs_r(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\r';
}
