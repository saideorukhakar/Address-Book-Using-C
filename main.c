/*Documentation
NAME            : SAI DEORUKHAKAR
DATE            : 22/10/2025
DESCRIPTION     : CREATE ADDRESS BOOK USING C
                  Address Book Project is an application written in C language. 
                  It keeps track of names and telephone/mobile numbers and e-mail addresses. 
                  It is a console based application which uses standard I/O 
                  for adding and deleting contact names, phone numbers and e-mail addresses, 
                  searching names and associated numbers and email addresses, 
                  updating numbers and email addresses, and deleting contacts.

*/


#include <stdio.h>
#include "contact.h"

int main() 
{
    //ADDRESS BOOK

    int choice;
    int option;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book
    printf("_________________________________________________________________________________________________________________\n");
    printf("\n\t\t\t\t\t------------------------------\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t|    Address Book Project    |\t\t\t\t\t\n");
    printf("\t\t\t\t\t------------------------------\t\t\t\t\t\t\n");
    printf("_________________________________________________________________________________________________________________\n");
    printf("\n");
    do {

        //ADDRESS BOOK MENU
        //CREATE CONTACT, SEARH CONTACT, EDIT CONTACT, DELETE CONTACT, LIST ALL CONTACTS SAVE CONTACTS, EXIT FROM ADDRESS BOOK.
        printf("---------------------------------\n");
        printf("|\tAddress Book Menu\t|\n");
        printf("---------------------------------\n");
        printf("| 1. Create contact             |\n");
        printf("| 2. Search contact             |\n");
        printf("| 3. Edit contact               |\n");
        printf("| 4. Delete contact             |\n");
        printf("| 5. List all contacts          |\n");
        printf("| 6. Save                       |\n");
        printf("| 7. Exit                       |\n");
        printf("---------------------------------\n");
        printf("\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("| Enter your choice : ");
        scanf("%d", &choice);

        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("\n");
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:

                do
                {
                printf("---------------------------------\n");
                printf("|\tList in Sorted Order \t|\n");
                printf("---------------------------------\n");
                printf("| 1. Yes                        |\n");
                printf("| 2. No                         |\n");
                printf("---------------------------------\n");
                printf("\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("| Select Option : ");
                scanf("%d",&option);
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");

                switch(option)
                {
                    case 1 :
                            printf("---------------------------------\n");
                            printf("|\tSort Contact List\t|\n");
                            printf("---------------------------------\n");
                            printf("| 1. Sort by name               |\n");
                            printf("| 2. Sort by phone              |\n");
                            printf("| 3. Sort by email              |\n");
                            printf("---------------------------------\n");
                            printf("\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("| Enter your choice : ");
                            int sortChoice;
                            scanf("%d", &sortChoice);
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                            listContacts(&addressBook, sortChoice);
                        break;
                    case 2 :
                            listContact(&addressBook);
                        break;
                    default :
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("Please enter correct option...\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                }
                } while (option != 1 && option != 2);
            
                break;
            case 6:
                printf("------------------------------------------\n");
                printf("|\tSave Contact Sucssesfully...  \t |\n");
                printf("------------------------------------------\n");
                printf("\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                
                
                do
                {
                    printf("---------------------------------\n");
                    printf("|\tSave Changes\t\t|\n");
                    printf("---------------------------------\n");
                    printf("| 1. Yes                        |\n");
                    printf("| 2. No                         |\n");
                    printf("---------------------------------\n");
                    printf("\n");
                    printf("---------------------------------\n");
                    printf("| Enter Option : ");
                    scanf("%d",&option);
                    printf("---------------------------------\n");

                    switch(option)
                    {
                        case 1 :
                                printf("\n");
                                printf("------------------------------------------\n");
                                printf("|\tSave Changes Sucssesfully...\t |\n");
                                printf("------------------------------------------\n");
                                printf("\n");
                                printf("Exiting...\n");
                                saveContactsToFile(&addressBook);
                            break;
                        case 2 : 
                                printf("\n");
                                printf("Exiting...\n");
                            break;
                        default :
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("Please enter correct option...\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                            
                    }
                    
                } while (option != 1 && option != 2);
                
                break;
            default:
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("Invalid choice. Please try again...\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");
        }
    } while (choice != 7);
    
       return 0;
}
