#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "loan.h"
#include "loan.c"

int main(){
struct Loan *loans;
int count=0;
int capacity=2;
loans=(struct Loan*)malloc(capacity*sizeof(struct Loan));
if(loans==NULL){
    printf("Memory not Allocated");
    exit(0);
}else{
   while(1){ 
    int menu;
    printf("\n<-><-><-><-> LOAN TRACKER <-><-><-><->\n");
    printf("1.Add Loan\n2.View Loans\n3.Search\n4.Update Loan Status\n5.Delete\n6.Exit\n");
    printf("\nSelect any option:");
    scanf("%d",&menu);

    switch(menu){
        case 1:addLoan(loans,&count);saveLoan(loans,&count);break;
        case 2:viewLoans(loans,&count);break;
        case 3:searchLoanByName(loans);break;
        case 4:markLoanStatus(loans);break;
        case 5:deleteLoan(loans);break;
        case 6:printf("\n*----------------< Thank you >----------------*\n\n\n");exit(0);
    }}
} 

free(loans);
return 0;
}