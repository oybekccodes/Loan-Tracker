#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "loan.h"
#include<ctype.h>

 void addLoan(struct Loan *loans,int *count) {
    struct Loan *l = &loans[*count];
    int choice;

    printf("\n1. Borrowing Money\n2. Lending Money\n");
    printf("* Please enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n<=== Add Loan (Borrowing) ===>\n");
    } else if (choice == 2) {
        printf("\n<=== Add Loan (Lending) ===>\n");
    } else {
        printf("Invalid choice! Please enter 1 or 2.\n");
        return;
    }
    printf("\n* Enter(Lent or Borrowed)again: ");
    scanf("%s",loans->type);

    printf("* Create an ID: ");
    scanf("%d", &loans->id);
    while (getchar() != '\n');

    printf("* Name: ");
    fgets(loans->name, sizeof(loans->name), stdin);

    printf("* Enter the amount: ");
    scanf(" %f", &loans->amount);

    printf("* Currency: ");
    scanf("%s",loans->currency);
    while (getchar() != '\n');

    printf("* Date: ");
    fgets(loans->date, sizeof(loans->date), stdin);

    printf("* Due Date: ");
    fgets(loans->due_date, sizeof(loans->due_date), stdin);

    printf("* Status (Paid/Unpaid): ");
    fgets(loans->status, sizeof(loans->status), stdin);

    printf("\n*------------< %s money added successfully! >------------*\n",loans->type);
    (*count)++;
}

void saveLoan(struct Loan *loans,int *count){

    FILE *ptr;
    ptr=fopen("loans.txt","a");
    if(ptr==NULL){
        printf("\nData has not been saved !!");
    }else{
        struct Loan l;
    fprintf(ptr,
    "Type: %s\n"
    "Id: %d\n"
    "Name: %s"
    "Amount: %.2f\n"
    "Currency: %s\n"
    "Date: %s"
    "Due Date: %s"
    "Status: %s\n",
     loans->type,loans->id, loans->name, loans->amount, loans->currency, loans->date, loans->due_date, loans->status);

    fclose(ptr);
    }
    (*count)++;
}

void viewLoans(struct Loan *loans,int *count) {
    FILE *ptr = fopen("loans.txt", "r");
    if (ptr == NULL) {
        printf("\nFailed to open file!\n");
        return;
    }
    int found=0;
    struct Loan l;
    printf("\n<-=-=-= Borrowed and Lent money transaction details =-=-=->\n\n");
    while (fscanf(ptr,
        "Type: %[^\n]\n"
        "Id: %d\n"
        "Name: %[^\n]\n"
        "Amount: %f\n"
        "Currency: %[^\n]\n"
        "Date: %[^\n]\n"
        "Due Date: %[^\n]\n"
        "Status: %[^\n]\n\n",
        l.type, &l.id, l.name, &l.amount,
        l.currency, l.date, l.due_date, l.status
    ) == 8) {
        printf("Type: %s\nId: %d\nName: %s\nAmount: %.2f\nCurrency: %s\nDate: %s\nDue Date: %s\nStatus: %s\n\n",
            l.type, l.id, l.name, l.amount,
            l.currency, l.date, l.due_date, l.status);
       found=1; 
    }
    if(!found){
    printf("\n<<========| There is no Loans to show !! |========>>\n");
   } 
    fclose(ptr);
}

void searchLoanByName(struct Loan *loans){
    FILE *ptr = fopen("loans.txt", "r");
    if (ptr == NULL) {
        printf("Failed to open file!\n");
        return;
    }
    struct Loan l;
    char name[50];
    int found=0;
    printf("\n*Enter the name of the person you want to SEARCH: ");
    scanf(" %[^\n]",name);
     while (fscanf(ptr,
        "Type: %[^\n]\n"
        "Id: %d\n"
        "Name: %[^\n]\n"
        "Amount: %f\n"
        "Currency: %[^\n]\n"
        "Date: %[^\n]\n"
        "Due Date: %[^\n]\n"
        "Status: %[^\n]\n\n",
        l.type, &l.id, l.name, &l.amount,
        l.currency, l.date, l.due_date, l.status
    )==8){

    if(strcasecmp(l.name,name)==0){
        printf("\n<*><*><*> %s is found <*><*><*>\n\n",name);
         printf("Type: %s\nId: %d\nName: %s\nAmount: %.2f\nCurrency: %s\nDate: %s\nDue Date: %s\nStatus: %s\n\n",
            l.type, l.id, l.name, l.amount,l.currency, l.date, l.due_date, l.status);
         }  
         found=1;
}
if(!found){
    printf("\n%s is NOT FOUND !!",name);
}
    fclose(ptr);
}


void deleteLoan(struct Loan *loans){
       FILE *ptr = fopen("loans.txt", "r");
       FILE *tmp = fopen("temp.txt","w");
    if (ptr == NULL) {
        printf("\nFailed to open file!\n");
        return;
    }
    struct Loan l;
    int id;
    int deleted=0;
    printf("\n * Enter the ID of the person you want to DELETE: ");
    scanf("%d",&id);
     while (fscanf(ptr,
        "Type: %[^\n]\n"
        "Id: %d\n"
        "Name: %[^\n]\n"
        "Amount: %f\n"
        "Currency: %[^\n]\n"
        "Date: %[^\n]\n"
        "Due Date: %[^\n]\n"
        "Status: %[^\n]\n\n",
        l.type, &l.id, l.name, &l.amount,
        l.currency, l.date, l.due_date, l.status
    )==8){
     if(l.id==id){
        deleted=1;
        continue;
      }

     if(l.id!=id){
      fprintf(tmp,
            "Type: %s\n"
            "Id: %d\n"
            "Name: %s\n"
            "Amount: %.2f\n"
            "Currency: %s\n"
            "Date: %s\n"
            "Due Date: %s\n"
            "Status: %s\n\n",
            l.type, l.id, l.name, l.amount,
            l.currency, l.date, l.due_date, l.status);
        }
    }

    if(deleted){
        remove("loans.txt");
        rename("temp.txt","loans.txt");
        printf("\n*-------< %d id is REMOVED Succesfully >-------*\n",id);
    }else{
        remove("temp.txt");
        printf("\n\n<<========| There is no Loans to delete !! |========>>\n\n");
    }
    fclose(ptr);
    fclose(tmp);
}

void markLoanStatus(struct Loan *loans){
     FILE *ptr = fopen("loans.txt", "r");
     FILE *temp= fopen("temp.txt","w");
    if (ptr == NULL || temp==NULL) {
        printf("Failed to open file!\n");
        return;
    }
    struct Loan l;
    int found=0,key,searchid;
    printf("\nUpdating Loan status...\n");
    printf("\nEnter Loan ID to update status: ");
    scanf("%d",&searchid);

     while (fscanf(ptr,
        "Type: %[^\n]\n"
        "Id: %d\n"
        "Name: %[^\n]\n"
        "Amount: %f\n"
        "Currency: %[^\n]\n"
        "Date: %[^\n]\n"
        "Due Date: %[^\n]\n"
        "Status: %[^\n]\n\n",
        l.type, &l.id, l.name, &l.amount,
        l.currency, l.date, l.due_date, l.status
    )==8){
            if(l.id==searchid){
                found=1;
                printf("\n1.PAID\n2.UNPAID\n");
                printf("Select the new status above ⬆️ : ");
                scanf("%d",&key);
                switch(key){
                case 1:printf("\nStatus is changed to PAID !!\n");
                        strcpy(l.status,"Paid");
                        break;
                case 2:printf("\n*<-----+----->| Status is changed to UNPAID !! | <-----+----->*\n");
                        strcpy(l.status,"Unpaid");
                        break;
                }   
            }  
        }
    
    fprintf(temp,
        "Type: %s\n"
        "Id: %d\n"
        "Name: %s\n"
        "Amount: %f\n"
        "Currency: %s\n"
        "Date: %s\n"
        "Due Date: %s\n"
        "Status: %s\n\n",
        l.type, l.id, l.name, l.amount,
        l.currency, l.date, l.due_date, l.status );
    
    fclose(ptr);
    fclose(temp);

    if(!found){
        printf("\nLoan Id is not found\n\n");
    }else{
        remove("loans.txt");
        rename("temp.txt","loans.txt");
    }    
}


