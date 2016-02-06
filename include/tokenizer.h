/*
** my.h for 42sh in /home/bellia_n/banc_essai/termcaps
** 
** Made by 
** Login   <bellia_n@epitech.net>
** 
** Started on  Wed Apr 22 14:12:48 2015 
** Last update Sun May 24 18:18:09 2015 gwendal querat
*/

#ifndef TOKENIZER_H_
# define TOKENIZER_H_

# include <glob.h>
# include "dlist.h"
# include "my_process.h"

#define	RESERVED_CHARS	"<>|&; \t"

/*
** inhibiteurs
*/
# define IS_SP_QUOTED   1
# define IS_DB_QUOTED	2
# define IS_BACKSLASHED	4
# define IS_QUOTED	(IS_SP_QUOTED | IS_DB_QUOTED)

# ifndef CONDITION
#  define CONDITION	0
# endif
# ifndef EXECUTION
#  define EXECUTION	1
# endif

/*
** ----------------------------------------------------------------------------
** token structure
*/
typedef struct s_tok
{
  char		*word;
  int		flag;
} t_tok;

/*
** ----------------------------------------------------------------------------
** prototypes
*/
t_dlist	*tokenizer(char *line, t_lnv *envlist);
t_tok	*get_next_token(char *line, int *i);
char	*str_insert(char *host, char *ins, int pos);
int	is_backslash(char *line, int *i, t_tok *tok);
int	is_inhibited(char *line, int *i, t_tok *tok);
int	is_db_quote(char *line, int *i, t_tok *tok);
int	is_sp_quote(char *line, int *i, t_tok *tok);
int	is_not_reserved_char(char *line, int *j, t_tok *tok);
int	done(char *line, int *i, t_tok *tok);
int	toggle_db_quote(char *line, int i, t_tok *tok);
int	toggle_sp_quote(char *line, int i, t_tok *tok);
int	toggle_backslashed(char *line, int i, t_tok *tok);
int	word_len(char *line, int i, t_tok *tok);
int	is_db_left(char *line, int *i , t_tok *tok);
int	get_db_left(char *line, int *i , t_tok *tok);
int	is_db_right(char *line, int *i , t_tok *tok);
int	get_db_right(char *line, int *i , t_tok *tok);
int	is_sp_right(char *line, int *i , t_tok *tok);
int	get_sp_right(char *line, int *i , t_tok *tok);
int	is_sp_left(char *line, int *i , t_tok *tok);
int	get_sp_left(char *line, int *i , t_tok *tok);
int	is_and(char *line, int *i , t_tok *tok);
int	get_and(char *line, int *i , t_tok *tok);
int	is_pipe(char *line, int *i , t_tok *tok);
int	get_pipe(char *line, int *i , t_tok *tok);
int	is_semicolon(char *line, int *i , t_tok *tok);
int	get_semicolon(char *line, int *i , t_tok *tok);
int	is_oror(char *line, int *i , t_tok *tok);
int	get_oror(char *line, int *i , t_tok *tok);
int	is_andand(char *line, int *i , t_tok *tok);
int	get_andand(char *line, int *i , t_tok *tok);
t_tok	*get_next_token(char *line, int *i);
int	get_word(char *line, int *i, t_tok *tok);
t_tok	*epur_tok(t_tok *tok);
char	*rm_char(char *line, int i);
void	free_token(void *data);
void	skipspace(char *str, int *i);
int	still_var_name(char *line, int *i, t_tok *state);
char	*get_var_name(char *line, t_tok *state, t_lnv *envlist);
void	toggle_inhibit(char *line, int i, t_tok *state);
char	*expand_var(char *line, int *i, t_lnv *envlist, t_tok *state);
char	*expand_variables(char *line, t_lnv *envlist);
char	*expand_globbing(char *line);
char	*expand_glob(char *line);
char	*glob_str_malloc(glob_t *globb);
void	cpy_glob_str(glob_t *globb, char *dest);
char	*get_globbed_str(char *raw);

#endif /* tokenizer.h */
