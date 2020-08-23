/*
 * Program to multiply 2 operands (numbers) recursively. We will be using
 * repetitive addition to get the multiplication output.
 *
 * Author: Sunny Bhayani
 */

/* ---- Includes ------------------------------------------------------------ */
#include "stdio.h"
#include "stdlib.h"

/* ---- Defines / Macros ---------------------------------------------------- */
#define FALSE       0
#define TRUE        1

/* ---- Typedefs ------------------------------------------------------------ */
typedef struct node {
    int data;
    struct node *next;
} node_t;

/* ---- Local function definitions ------------------------------------------ */
/*
 * Function to get new node.
 *
 * Allocate a new node (dynamically), and initialize the members.
 *
 * @param [in]: num:    data to be initialized in the new node
 *
 * return:  new node pointer (allocated dynamically)
 */
static node_t* new_node(int num)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if (!tmp)
    {
        printf("malloc failed !!\n");
        exit(0);
    }

    tmp->data = num;
    tmp->next = NULL;

    printf("-- Create new node: data=%d\n", num);

    return tmp;
}

/*
 * Function to print the linked list from HEAD pointer.
 *
 * @param [in]: head:   HEAD pointer
 *
 * return:  none
 */
static void print_list(node_t *head)
{
    if (head == NULL)
    {
        printf("List is EMPTY (HEAD is NULL)\n");
    }
    else
    {
        node_t *tmp = head;

        printf("List is: ");
        while(tmp)
        {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }

        printf("NULL\n\n");
    }
}

/*
 * Function to insert a new node at the end of the list.
 *
 * Need to take care of one special case i.e. if the list is Empty, then update
 * the HEAD pointer to point to the new node.
 *
 * @param [in]: head:   HEAD pointer (double pointer since we need to maipulate
 *                      this pointer in the special case)
 * @param [in]: num:    data to be initialized in the new node
 *
 * return:  none
 */
static void insert_end(node_t **head, int num)
{
    node_t *tmp;
    tmp = new_node(num);

    if (*head == NULL)
    {
        printf("---- Insert End: List is EMPTY (HEAD is NULL)\n");
        *head = tmp;
    }
    else
    {
        node_t *end = *head;

        while(end && (end->next != NULL))
        {
            end = end->next;
        }

        end->next = tmp;
    }
    printf("---- Insert End: data=%d\n", num);

    print_list( *head);
}

/*
 * Function to delete a node from the list.
 *
 * Need to take care of one special case i.e. if there is only one node in the
 * list, then need to make the HEAD pointer as NULL.
 *
 * @param [in]: head:   HEAD pointer (double pointer since we need to maipulate
 *                      this pointer in the special case)
 * @param [in]: num:    data to be removed from the list
 *
 * return:  none
 */
static void del_node(node_t **head, int num)
{
    if (NULL == *head)
    {
    	printf("---- Del Node: List is EMPTY (HEAD is NULL)\n\n");
    }
    else
    {
    	int found = FALSE;
        node_t *tmp = *head;
        node_t *prev = tmp;

        while (tmp)
        {
        	if (tmp->data == num)
            {
            	found = TRUE;

            	if ((*head)->data == num)
                {
                	*head = tmp->next;
                }
                else
                {
                    prev->next = tmp->next;
                }

            	printf("---- Del Node: data=%d: found, deleting this node ...\n", num);
                
                free(tmp);

                print_list(*head);

                break;
            }

            prev = tmp;
        	tmp = tmp->next;
        }

        if (FALSE == found)
        {
        	printf("---- Del Node: data=%d: Not found !!\n\n", num);
        }
    }
}

/*
 * C entry point
 */
void main(void)
{
    int i;
    node_t *head = NULL;

    /* Test the sanity check for Delete node */
    del_node(&head, 3);

    /* Fill the linked-list */
    for (i=1; i<5; i++)
    {
        insert_end(&head, i);
    }

    /* Delete the nodes */
    del_node(&head, 7);
    del_node(&head, 3);

    for (i=1; i<5; i++)
    {
        del_node(&head, i);
    }
}
