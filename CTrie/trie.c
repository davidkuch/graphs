#include <stdlib.h>
#include <string.h>

#include "trie.h"


#define ALPHA 25
#define INDEX(let) (let - 'a')

enum bool {false, true};


/*-----------------------------------------*/

typedef struct node node;

struct node
{
	node* childs[ALPHA];
	int is_end;
};

static void init_node(node* raw)
{
	for (size_t i = 0; i < ALPHA; ++i)
	{
		raw->childs[i] = NULL;
	}
	
	raw->is_end = false;
}

static node* create_node()
{
	node* ret = (node*)malloc(sizeof(node));
	
	if (ret == NULL)
	{
		return NULL;
	}
	
	init_node(ret);
	
	return ret;
}

static void destroy_node(node *target, int is_root)
{
	for (int i = 0; i < ALPHA; ++i)
	{
		if (target->childs[i] != NULL)
		{
			destroy_node(target->childs[i], false);
			
			/* extra safe */
			target->childs[i] = NULL;
		}
	}
	
	if (is_root == false)
	{
		free(target);
	}
}

static int node_is_leaf(const node* th__)
{
	int ret = true;
	
	for (int i = 0; i < ALPHA; ++i)
	{
		if (th__->childs[i] != NULL)
		{
			ret = false;
		}
	}
	
	return ret;
}

/* places string str starting from start index, with root as root */
static int node_slide(node* root, const char* str, int start_index)
{
	char curr_char = str[start_index];
	
	if (curr_char == '\0')
	{
		root->is_end = true;
		
		return 0;
	}	
	
	if (root->childs[INDEX(curr_char)] == NULL)
	{
		root->childs[INDEX(curr_char)] = create_node();
	}
	
	return node_slide(root->childs[INDEX(curr_char)], str, start_index + 1);
}

/* checks if str[start_index : ] exists from root */
static int node_check(const node* root, const char* str,int start_index)
{
	char curr_char = str[start_index];
	
	/* end of recursion */
	if (curr_char == '\0')
	{
		if	(root->is_end == true)
		{
			return true;		
		}
		else
		{
			return false;
		}	
	}
	
	/* case no next node for next char */
	if (root->childs[INDEX(curr_char)] == NULL)
	{
		return false;
	}
	
	return node_check(root->childs[INDEX(curr_char)], str, start_index + 1);	
}

/* detaches string str[start_index : ] from root. memory is not freed, lazy... */
static void node_detach(node* root, const char* str,int start_index)
{
	char curr_char = str[start_index];
	
	if (curr_char == '\0')
	{
		root->is_end = false;
		
		return;
	}
	
	node* next_node = root->childs[INDEX(curr_char)];
	
	node_detach(next_node, str, start_index + 1);
	
		
}

/*----------------------------------------*/

struct trie
{
	node root;

};


trie_ty* create()
{
	trie_ty* ret = (trie_ty *)malloc(sizeof(trie_ty));
	
	if (ret == NULL)
	{
		return NULL;
	}
	
	init_node(&(ret->root));
	
	return ret;
}

void destroy(trie_ty* trie)
{
	destroy_node(&trie->root, true);
	
	free(trie);
}

int add(trie_ty* th_, const char* str)
{
	int succes = node_slide(&(th_->root), str, 0);
	
	return succes;
}

/* removing string that is not present is undefined */
int remove_str(trie_ty* trie, const char* str)
{
	node_detach(&trie->root, str, 0);
}

int isPresent(const trie_ty* th_, const char* str)
{
	int is_present = node_check(&(th_->root),str, 0);
	
	return is_present;
}

size_t count(const trie_ty* trie)
{

}

int isEmpty(const trie_ty* th_)
{
	int root_is_leaf = node_is_leaf(&(th_->root));

	return root_is_leaf;
}
