/*
** my_graph.h for  in /home/querat_g/libmy/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Wed Apr 15 11:35:39 2015 gwendal querat
** Last update Wed Apr 22 15:05:32 2015 gwendal querat
*/

#ifndef MY_GRAPH_H_
# define MY_GRAPH_H_

typedef struct	s_node
{
  t_slist	*edges;
  void		*data;
  size_t	id;
} t_node;

typedef struct	s_net
{
  char		*name;
  t_slist	*nodes;
  int		nb_links;
  int		nb_nodes;
  size_t	assigned_ids;
} t_net;

t_net		*init_network(char *name);
int		add_node(t_net *g);
int		add_edge(t_net *g, size_t id1, size_t id2);
int		add_directed_edge(t_net *g, size_t id1, size_t id2);
int		brk_edge(t_net *g, size_t id1, size_t id2);
int		brk_directed_edge(t_net *g, size_t id1, size_t id2);
int		check_edge(t_net *g, size_t id1, size_t id2);
int		set_node_data(t_net *g, size_t id, void *data);
void		*get_node_data(t_net *g, size_t id);

void		print_network(t_net *g, void (*func)(t_slist*));
t_node		*find_node(t_net *g, size_t id);
size_t		find_node_slist_pos(t_net *g, size_t id);
int		brk_node(t_net *g, size_t id);
void		free_network(t_net *g, void (*freefunc)(void*));
int		edge_exists(t_node *node_a, t_node *node_b);
int		brk_all_node_edges(t_net *g, t_node *node);

void		free_nodes(void *data);

#endif /* !my_graph.h */
