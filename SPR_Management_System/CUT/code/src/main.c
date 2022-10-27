/*
 *      author :- Nimish Khattar
 *      date :- 21-10-2022
 *      modified by :- Happy,Sanjeev,Janaki,Sonu
 *      description :- main the welcome screen
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int main(int argc, char** argv)
{
        int choice;
        int total_defects;                      //total defects in our csv file
        char v='1';
        
/*
        ################################
        user data
*/
        user* hashTable[HASHSIZE];
        memset (hashTable, 0, sizeof(user*)*HASHSIZE);
        int usercount = readuserCSVinHashTable(hashTable, "../data/registered_users.csv") ;
        if( usercount == 0)
            {
                printf("Could not read the user file.\n");
            }
        else
        printf ("%d records read from the csv file\n", usercount);

/*
        ################################
        spr data
*/
        spr **defects= (spr**)malloc (sizeof(spr*));
        *defects = NULL ;
        total_defects=readdefectsfromcsv(defects,"../data/defects_list.csv");
        do{
                system("clear");
                printf("Welcome to the software Performance Report Management System.Please select one of the following options.\n");
                printf("\n\t 1. User Login\n");
                printf("\n\t 2. Create a new Defect report \n");
                printf("\n\t 3. Moditfy an existing report \n");    
                printf("\n\t 4. Review the existing report of defects\n");
                printf("\nEnter an option from given choices :- ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                authenticate(defects,hashTable);
                                break;
                        case 2:
                                total_defects+=create_newdefect(defects,"ask");
                                break;
                        case 3:
                                modifydefect(defects);
                                break;
                        case 4:
                                show_defect(defects);
                                break;
                        default:
                                printf("Wrong choice\n");
                                break;

                }
                printf("Do you want to quit the main program (press q to quit, press b to go back):-");
                scanf("%c",&v);
                v=fgetc(stdin);
                
        }
        while(v!='q');
        // printll(*defects);
        saveToFile(*defects,"../data/defects_list.csv");
        
        
        int freedStructures = freeLinkedList(defects);
        // int freedtable = freeLinkedListhl(hashTable);
        log_info("%d Structres freed", freedStructures);
        // log_info("%d Structres freed", freedtable);
        free(defects);
        // log_trace("Exiting function %s", __func__);
        return EXIT_SUCCESS;
}
