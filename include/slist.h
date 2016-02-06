/*
** slist.h for  in /home/querat_g/libmy/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Wed Apr 15 11:42:17 2015 gwendal querat
** Last update Tue May 19 21:22:11 2015 gwendal querat
*/

#ifndef SLIST_H_
# define SLIST_H_

typedef struct		s_slist
{
  struct s_slist	*next;
  void			*data;
} t_slist;

/*
** ----------------------------------------------------------------------------
** slist_create.c
*/
t_slist *add_head_slist_elem(t_slist *list);
t_slist *add_slist_elem(t_slist *list);
t_slist *insert_slist(t_slist *list, size_t pos);

/*
** ----------------------------------------------------------------------------
** slist_destroy.c
*/
t_slist	*rm_first_slist(t_slist *list, void(*freefunc)(void*));
t_slist	*rm_slist_elem(t_slist *list, size_t pos, void(*freefunc)(void*));
t_slist	*destroy_slist(t_slist *list, void(*freefunc)(void*));

/*
** ----------------------------------------------------------------------------
** slist_util.c
*/
size_t  count_slist(t_slist *list);
void    print_slist(t_slist *list, void (*func)(void*));
t_slist *goto_last_slist(t_slist *list);
t_slist *goto_pos_slist(t_slist *list, size_t pos);

#endif /* !slist.h */
