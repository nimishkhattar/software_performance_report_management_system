/*
 *      author :- Nimish Khattar
 *      date :- 21-10-2022
 *      description :- Entering Login screen and taking input username and password
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>
void authenticate (spr **defect,user** hashTable)
{
    int i=0,ln;
    char eusername[USERNAME_LEN]; //username of the user
    char epass[PASS_LEN];     
    do{
        system("clear");
        fgetc(stdin);
        printf("Enter username :- ");           // Entering username
        fgets(eusername,USERNAME_LEN-1,stdin);
        ln = strlen(eusername) - 1;
        if (*eusername && eusername[ln] == '\n') 
        eusername[ln] = '\0';
        printf("Enter password :- ");
        fgets(epass,PASS_LEN-1,stdin);
        int ka=searchinhash(hashTable,eusername,epass);
        if(ka==2){
            login(defect,eusername);
            i=1;
        }
        else printf("Wrong Credentials\n");
        // i=1;
        if(i==0){
            printf("Press 0 to try again and 1 to quit :- ");
            scanf("%d",&i);
        }else{
            // fgetc(stdin);
            printf("Enter q\n");
        }
    }while(i==0);
}