#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "getcontact.h"
#include "sortContacts.h"

void listContact(AddressBook *addressBook)
{
    //LIST CONTACT WITHOUT SORTING
    int size = addressBook->contactCount;
    int count = 1;

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|\t\t\t\t\t\tAddress Book\t\t\t\t\t\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| Sr.No.|\t\tName\t\t|\tPhone Number\t|\t\tEmail ID\t\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n"); 

    for(int i = 0; i < size; i++)
    {
       
        printf("|  %d\t|\t%s \t|\t%s\t|\t%s \t\t|\n",count,addressBook ->contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
        count++;
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    //LIST CONTACTS AND SORT BY OUR CHOISE
    // Sort contacts based on the chosen criteria
    int size = addressBook->contactCount;
    sortContacts(addressBook,sortCriteria,size);
    int count = 1;

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|\t\t\t\t\t\tAddress Book\t\t\t\t\t\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| Sr.No.|\t\tName\t\t|\tPhone Number\t|\t\tEmail ID\t\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n"); 

    for(int i = 0; i < size; i++)
    {
       
        printf("|  %d\t|\t%s \t|\t%s\t|\t%s \t\t|\n",count,addressBook ->contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
        count++;
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void initialize(AddressBook *addressBook) {
    //addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}



int check_phone(AddressBook *addressBook,char *phone)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(phone,addressBook->contacts[i].phone) == 0)
        {
            return 0;
        }
    }

    return 1;
    
}

int check_email(AddressBook *addressBook,char *email)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(email,addressBook->contacts[i].email) == 0)
        {
            return 0;
        }
    }

    return 1;
    
}
void createContact(AddressBook *addressBook)
{
    //CREATE CONTACT
    //READ THE NAME, PHONE NUMBER AND EMAIL ID

    char name[20],phone[20],email[50],*ch,*sub_str;
    int len,option;
    

    getchar();

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("Enter the name : ");
    scanf("%[^\n]",name);
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

    getchar();

    do
    {
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("Enter the phone number : ");
        scanf("%s", phone);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("\n");

        len = strlen(phone);

        if(len != 10)
        {
            printf("-----------------------------------------------------------------------------------------------------------------\n");
            printf("Please enter 10 digit number.\n");
            printf("-----------------------------------------------------------------------------------------------------------------\n");
            printf("\n");
        }
        else
        {
            if(check_phone(addressBook, phone) == 0)
            {
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("The phone number is already present, so we can't add this contact.\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");
                len = 0;   
            }
        }

        getchar();
    } while ( len != 10 );

    do
    {
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("Enter the email id : ");
        scanf("%s",email);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("\n");
        ch = strchr(email,'@');
        sub_str = strstr(email,".com");

        
        if(ch == NULL || sub_str == NULL)
        {
            printf("-----------------------------------------------------------------------------------------------------------------\n");
            printf("Please enter @ character and end with .com\n");
            printf("-----------------------------------------------------------------------------------------------------------------\n");
            printf("\n");
        }
        else
        {
            if(check_email(addressBook, email) == 0)
            {
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("The email id is already present, re enter the email id.\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
        }

    } while (ch == NULL || sub_str == NULL);

    do
                {
                    printf("---------------------------------\n");
                    printf("|\tSave Contact\t\t|\n");
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

                                strcpy(addressBook->contacts[addressBook->contactCount].name,name);
                                strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
                                strcpy(addressBook->contacts[addressBook->contactCount].email,email);
    
                                (addressBook->contactCount)++;
                                
                                printf("\n");
                                printf("------------------------------------------\n");
                                printf("|\tSave Changes Sucssesfully...\t |\n");
                                printf("------------------------------------------\n");
                                printf("\n");
                                
                            break;
                        case 2 : 
                            break;
                        default :
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("Please enter correct option...\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                            
                    }
                    
                    
                } while (option != 1 && option != 2);


                
    
}


void searchContact(AddressBook *addressBook) 
{
    ///SEARCH CONTACT
    getcontact(addressBook);
}


void editContact(AddressBook *addressBook)
{
	//EDIT CONTACT
    char name[50],phone[20],email[20];
    int option;
    int index = getcontactlocation(addressBook);

    printf("---------------------------------\n");
    printf("|\tEdit Contact\t\t|\n");
    printf("---------------------------------\n");
    printf("| 1. Edit the name.             |\n");
    printf("| 2. Edit the phone number.     |\n");
    printf("| 3. Edit the email id.         |\n");
    printf("---------------------------------\n");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| Enter the option : ");
    
    scanf("%d",&option);
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

    switch(option)
    {
        case 1 :
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("| Enter the new name : ");
                getchar();
                scanf("%[^\n]",name);
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");

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
                                strcpy(addressBook->contacts[index].name,name);
                            break;
                        case 2 : 
                            break;
                        default :
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("Please enter correct option...\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                            
                    }
                    
                } while (option != 1 && option != 2);
                
            break;

        case 2 :
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("| Enter the new phone number : ");
                getchar();
                scanf("%s",phone);
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");

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
                                strcpy(addressBook->contacts[index].phone,phone);
                            break;
                        case 2 : 
                            break;
                        default :
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("Please enter correct option...\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                            
                    }
                    
                } while (option != 1 && option != 2);
                
            break;
        
        case 3 :
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("| Enter the new email id : ");
                getchar();
                scanf("%s",email);
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");

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
                                strcpy(addressBook->contacts[index].email,email);
                            break;
                        case 2 : 
                            break;
                        default :
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("Please enter correct option...\n");
                            printf("-----------------------------------------------------------------------------------------------------------------\n");
                            printf("\n");
                            
                    }
                    
                } while (option != 1 && option != 2);

                
            break;
    }

    
}

void deleteContact(AddressBook *addressBook)
{
	//DELETE CONTACT
    int option;
    int index = getcontactlocation(addressBook);

    do
    {

    printf("---------------------------------\n");
    printf("|\tDelete Contact\t\t|\n");
    printf("---------------------------------\n");
    printf("| 1. Yes                        |\n");
    printf("| 2. No                         |\n");
    printf("---------------------------------\n");
    printf("\n");
    printf("---------------------------------\n");
    printf("| Enter Option :  ");
    scanf("%d",&option);
    printf("---------------------------------\n");
    printf("\n");

    switch(option)
    {
        case 1 : for(int i = index; i < addressBook->contactCount; i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i+1];
                }

                (addressBook->contactCount)--;
            break;

        case 2 :
                break;

        default :
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("Please enter correct option...\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                printf("\n");
    }
    } while (option != 1 && option != 2);
    
   
}
