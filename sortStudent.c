#include "sortstudent.h"

void sortstudent(List* head)
{
	for (List* turn = head->next; turn->next != NULL; turn = turn->next)
	{
		for (List* move = turn->next; move != NULL; move = move->next)
		{
			if (turn->student.score < move->student.score)
			{
				student temp = turn->student;
				turn->student = move->student;
				move->student = temp;
			}
		}
	}
	printstudent(head);
}
