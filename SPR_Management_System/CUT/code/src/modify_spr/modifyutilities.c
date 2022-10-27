/*
 *      author :- Sanjeev Yadav
 *      date :- 21-10-2022
 *      modified by :- Nimish Khattar
 *      description :- modify defect search utility
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

spr* searchsprid(spr* defect,int sprid)
/******************************************************************************
 * Takes input an defect id integer and return the node if found.
 */
{

   while(defect){
      if(defect->spr_id==sprid)
         return defect;
          defect=defect->next;
   }
   return NULL;

}