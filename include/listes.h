/*
** listes.h for  in /home/querat_g/42sh/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu Apr 23 11:00:38 2015 gwendal querat
** Last update Thu Apr 23 11:00:38 2015 gwendal querat
*/

#ifndef LISTES_H_
# define LISTES_H_

# define MERROR -1
# define MFALSE  0
# define MTRUE   1

struct		s_mls
{
  void		*item;
  struct s_mls	*next;
  struct s_mls	*prev;
};

typedef struct s_mls t_mls;

int	list_freeel(t_mls *, void (*)(t_mls *));
int	list_addel(t_mls *, void *, void (*)(t_mls *, void *));
int	list_delel(t_mls *, void (*)(t_mls *));
t_mls	*createlist(void *, void (*)(t_mls *, void *));
int	freelist(t_mls *, void (*)(t_mls *));
int	printlist(t_mls *, void (*)(t_mls *));
int	ilistsort(t_mls *, int (*)(t_mls *, t_mls *));

#endif /* !LISTES_H_ */
