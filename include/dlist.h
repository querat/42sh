/*
** dlist.h for  in /home/querat_g/libmy/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Wed Apr 15 11:42:17 2015 gwendal querat
** Last update Sat May 23 18:09:25 2015 gwendal querat
*/

#ifndef DLIST_H_
# define DLIST_H_

typedef struct		s_dlist
{
  struct s_dlist	*next;
  struct s_dlist	*prev;
  void			*data;
} t_dlist;

int	dlist_len(t_dlist *list);

/*
** ----------------------------------------------------------------------------
** dlist_create.c
*/
t_dlist *add_head_dlist_elem(t_dlist *list);
t_dlist *add_dlist_elem(t_dlist *list);
t_dlist *insert_dlist(t_dlist *list, size_t pos);

/*
** ----------------------------------------------------------------------------
** dlist_destroy.c
*/
t_dlist	*rm_first_dlist(t_dlist *list, void(*freefunc)(void*));
t_dlist	*rm_dlist_elem(t_dlist *list, size_t pos, void(*freefunc)(void*));
t_dlist	*destroy_dlist(t_dlist *list, void(*freefunc)(void*));

/*
** ----------------------------------------------------------------------------
** dlist_util.c
*/
size_t  count_dlist(t_dlist *list);
void    print_dlist(t_dlist *list, void (*func)(void*));
t_dlist *goto_last_dlist(t_dlist *list);
t_dlist *goto_pos_dlist(t_dlist *list, size_t pos);

#endif /* !dlist.h */
