/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void reverse(struct node *current, struct node *previous, struct node **head)
{
	struct node *next = current->next;
	if (current->next == NULL)
	{
		*head = current;
		current->next = previous;
		return;
	}
	current->next = previous;
	reverse(next, current, head);
}
struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	reverse(head, NULL, &head);
	
}
