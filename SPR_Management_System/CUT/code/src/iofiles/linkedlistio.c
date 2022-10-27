/*
 *      author :- Happy Kamra
 *      date :- 21-10-2022
 *      modified by :- Nimish
 *      description :- taking LinkedList io from the csv file defectslist.csv
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int freeLinkedList(spr** head)
/***************************************************************************************
 This function takes the link list head, iterates through it and frees each structure.
 **************************************************************************************/
{
    spr *iter =  *head;
    spr *temp = NULL ;
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

spr* constructssprStruct(char* line)
/****************************************************************
Takes a comma or " seperated line. Constructs ( allocats ) an
report structure and populates it with the tokens from the line.
Then returns the report structure pointer.
Caller of the function should take care of freeing the pointer.
****************************************************************/
{
    log_trace("Entering function %s", __func__);
    char* token ;
    const char* seperator = "|";

    spr *sprRet = (spr*)malloc (sizeof(spr));

    if ( line == NULL)
        return NULL ;
   token = strtok (line, seperator);
    if ( token != NULL )
    {
        log_info("spr Id is %s", token);
       sprRet->spr_id = atoi(token);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("product Name is %s", token);
        strncpy (sprRet->product, token, PRODUCT_LEN-1);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("creator Name is %s", token);
        strncpy (sprRet->creator, token,CREATOR_LEN-1);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("assignee Name is %s", token);
        strncpy (sprRet->assignee, token, ASSIGNEE_LEN-1);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("severity is %s", token);
        strncpy (sprRet->severity, token, SEVERITY_LEN-1);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("priotity is %s", token);
        strncpy (sprRet->priority, token, PRIORITY_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("status is %s", token);
        strncpy (sprRet->status, token, STATUS_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        strncpy (sprRet->spr_desc, token, SPR_DESC_LEN-1);
        log_info("spr descriptiion is %s", sprRet-> spr_desc);
    }

    return sprRet ;
}

/******************************************************************
    Top level function which takes a filename and a link list head
    and and does the file tasks like opening the file and closing it
    After the file is opened it reads each line and calls constructssprStruct

    which returns the report struct pointer. This is then used to make
    the linked list.
******************************************************************/

int readdefectsfromcsv (spr** head, char* fileName )
{
    spr *newspr = NULL ;
    char sprLine[LINE_SIZE]; // Temp buffer for reading the line
	int count = 0;

    FILE* sprFile = fopen (fileName, "r");
    if (sprFile == NULL )
    {
            printf ("Could not open the file for reading\n");
            return EXIT_FAILURE;
    }

    while (1)
    {
        if (fgets(sprLine, LINE_SIZE, sprFile) == NULL)
            break ;
        newspr =  (spr*)constructssprStruct(sprLine);
        append(head, newspr); // Check for success here  
		count++;
    }

    fclose(sprFile);
    return  count ;
}
int saveToFile(spr* head, char* fileName)
{
    FILE* fp = fopen (fileName, "w");
    spr* defect = head ;
    int countRecords = 0;

    if ( head == NULL ) //|| *head == NULL )
        return EXIT_FAILURE;

    if ( fp == NULL )
        return EXIT_FAILURE;

    while (defect != NULL && defect->spr_id!=0)
    {
        fprintf(fp," %d|%s|%s|%s|%s|%s|%s|%s", defect->spr_id, defect->product, defect->creator, defect->assignee, defect->severity, defect -> priority,  defect->status, defect->spr_desc);

        defect = defect -> next;
        countRecords++ ;
    }

    fclose(fp);

    return countRecords; // Return number of records saved!

}
