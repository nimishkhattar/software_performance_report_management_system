/*
 *      author :- Janaki Medisetti
 *      date :- 21-10-2022
 *      modified by :- Nimish Khattar
 *      description :- the main screen for the show function taking in the filter.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h> 

spr* viewall(){
    printf("All the data is shown here:\n");
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "all", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"all", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "all", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"all", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "all", PRIORITY_LEN -1);
    strncpy (newspr -> status, "all", STATUS_LEN -1);
    return newspr;
 }

spr* viewproduct(){
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "a", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"a", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "a", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"a", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "a", PRIORITY_LEN -1);
    strncpy (newspr -> status, "a", STATUS_LEN -1);
        fgetc(stdin);

    printf("Enter the product whose defect you want to see :- ");
    fgets(newspr->product,PRODUCT_LEN-1,stdin);
    int ln = strlen(newspr->product) - 1;
    if (*newspr->product && newspr->product[ln] == '\n') 
    newspr->product[ln] = '\0';
    return newspr;
 }

spr* viewcreator(){

    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "a", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"a", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "a", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"a", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "a", PRIORITY_LEN -1);
    strncpy (newspr -> status, "a", STATUS_LEN -1);
    fgetc(stdin);
    printf("Enter the creator's name whose defect you want to see :- ");
    fgets(newspr->creator,CREATOR_LEN-1,stdin);
    int ln = strlen(newspr->creator) - 1;
    if (*newspr->creator && newspr->creator[ln] == '\n') 
    newspr->creator[ln] = '\0';
    return newspr;
 }

spr* viewassignee(){
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "a", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"a", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "a", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"a", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "a", PRIORITY_LEN -1);
    strncpy (newspr -> status, "a", STATUS_LEN -1);
    fgetc(stdin);
    printf("Enter the assignee name whose defect you want to see :- ");
    fgets(newspr->assignee,ASSIGNEE_LEN-1,stdin);
    int ln = strlen(newspr->assignee) - 1;
        if (*newspr->assignee && newspr->assignee[ln] == '\n') 
        newspr->assignee[ln] = '\0';
    return newspr;
 }

spr* viewseverity(){
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "a", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"a", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "a", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"a", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "a", PRIORITY_LEN -1);
    strncpy (newspr -> status, "a", STATUS_LEN -1);
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
    return newspr;

}   

spr* viewpriority(){
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "a", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"a", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "a", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"a", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "a", PRIORITY_LEN -1);
    strncpy (newspr -> status, "a", STATUS_LEN -1);
    int n;
    printf("which type of priority you want to see :\n");
    printf("\n\t1. Top   \n\t2. High   \n\t3. Medium  \n\t4. Low");
    printf("Enter your choice :- ");
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
    return newspr;
}


spr* viewstatus(){
    spr* newspr = (spr*)calloc (1, sizeof(spr));
    strncpy (newspr -> product, "a", PRODUCT_LEN-1);
    strncpy (newspr -> creator,"a", CREATOR_LEN-1);
    strncpy (newspr -> assignee, "a", ASSIGNEE_LEN-1);
    strncpy (newspr -> severity,"a", SEVERITY_LEN-1);
    strncpy (newspr -> priority, "a", PRIORITY_LEN -1);
    strncpy (newspr -> status, "a", STATUS_LEN -1);
    int n;
    printf("which type of status of a defect you want to select :\n");
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
    return newspr;
}

int show_defect(spr **defect)
{        
        int answer;
        spr* newspr = (spr*)calloc (1, sizeof(spr));
        printf("which filter you want to use?\n");
        printf("\t1. Show all defects\n \t2. Filter according to product\n \t3. Filter according to creator\n \t4. Filter according to assignee\n \t5. Filter according to severity\n \t6. Filter according to priority\n \t7. Filter according to status\n");
        printf("Enter your choice :- ");
        do{
        scanf("%d",&answer);
        switch (answer){
            case 1 :
                newspr=viewall();
                break;
            case 2 :
                newspr=viewproduct();
                break;
            case 3 :
                newspr=viewcreator();
                break;
            case 4 :
                newspr=viewassignee();
                break;
            case 5 :
                newspr=viewseverity();
                break;
            case 6 :
                newspr=viewpriority();
                break;
            case 7 :
                newspr=viewstatus();
                break;
            default:
                printf("Wrong choice\n");
                break;   
            } 

        }while(answer>7);
        printf("Filterd data ... \n\n ");
        printf("|spr_id| product | creator | assignee | severity | priority | status | spr_desc\n");
        int number_of_passed_data=filterdefectreport(*defect,newspr);
        printf("\nTotal number of defects found with the filter:- %d\n",number_of_passed_data);
                fgetc(stdin);

        return number_of_passed_data;
     


}
        
