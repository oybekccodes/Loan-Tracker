# 📘 Loan Tracker (C Project)

A console-based **Loan Management System** built using the **C programming language**.  
This project allows users to **add, view, search, delete, and update loan records**, while also tracking loan status and storing data using **file handling and structures**.

---

## 🎯 Project Objective

To build a real-world C application that demonstrates:

✔ File Handling  
✔ Structures  
✔ Dynamic Memory Allocation  
✔ Modular Programming  
✔ Data Management (Insert, Search, Update, Delete)

---

## ✨ Main Features

### ➕ 1. Add Loan Record
- At first, you need select either Borrowing or Lending.
- Enter borrower id,borrower name, loan amount, Currency,data,due date, and loan status.
- Stores record in file permanently.

### 👀 2. View All Loans
- Displays all loan entries in a formatted table.
- Reads data from `loans.txt`.

### 🔍 3. Search Loan
- Search a specific loan using Borrower Name.
- Displays complete loan details.

### ✏️ 4. Update Loan Status
- Modify only the Loan status (Paid or Unpaid)
- Stores updated status in file permanently. 

### ❌ 5. Delete Loan Record
- Remove a loan entry from the file.
- Safely rewrites remaining records.

---

## 🛠️ Concepts Used

| Concept | Description |
|--------|-------------|
| Structures | To store borrower and loan details |
| File Handling | Permanent data storage |
| Dynamic Memory | For scalable record storage |
| Functions & Modularity | Organized code (multiple .c and .h files) |
| Conditional Logic | Menu-based system |
| Loops & Validation | Repeated safe user input |

---

## 📂 Project Structure

│── main.c # Menu and program control
│── loans.c # Add, view, search, update, delete functions, File reading and writing
│── loans.h # Function declarations
│── loans.txt # Data storage file
│── README.md # Project documentation


---

## 📊 Sample Stored Data Format

Type: Borrow
Id: 1001
Name: Usman
Amount: 100.000000
Currency: $
Date: Ocotober 20
Due Date: December 20
Status: Paid


---

## 🧪 Compilation & Run

### Compile:

gcc main.c loans.c -o main
./main

## 🚀 Future Enhancements
🔹 EMI auto-calculation
🔹 Admin login system
🔹 Export records to CSV
🔹 Colorful UI and progress bars
🔹 Use binary file storage


👤 Project Author
Student Developer: Oybek
Language: C
Type: File Handling + Data Management Project

📝 License
This project is open-source for learning and academic use.

💡 “Tracking loans made simpler — powered by C.”

---
