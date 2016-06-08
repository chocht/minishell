/*
** list.c for mysh in /home/chauch_p/Repositories/PSU_2015_42sh
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Sun Jun  5 21:09:58 2016 Pierre Chauchoy
** Last update Sun Jun  5 21:39:48 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void		init_list(t_list *list)
{
  list->len = 0;
  list->head = NULL;
  list->tail = NULL;
}

void		show_list(t_list *list)
{
  t_elem	*tmp;

  tmp = list->head;
  while (tmp)
    {
      my_printf("%t\n", tmp->command);
      my_printf("entree : %d\n", tmp->entree);
      my_printf("sortie : %d\n", tmp->sortie);
      tmp = tmp->next;
    }
}

int		add_list(t_list *list, char **command, int entree, int sortie)
{
  t_elem	*new;

  if (!(list) || !(new = malloc(sizeof(t_elem))))
    return (1);
  if (list->tail == NULL)
    list->head = new;
  else
    list->tail->next = new;
  new->command = my_wordtab_dup(command);
  new->entree = entree;
  new->sortie = sortie;
  new->next = NULL;
  new->prev = list->tail;
  list->tail = new;
  list->len++;
  return (0);
}

int		free_list(t_list *list)
{
  t_elem	*old;
  t_elem	*tmp;

  if (!(list))
    return (1);
  tmp = list->head;
  while (tmp)
    {
      old = tmp;
      tmp = tmp->next;
      my_free_wordtab(&old->command);
      free(old);
    }
  return (0);
}
