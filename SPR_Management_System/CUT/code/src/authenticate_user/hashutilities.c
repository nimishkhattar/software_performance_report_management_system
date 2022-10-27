/*
 *      author :- Nimish Khattar
 *      date :- 21-10-2022
 *      description :- main the welcome screen
 * 					This file contain all the utilities for for the hashtable
 * 					appendkl
 * 					freelinkedlisthl
 * 					hashfunction
 * 					addusertohashfunction 
 * 					constructsuserStruct
 * 					readuserCSVinHashTable
 * 					freehashTable
 * 					searchinhash
 */
#include <stdio.h>
#include <main.h>
#include <stdlib.h>
#include <log.h>
#include <struct.h>
#include <string.h>
int appendhl ( user** head, user* newuser )
// Time complexity is O(n)
// Time complexity for reading the list is O(n*(n+1)/2) = O(n^2)
{
	user* iter = *head ;
	if (*head == NULL)
		*head =  newuser ;
	else
	{
		while ( iter -> next != NULL)
		{
			iter = iter -> next ;
		}
		iter -> next = newuser ;
		newuser -> next = NULL ;
	}		
	return EXIT_SUCCESS;
}
int freeLinkedListhl(user** head)
/***************************************************************************************
 This function takes the link list head, iterates through it and frees each structure.
 **************************************************************************************/
{
    user *iter =  *head;
    user *temp = NULL ;
    int freeCount = 0;

    while (iter != NULL )
    {
        temp = iter ;
        iter = iter ->next ;
        free ( temp);
        freeCount++;
    }
    *head = NULL ;
    return freeCount;
}
static int hashFunction (char* key)
{
	int h = 0;
	while ( *key )
		h += *key++ ;
	return abs ( h % HASHSIZE );
}

void adduserToHashTable ( user** hashTable, user* newuser)
{
	int index = hashFunction (newuser -> username);
	appendhl (&hashTable[index], newuser );
	if (hashTable[index] != 0)
	{
		log_info ("Collision detected!\n");
	}
}
static user* constructsuserStruct(char* line)
/****************************************************************
Takes a comma or " seperated line. Constructs ( allocats ) an
user structure and populates it with the tokens from the line.
Then returns the user structure pointer.
Caller of the function should take care of freeing the pointer.
****************************************************************/
{
    log_trace("Entering function %s", __func__);
    char* token ;
    const char* seperator = "|";

    user *userRet = (user*)malloc (sizeof(user));

    if ( line == NULL)
        return NULL ;
   token = strtok (line, seperator);
    if ( token != NULL )
    {
        log_info("user Id is %s", token);
       userRet->userid = atoi(token);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("user name is %s", token);
        strncpy (userRet->username, token, USERNAME_LEN-1);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("password is %s", token);
        strncpy (userRet->pass, token,PASS_LEN-1);
    }

    return userRet ;
}
int readuserCSVinHashTable(user** hashTable, char* fileName)
{
	user *newuser = NULL ;
    char userdataline[LINE_SIZE]; // Temp buffer for reading the line
    int count = 0;

    FILE* userdatafile = fopen (fileName, "r");
    if (userdatafile == NULL )
    {
            printf ("Could not open the file for reading\n");
            return EXIT_FAILURE;
    }

    while (1)
    {
        if (fgets(userdataline, LINE_SIZE, userdatafile) == NULL)
            break ;

        newuser =  (user*)constructsuserStruct(userdataline);
		adduserToHashTable ( hashTable, newuser);
        count++;
    }

    fclose(userdatafile);
    return  count ;
}	

int freehashTable(user** hashTable)
{
	int count = 0;
	for (int i = 0; i < HASHSIZE; i++)
	{
	    if (hashTable[i] != NULL )
			count += freeLinkedListhl(&hashTable[i]);
	}
	return count;	
}

void printHashTable ( user** hashTable)
{
	for ( int i = 0; i < HASHSIZE; i++)
	{
		user* iter = NULL ;

		if (hashTable[i] != NULL )
		{
			// print the linked list in single line.
			printf ( "hashbucket [%2d] : " , i);
			iter = hashTable[i] ;
			while ( iter != NULL )
			{
				printf ("|%8d %10s| -> ", iter -> userid, iter -> username);
				iter = iter -> next;
			}
			printf (" NULL\n");
		}  
		else
			printf("hashbucket [%2d] : -> NULL\n" , i);
	}
}

int searchinhash ( user** hashTable,char* eusername,char* epass)
{
	printf("%s",eusername);
	printf("%s",epass);
	int i=hashFunction (eusername);
	{
		user* iter = NULL ;

		if (hashTable[i] != NULL )
		{
			// print the linked list in single line.
			iter = hashTable[i] ;
			while ( iter != NULL )
			{
				if(!strcmp(iter -> username,eusername) && !strcmp(iter -> pass,epass)){
					return 2;
				}
				iter = iter -> next;
			}
		}  
	}
	return 0;
}
