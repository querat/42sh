/*
** is_alphanum.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 17:14:39 2015 gwendal querat
** Last update Fri May  1 17:16:16 2015 gwendal querat
*/

int	is_alphanum(unsigned char c)
{
  return ((c >= 'a' && c <= 'z') ||
	  (c >= 'A' && c <= 'Z') ||
	  (c >= '0' && c <= '9'));
}
