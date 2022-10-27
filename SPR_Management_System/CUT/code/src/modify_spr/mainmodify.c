/*
 *      author :- Sanjeev Yadav
 *      date :- 21-10-2022
 *      modified by :- Nimish
 *      description :- This file is the main modification screen
 *                      and take the modified input and assign it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

void makemodification(spr* newspr){
    int k,n; 
    char v='1';
    printf("Select the parameter you want to modify :- \n");
    printf("\t1. Product Name\n");
    printf("\t2. Creator's Name\n");
    printf("\t3. Assignee's Name\n");
    printf("\t4. Severity \n");    
    printf("\t5. Priority \n");
    printf("\t6. Status \n");
    printf("\t7. description \n");
    do{
        printf("Enter your choice :- ");
        scanf("%d",&k);
        switch(k){
            case 1:
            fgetc(stdin);
                printf("Enter the Name of the project :- ");
                fgets(newspr->product,PRODUCT_LEN-1,stdin);
                int ln = strlen(newspr->product) - 1;
                if (*newspr->product && newspr->product[ln] == '\n') 
                newspr->product[ln] = '\0';
                break;
            case 2:
            fgetc(stdin);
                printf("Enter the name of the creator :- ");
                fgets(newspr->creator,CREATOR_LEN-1,stdin);
                ln = strlen(newspr->creator) - 1;
                if (*newspr->creator && newspr->creator[ln] == '\n') 
                newspr->creator[ln] = '\0';
                break;
            case 3:
            fgetc(stdin);
                printf("Enter the name of the assignee :- ");
                fgets(newspr->assignee,ASSIGNEE_LEN-1,stdin);
                ln = strlen(newspr->assignee) - 1;
                if (*newspr->assignee && newspr->assignee[ln] == '\n') 
                newspr->assignee[ln] = '\0';
                break;
            case 4:
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

                break;
            case 5:
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
                break;
            case 6:
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
                break;
            case 7:
            fgetc(stdin);
                printf("Enter the description of the report :- ");
                fgets(newspr->spr_desc,SPR_DESC_LEN-1,stdin);
                ln = strlen(newspr->spr_desc) - 1;
                if (*newspr->spr_desc && newspr->spr_desc[ln] == '\n') 
                newspr->spr_desc[ln] = '\0';
                break;
            default:
                printf("Wrong choice\n");
                break;

        }

        printf("Do you want to modify another parameter? (press y to continue):-");
        // scanf("%c",&v);
        v=fgetc(stdin);

    }while(v=='y');



}

void modifydefect(spr **defect)
{
    // printll(*defect);
        char v='1';        
        do{
            system("clear");
            printf("Modifying a report....\n");
            int sprid;
            printf("Enter the spr id you want to modify :- ");
            scanf("%d",&sprid);
            spr * modspr=searchsprid(*defect,sprid);
            if(modspr==NULL){
                printf("Defects not found\n");
            }
            else{
                printsprStruct(modspr);
                makemodification(modspr);
                printsprStruct(modspr);
                printf("Report Modified Successfully.\n\n");
            }
            printf("Do you want to modify another report ? (press y to continue):-");
            v=fgetc(stdin);
            scanf("%c",&v);

        }
        while(v=='y');
}
