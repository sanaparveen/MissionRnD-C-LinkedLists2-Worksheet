/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node* merge2List(struct node* a, struct node* b)
{

	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	if (a->num <= b->num)
	{
		a->next = merge2List(a->next, b);
		return a;
	}
	else
	{
		b->next = merge2List(a, b->next);
		return b;
	}
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL&&head2 == NULL)
	    return NULL;
	struct node *result = (struct node *)malloc(sizeof(struct node));
	result = merge2List(head1, head2);
	return result;
}
