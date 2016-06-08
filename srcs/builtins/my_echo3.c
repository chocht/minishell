/*
** my_echo3.c for 42sh in /home/andrea_j/rendu/Shell_Programming/PSU_2015_42sh
** 
** Made by Julien Andreani
** Login   <andrea_j@epitech.net>
** 
** Started on  Sun Jun  5 10:09:42 2016 Julien Andreani
** Last update Sun Jun  5 10:12:37 2016 Julien Andreani
*/

#include "mysh.h"

void		echo_bs_b(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\b';
}

void		echo_bs_t(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\t';
}

void		echo_bs_v(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\v';
}

void		echo_bs_a(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\a';
}

void		echo_bs_bs(t_echo *echo, int *j)
{
  echo->dest[(*j)++] = '\\';
}
