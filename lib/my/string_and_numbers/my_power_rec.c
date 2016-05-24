/*
** my_power_rec.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May 17 12:48:30 2016 Pierre Chauchoy
** Last update Tue May 17 12:48:31 2016 Pierre Chauchoy
*/

int		rec(int nb, int power, int i, int temp)
{
  if (i >= power)
    return (nb);
  nb = nb * temp;
  i = i + 1;
  rec(nb, power, i, temp);
  return (rec(nb, power, i, temp));
}

int		my_power_rec(int nb, int power)
{
  int		temp;

  temp = nb;
  if (power == 0 && nb != 0)
    return (1);
  else if (power < 0)
    return (0);
  else
    return (rec(nb, power, 1, temp));
}
