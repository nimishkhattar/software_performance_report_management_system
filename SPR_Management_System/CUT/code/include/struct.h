#pragma once
#define PRODUCT_LEN 100
#define CREATOR_LEN  100
#define ASSIGNEE_LEN 100
#define SEVERITY_LEN 100
#define PRIORITY_LEN 50
#define STATUS_LEN 50
#define SPR_DESC_LEN 200
#define USERNAME_LEN 200
#define PASS_LEN 100
#define LINE_SIZE 2000
#define HASHSIZE 100

typedef struct _spr_
{
  int spr_id;//software Performance id
  char product[PRODUCT_LEN];//owner of  product(who  buy the product)
  char creator[CREATOR_LEN];//who is logged into spr and creating a new SPR 
  char assignee[ASSIGNEE_LEN];//who is fixing the issues in the SPR
  char severity[SEVERITY_LEN];//Enhancement   Server Defect   Defect  UI issue   Nuisance
  char priority[PRIORITY_LEN];// Top   High  Medium Low
  char status[STATUS_LEN]; //Idle  Active  Inactive
  char spr_desc[SPR_DESC_LEN];
  
    struct _spr_* next;
} spr;

typedef struct _user_
{
	int userid;  //a unique userid of the user 
  char username[USERNAME_LEN]; //username of the user
	char pass[PASS_LEN];  //password assigned to user for login
    struct _user_* next;
} user;

