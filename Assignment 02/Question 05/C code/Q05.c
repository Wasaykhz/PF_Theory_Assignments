/*
Program: University Library Management System
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
Dated: November 05, 2026
*/


#include <stdio.h>

// Displays all menu options
void displayMenu()
{
    printf("\n===== UNIVERSITY LIBRARY =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Inputs the member's details (name must be one word, e.g. Ali_Khan)
void registerMember(char name[], int *studentID, int *memberType)
{
    printf("Enter name (no spaces): ");
    scanf("%s", name);
    printf("Enter student ID: ");
    scanf("%d", studentID);
    printf("Enter membership type (1 = Student, 2 = Faculty): ");
    scanf("%d", memberType);

    while (*memberType != 1 && *memberType != 2)    // keep asking until valid
    {
        printf("Invalid type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", memberType);
    }
    printf("Member registered successfully.\n");
}

// Displays all books in a table
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks)
{
    int i;

    printf("\n%-6s %-25s %s\n", "ID", "Title", "Copies");
    printf("------------------------------------------\n");
    for (i = 0; i < totalBooks; i++)
    {
        printf("%-6d %-25s %d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

// Borrows a book if the ID is valid, a copy is available and the limit is not reached
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount, int memberType)
{
    int id, days, i;
    int index = -1;                 // position of the book in the inventory
    int allowed;                    // permitted days for this member

    if (*borrowedCount >= 3)        // maximum of three books at a time
    {
        printf("You have already borrowed 3 books. Return one first.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++)    // search the book ID
    {
        if (bookIDs[i] == id)
            index = i;
    }

    if (index == -1)
    {
        printf("Invalid book ID.\n");
        return;
    }
    if (availableCopies[index] == 0)
    {
        printf("Sorry, no copies of '%s' are available.\n", bookTitles[index]);
        return;
    }

    printf("Enter number of days you want to keep the book: ");
    scanf("%d", &days);
    if (days <= 0)                  // days must be positive
    {
        printf("Number of days must be positive.\n");
        return;
    }

    if (memberType == 1)
        allowed = 14;
    else
        allowed = 30;

    if (days > allowed)
        printf("Note: allowed period is %d days. A fine applies after that.\n", allowed);

    // record the borrowing and reduce the stock
    borrowedBookIDs[*borrowedCount] = id;
    (*borrowedCount)++;
    availableCopies[index]--;
    printf("Book borrowed successfully.\n");
}

// Returns a book, calculates the fine and returns the fine payable for this return
float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine)
{
    int id, days, i;
    int bookIndex = -1;             // position in inventory
    int borrowPos = -1;             // position in the borrowed list
    int allowed, rate, extra;
    float fine = 0;
    char code[20];
    char correct[] = "LIB2026";
    int same;                       // 1 if the entered code matches

    printf("Enter book ID to return: ");
    scanf("%d", &id);
    printf("Enter actual number of days the book was kept: ");
    scanf("%d", &days);

    if (days <= 0)                  // days must be positive
    {
        printf("Number of days must be positive.\n");
        return 0;
    }

    for (i = 0; i < *borrowedCount; i++)    // verify the member borrowed this book
    {
        if (borrowedBookIDs[i] == id)
            borrowPos = i;
    }
    if (borrowPos == -1)
    {
        printf("You have not borrowed this book.\n");
        return 0;
    }

    for (i = 0; i < totalBooks; i++)        // find the book in the inventory
    {
        if (bookIDs[i] == id)
            bookIndex = i;
    }
    availableCopies[bookIndex]++;           // copy comes back to the library

    // permitted days and fine rate depend on the membership type
    if (memberType == 1)
    {
        allowed = 14;
        rate = 20;
    }
    else
    {
        allowed = 30;
        rate = 10;
    }

    if (days > allowed)             // late return
    {
        extra = days - allowed;
        fine = extra * rate;
        printf("Late return by %d days. Fine: Rs. %.2f\n", extra, fine);
        *totalFine = *totalFine + fine;     // fine before waiver

        printf("Enter membership code (or any word to skip): ");
        scanf("%19s", code);

        // compare the entered code with LIB2026 character by character
        same = 1;
        i = 0;
        while (code[i] != '\0' || correct[i] != '\0')
        {
            if (code[i] != correct[i])
                same = 0;
            i++;
        }

        if (same == 1)
        {
            fine = fine / 2;        // 50% waiver
            printf("Code accepted. 50%% waiver applied. Fine payable: Rs. %.2f\n", fine);
        }
        else
        {
            printf("Incorrect code. No waiver. Fine payable: Rs. %.2f\n", fine);
        }
    }
    else
    {
        printf("Returned on time. No fine.\n");
    }

    // remove the book from the borrowed list by shifting the later items left
    for (i = borrowPos; i < *borrowedCount - 1; i++)
    {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;

    return fine;
}

// Displays the member's details and borrowing record
void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[],
                         int borrowedCount, float totalFine, float fineAfterWaiver)
{
    int i;

    printf("\n===== MEMBER RECORD =====\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    if (memberType == 1)
        printf("Membership: Student\n");
    else
        printf("Membership: Faculty\n");

    printf("Currently borrowed books: ");
    if (borrowedCount == 0)
    {
        printf("None");
    }
    for (i = 0; i < borrowedCount; i++)
    {
        printf("%d ", borrowedBookIDs[i]);
    }
    printf("\n");
    printf("Total fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable: Rs. %.2f\n", fineAfterWaiver);
}

int main()
{
    // book inventory
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    // member record
    char name[50];
    int studentID = 0;
    int memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0;            // fine before waivers
    float fineAfterWaiver = 0;      // fine payable after waivers
    int registered = 0;             // 1 once a member is registered

    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (registered == 1)
            {
                printf("A member is already registered.\n");
            }
            else
            {
                registerMember(name, &studentID, &memberType);
                registered = 1;
            }
            break;

        case 2:
            displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
            break;

        case 3:
            if (registered == 0)
                printf("Please register first.\n");
            else
                borrowBook(bookIDs, bookTitles, availableCopies, totalBooks,
                           borrowedBookIDs, &borrowedCount, memberType);
            break;

        case 4:
            if (registered == 0)
                printf("Please register first.\n");
            else
                fineAfterWaiver = fineAfterWaiver +
                    returnBook(bookIDs, availableCopies, totalBooks,
                               borrowedBookIDs, &borrowedCount, memberType, &totalFine);
            break;

        case 5:
            if (registered == 0)
                printf("Please register first.\n");
            else
                displayMemberRecord(name, studentID, memberType, borrowedBookIDs,
                                    borrowedCount, totalFine, fineAfterWaiver);
            break;

        case 6:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
