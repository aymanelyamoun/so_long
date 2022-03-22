#include <unistd.h>
struct s_list
{
	struct list	*next;
	struct list	*prev;
	char		*str;
};

typedef struct s_list t_list;

t_list *add_at_end(t_list **list, char **str);