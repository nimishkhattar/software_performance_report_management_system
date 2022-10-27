/*
 *      author :- Sonu
 *      date :- 21-10-2022
 *      modified by :- Nimish
 *      description :- main the welcome screen
 *      This file is the main creation screen for the function
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

spr* takeinput(char* username){
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    spr **spridd= (spr**)malloc (sizeof(spr*));
    *spridd = NULL ;
    readdefectsfromcsv(spridd,"../data/spriddata.csv");   
    newspr->spr_id=(*spridd)->spr_id++;
    saveToFile(*spridd,"../data/spriddata.csv");
        

    fgetc(stdin);
    printf("Enter the Name of the project :- ");
    fgets(newspr->product,PRODUCT_LEN-1,stdin);
    int ln = strlen(newspr->product) - 1;
    if (*newspr->product && newspr->product[ln] == '\n') 
    newspr->product[ln] = '\0';

    if(!strcmp(username,"ask")){
        printf("Enter the name of the creator :- ");
        fgets(newspr->creator,CREATOR_LEN-1,stdin);
        ln = strlen(newspr->creator) - 1;
        if (*newspr->creator && newspr->creator[ln] == '\n') 
        newspr->creator[ln] = '\0';
    }
    else {
        strncpy (newspr->creator, username, CREATOR_LEN -1);
    }
        printf("Enter the name of the assignee :- ");
        fgets(newspr->assignee,ASSIGNEE_LEN-1,stdin);
        ln = strlen(newspr->assignee) - 1;
        if (*newspr->assignee && newspr->assignee[ln] == '\n') 
        newspr->assignee[ln] = '\0';

        int n;
        printf("\nSelect the severity:- ");
        printf("\n\t1. Enhancement   \n\t2. Server Defect   \n\t3. Defect  \n\t4. UI issue   \n\t5. Nuisance");
        do{
            printf("\nEnter the severity:- ");
            scanf("%d",&n);
            switch(n){
                case 1:
                    strncpy (newspr->severity,"Enhancement", SEVERITY_LEN -1);
                    break;
                case 2:
                    strncpy (newspr->severity, "Server Defect", SEVERITY_LEN -1);
                    break;
                case 3:
                    strncpy (newspr->severity, "Defect", SEVERITY_LEN -1);
                    break;
                case 4:
                    strncpy (newspr->severity, "UI issue", SEVERITY_LEN -1);
                    break;
                case 5:
                    strncpy (newspr->severity, "Nuisance", SEVERITY_LEN -1);
                    break;
                default:
                    printf("Wrong choice\n");
                    break;
            }
        }while(n>5);

        printf("\nSelect the priority:- ");
        printf("\n\t1. Top   \n\t2. High   \n\t3. Medium  \n\t4. Low");
        do{
            printf("\nEnter the priority:- ");
            scanf("%d",&n);
            switch(n){
                case 1:
                    strncpy (newspr->priority,"Top", PRIORITY_LEN -1);
                    break;
                case 2:
                    strncpy (newspr->priority, "High", PRIORITY_LEN -1);
                    break;
                case 3:
                    strncpy (newspr->priority, "Medium", PRIORITY_LEN -1);
                    break;
                case 4:
                    strncpy (newspr->priority, "Low", PRIORITY_LEN -1);
                    break;
                default:
                    printf("Wrong choice\n");
                    break;
            }
        }while(n>4);

        printf("\nSelect the status:- ");
        printf("\n\t1. Idle   \n\t2. Active   \n\t3. Inactive");
        do{
            printf("\nEnter the status:- ");
            scanf("%d",&n);
            switch(n){
                case 1:
                    strncpy (newspr->status,"Idle", STATUS_LEN -1);
                    break;
                case 2:
                    strncpy (newspr->status, "Active", STATUS_LEN -1);
                    break;
                case 3:
                    strncpy (newspr->status, "Inactive", STATUS_LEN -1);
                    break;
                default:
                    printf("Wrong choice\n");
                    break;
            }
        }while(n>3);

        fgetc(stdin);
        printf("Enter the description of the report :- ");
        fgets(newspr->spr_desc,SPR_DESC_LEN-1,stdin);
        printf("\n");
        return newspr;

}

int create_newdefect(spr **defect, char* username)
{

        char v='1';
        int count=0;
        do{
            printf("Creating a new defect report....\n");
            spr * newspr=takeinput(username);
            append(defect,newspr);
            printf("New defect Added successfully.Press Enter to Continue.\n\n");
            printsprStruct(newspr);
            fgetc(stdin);
            printf("Do you want to add another report ? (press y to continue):-");
            scanf("%c",&v);
            // v=fgetc(stdin);
            system("clear");
            count++;
        }
        while(v=='y');
    log_trace("Exiting function %s", __func__);
        // return EXIT_SUCCESS;
    return count;
}