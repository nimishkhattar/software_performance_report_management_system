/*
 *      author :- Janaki Medisetti
 *      date :- 21-10-2022
 *      modified by :- Nimish Khattar, Happy Kamra
 *      description :- the main screen where the show function 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

void printsprStruct(spr* defect)
/******************************************************************************
 * Takes input an defect structure ( pointer) and prints it contents on screen.
 * Logs are commented as they mess up with formatting
 */
{
   // log_trace("Entering function %s", __func__);

   printf(" |%5d | %7s | %7s | %7s | %9s | %5s | %7s | %s \n", defect->spr_id, defect->product, defect->creator, defect->assignee, defect->severity, defect -> priority,  defect->status, defect->spr_desc);

   // log_trace("Exiting function %s\n", __func__);
}

int filterdefectreport(spr* defectlist,spr* find){
   /******************************************************************************
 * Takes input an defect structure ( pointer) and a filter and print filtered content on screen.
 */
   int count=0;

   while(defectlist){
      if(!strcmp(find->product,"all") || !strcmp(defectlist->product,find->product)){
         printsprStruct(defectlist);
         count++;
      }
      else if(!strcmp(find->creator,"all") || !strcmp(defectlist->creator,find->creator)){
         printsprStruct(defectlist);
         count++;
      }
      else if(!strcmp(find->assignee,"all") || !strcmp(defectlist->assignee,find->assignee)){
         printsprStruct(defectlist);
         count++;
      }
      else if(!strcmp(find->severity,"all") || !strcmp(defectlist->severity,find->severity)){
         printsprStruct(defectlist);
         count++;
      }
      else if(!strcmp(find->priority,"all") || !strcmp(defectlist->priority,find->priority)){
         printsprStruct(defectlist);
         count++;
      }
      else if(!strcmp(find->status,"all") || !strcmp(defectlist->status,find->status)){
         printsprStruct(defectlist);
         count++;
      }
      defectlist=defectlist->next;
   }
   return count;
}
void printll(spr *defects){
   // qsort(defects, 3, sizeof(spr), cmpfunc);
   while(defects){
          printsprStruct(defects);
          defects=defects->next;
   }
}

