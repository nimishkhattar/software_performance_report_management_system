/*
 *      author :- Nimish Khattar
 *      date :- 21-10-2022
 *      description :- main the welcome screen in case if user login successfully
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int login(spr ** defects,char* username)
{
        int choice;
        int total_defects;
        char v='1';
        do{
                system("clear");
                printf("Welcome %s to the software Performance Report Management System.Please select one of the following options.\n",username);
                printf("\n\t 1. Create a new Defect report \n");
                printf("\n\t 2. Moditfy an existing report \n");    
                printf("\n\t 3. Review the existing report of defects\n");
                printf("\nEnter an option from given choices :- ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                total_defects+=create_newdefect(defects,username);
                                break;
                        case 2:
                                modifydefect(defects);
                                break;
                        case 3:
                                show_defect(defects);
                                break;
                        default:
                                printf("Wrong choice\n");
                                break;

                }
                printf("If you want to logout press q :- ");
                scanf("%c",&v);
                v=fgetc(stdin);
                
        }
        while(v!='q');
        
        
        // int freedStructures = freeLinkedList(defects);
    // log_info("%d Structres freed", freedStructures);

    // log_trace("Exiting function %s", __func__);
        return EXIT_SUCCESS;
}
