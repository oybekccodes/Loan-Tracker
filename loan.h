#ifndef LOAN_H
#define LOAN_H

struct Loan {
    int id;
    char name[50];
    float amount;
    char currency[10];
    char type[20];
    char date[20];
    char due_date[20];
    char status[10];

};

// --- Function prototypes ---
void addLoan(struct Loan *loans,int *count);
void saveLoans(struct Loan *loans,int *count);
void viewLoans(struct Loan *loans,int *count);
void searchLoanByName(struct Loan *loans);
void markLoanStatus(struct Loan *loans);
void deleteLoan(struct Loan *loans);
#endif
