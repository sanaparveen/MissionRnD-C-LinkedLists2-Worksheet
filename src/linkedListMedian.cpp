/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	struct node *oneStep = head; //one step pointer
	struct node *twoStep = head; // double step pointer
	int flag = 0, n = 0,result=0;

	if (head == NULL)
	{
		return -1;
	}
	while (twoStep != NULL && twoStep->next != NULL)
	{
			twoStep = twoStep->next->next;
			if (twoStep != NULL)
			{
				oneStep = oneStep->next;
			}
			else
				flag = 1;
	}
	if (flag == 0)
		return oneStep->num;
	else  //in case there are even no. of data items
	{
		n = oneStep->num;
		oneStep = oneStep->next;
		return (n + oneStep->num) / 2;
	}
	return -1;
}
