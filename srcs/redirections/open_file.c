/*
** open_file.c for open files in /home/echeva_t/rendu/PSU_2015_42sh/srcs/redirection
** 
** Made by thomas echevard
** Login   <echeva_t@epitech.net>
** 
** Started on  Thu May 26 14:08:49 2016 thomas echevard
** Last update Sun Jun  5 16:16:23 2016 Julien Andreani
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mysh.h"
#include "my.h"

int		open_file_create(char *file)
{
  int		fd;

  if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 00644)) == -1)
    return (at_exit_m1(ERR_OPEN));
  return (fd);
}

int		open_file_concat(char *file)
{
  struct stat	sb;
  int		fd;

  if ((fd = open(file, O_RDWR | O_CREAT | O_APPEND, 00644)) == -1)
    return (at_exit_m1(ERR_NOTHING));
  if (stat(file, &sb) == -1)
    return (at_exit_m1(ERR_STAT));
  if ((sb.st_mode & S_IFMT) == S_IFDIR)
    return (at_exit_m1(ERR_READ_DIR));
  return (fd);
}

int		open_file_read(char *file)
{
  struct stat	sb;
  int		fd;

  if (stat(file, &sb) == -1)
    return (at_exit_m1(ERR_STAT));
  if ((sb.st_mode & S_IFMT) == S_IFDIR)
    return (at_exit_m1(ERR_READ_DIR));
  if ((fd = open(file, O_RDONLY)) == -1)
    return (at_exit_m1(ERR_NOTHING));
  return (fd);
}
