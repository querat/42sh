/*
** my.h for 42sh in /home/bellia_n/banc_essai/termcaps
** 
** Made by 
** Login   <bellia_n@epitech.net>
** 
** Started on  Wed Apr 22 14:12:48 2015 
** Last update Sun May 24 16:48:42 2015 gwendal querat
*/

#ifndef READLINE_H_
# define READLINE_H_

#include <termios.h>
#include <ncurses/curses.h>
#include <stropts.h>
#include <stdlib.h>
#include "dlist.h"

/*
** ----------------------------------------------------------------------------
** various readline related macros
*/
#define HIST_MAX_SIZE	10
#define READLINE_SZ	32
#define FAILURE		-1
#define RD_TAB		42
#define CONDITION__	0
#define INSTRUCTION	1
#define MAX_LEN		8192

/*
** ----------------------------------------------------------------------------
** key mapping macros
*/
#define PRINTABLE_CHAR	(rdl->input >= 32 && rdl->input <= 126)
#define ENTER_KEY	10
#define BACKSPACE_KEY	127
#define DELETE_KEY	295
#define UP_KEY		183
#define DOWN_KEY	184
#define LEFT_KEY	186
#define RIGHT_KEY	185
#define TABULATION	9
#define END_KEY		176
#define BEG_KEY		178
#define CTRL_A		1
#define CTRL_K		11
#define CTRL_U		21
#define CTRL_R		18
#define CTRL_L		12
#define CTRL_Y		25
#define CTRL_D		4
#define ENTER		10
#define CTRL_LEFT	347
#define CTRL_RIGHT	346

/*
** ----------------------------------------------------------------------------
** readline structure, conaining every readline-related stuff
*/
typedef struct s_readline
{
  unsigned char	buffer[READLINE_SZ];
  unsigned char	*line;
  char		*prompt;
  int		pos;
  int		input;
  unsigned char	flag;
  unsigned char	*kill;
  t_dlist	*hist;
  t_dlist	*cur_hist;
  char		browsing_hist;
  int		print;
} t_line;

/*
** ----------------------------------------------------------------------------
** readline prototypes
*/
int		rawmode(void);
int		canonmode(void);
int		is_alphanum(unsigned char c);
int		concat_char(t_line *rdl, void *data);
int		cast_buffer(unsigned char *buffer);
int		call_func_by_keycode(t_line *rdl);
unsigned char	*readline(t_line *rdl);
char		*get_term_name_cpy(char *str);
char		*get_term_name(char **envp);
char		*get_term_name_detect(char **envp);
int		getent_term(char **envp);

/*
** ----------------------------------------------------------------------------
** functions for the double array of functions pointers
*/
int	is_printable_char(t_line *rdl, void *data);
int	concat_char(t_line *rdl, void *data);
void	print_char_concat(t_line *rdl, void *data);
int	is_backspace(t_line *rdl, void *data);
int     backspace(t_line *rdl, void *data);
int	is_delete(t_line *rdl, void *data);
int     delete_char(t_line *rdl, void *data);
int	is_ctrlk(t_line *rdl, void *data);
int     kill_buffer_end(t_line *rdl, void *data);
int	is_ctrlu(t_line *rdl, void *data);
int     kill_buffer_beg(t_line *rdl, void *data);
int	is_tab(t_line *rdl, void *data);
int     autocomplete(t_line *rdl, void *data);
int	is_upkey(t_line *rdl, void *data);
int     hist_up(t_line *rdl, void *data);
int	is_downkey(t_line *rdl, void *data);
int     hist_down(t_line *rdl, void *data);
int	hist_down_management(t_line *rdl);
int	is_leftkey(t_line *rdl, void *data);
int     move_cursor_left(t_line *rdl, void *data);
int	is_rightkey(t_line *rdl, void *data);
int     move_cursor_right(t_line *rdl, void *data);
int	is_endkey(t_line *rdl, void *data);
int     cursor_end(t_line *rdl, void *data);
int	is_begkey(t_line *rdl, void *data);
int     cursor_beg(t_line *rdl, void *data);
int	is_ctrlr(t_line *rdl, void *data);
int     hist_search(t_line *rdl, void *data);
int	is_ctrll(t_line *rdl, void *data);
int     my_clear(t_line *rdl, void *data);
int	is_ctrly(t_line *rdl, void *data);
int     cpy_kill(t_line *rdl, void *data);
int	is_true(t_line *rdl, void *data);
int     not_ascii(t_line *rdl, void *data);
int	is_ctrl_left(t_line *rdl, void *data);
int     goto_word_left(t_line *rdl, void *data);
int	is_ctrl_right(t_line *rdl, void *data);
int     goto_word_right(t_line *rdl, void *data);

void	print_hist(t_dlist *hist, t_dlist *cur);

/*
** ------------------------------------------------
**termcaps related functions
*/

int	get_nb_char_line(t_line *rdl);
int	get_winsize_x();
int	cursor_management(t_line *rdl);
void	return_to_beg(t_line *rdl, void *data, int flag);
int	is_cursor_left(t_line *rdl);
void	go_up(t_line *rdl);
void	go_down(t_line *rdl, int flag);
int     move_cursor_end(t_line *rdl);

#endif /* READLINE_H_ */
