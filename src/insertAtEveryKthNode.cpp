/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	struct node* newNode, *current, *temp = head;
	int index, len = 0, value = K;
	if (head == NULL || K <= 0)
	    return NULL;

	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	while (K <= len)
	{
		 current = head;
		 for (index = 1; index < K; index++)
		 {
			  current = current->next;
			  if (current == NULL)
				 return head;
		 }
		 newNode = (struct node*) malloc(sizeof(struct node));
		 newNode->num = value;
		 newNode->next = current->next;
		 current->next = newNode;
		 len++;
		 K += value+1;

	}
	return head;
}
