#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>


// Forward declarations of the functions
extern int readdefectsfromcsv (spr** head, char* fileName );
extern int prepend ( spr** head, spr* newspr );
extern int append ( spr** head, spr* newspr );
extern int freeLinkedList(spr** head);
extern void printsprStruct(spr* defect);
extern spr* constructssprStruct(char* line);
extern void printll(spr * defects);
extern spr* searchsprid(spr* defects,int sprid);
extern int filterdefectreport(spr* defectlist,spr* find);
extern int create_newdefect(spr **defect, char* username);
extern void modifydefect();
extern void authenticate (spr **defect,user** hashTable);
extern int searchinhash ( user** hashTable,char* eusername,char* epass);
extern int login(spr ** defects,char* username);
extern int show_defect(spr **defect);
extern int filterdefectreport(spr* defectlist,spr* find);
extern int saveToFile(spr* head, char* fileName);
extern int freeLinkedListhl(user** head);


// HashTable related functions
extern int freehashTable(user**);
extern int readuserCSVinHashTable(user** hashTable, char* fileName);
extern void printHashTable ( user** hashTable);

//


#endif
