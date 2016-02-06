/*
** hashtable.h for  in /home/querat_g/42sh/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu Apr 23 11:01:15 2015 gwendal querat
** Last update Thu Apr 23 11:01:16 2015 gwendal querat
*/

#ifndef HASHTABLE_H_
# define HASHTABLE_H_
#include "listes.h"

struct		s_htb
{
  size_t	size;
  t_mls		**data;
};

struct		s_hdt
{
  size_t  	size;
  void		*data;
  void		*key;
};

typedef struct s_htb t_htb;
typedef struct s_hdt t_hdt;

t_htb	*createhashtable(unsigned int);
void   	destroyhashtable(t_htb *);
void   	*hasht_getel(void *, size_t, t_htb *);
int    	hasht_addel(void *, size_t, t_htb *, void *);
int	hasht_delel(void *, size_t, t_htb *);
void	hasht_del(t_mls *);
int    	hashnoct(void *, size_t, size_t);

#endif /* !HASHTABLE_H_ */
