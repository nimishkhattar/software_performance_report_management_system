/*
 *      author :- Sonu
 *      date :- 21-10-2022
 *      modified by :- Nimish
 *      description :-Tis file is creating a new spr utilites
 * 					  containing append and prepend utilitites
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>
int append ( spr** head, spr* newspr )
// Time complexity is O(n)
// Time complexity for reading the list is O(n*(n+1)/2) = O(n^2)
{
	spr* iter = *head ;
	if (*head == NULL)
		*head =  newspr ;
	else
	{
		while ( iter -> next != NULL)
		{
			iter = iter -> next ;
		}
		iter -> next = newspr ;
		newspr -> next = NULL ;
	}		
	return EXIT_SUCCESS;
}

int prepend ( spr** head, spr* newspr )
// Time complexity is O(1)
// Time complexity for reading the list is O(n)
{
	printf("\n\n%d\n\n",(newspr)->spr_id);

	spr* tspr = NULL ;
    if (*head != NULL)
    {
		tspr = *head;
		*head = newspr ;
		(*head) -> next = tspr;
    }
    return EXIT_SUCCESS ;
}

