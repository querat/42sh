/*
** str_to_wordtab.h for  in /home/querat_g/42sh/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu Apr 23 11:00:56 2015 gwendal querat
** Last update Thu Apr 23 11:00:57 2015 gwendal querat
*/

#ifndef STR_TO_WORDTAB_H_
# define STR_TO_WORDTAB_H_

struct  s_my_wd
{
  int   nb_words;
  char  *str;
  char  **my_wordtab;
};
struct          s_my_lwd
{
  struct        s_my_lwd *prev;
  struct        s_my_lwd *next;
  char          *str;
};

typedef struct s_my_wd t_my_wd;
typedef struct s_my_lwd t_my_lwd;

#endif /* !STR_TO_WORDTAB_H_ */
