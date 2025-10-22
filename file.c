#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "file.h"

//Text File
//LOAD AND SAVE CONTACT IN TXT FILE
/*
void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contact.txt", "w");
    int size = addressBook->contactCount;

    fprintf(fptr,"#%d#\n",size);
    for(int i = 0; i < size; i++)
    {
       
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fptr);
  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    char str[500];

    FILE *fptr = fopen("contact.txt", "r");

    if(fptr == NULL)
    {
        printf("File is Not Present.\n");
    }
    else
    {
        fscanf(fptr, "%[^\n]",str);
        int size = atoi(strtok(&str[1],"#"));

        addressBook->contactCount = size;

        for(int i = 0; i < size; i++)
        {
            fscanf(fptr," %[^\n]",str);
            
            strcpy(addressBook->contacts[i].name, strtok(str, ","));
            strcpy(addressBook->contacts[i].phone, strtok(NULL, ","));
            strcpy(addressBook->contacts[i].email, strtok(NULL, ","));
        }
    } 
    fclose(fptr);
}

*/

//CSV File
//LOAD AND SAVE CONTACT IN CSV FILE

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contact1.csv", "w");
    int size = addressBook->contactCount;
    //int count = 1;
    fprintf(fptr,"#%d#\n",size);
    //fprintf(fptr,"%s,%s,%s,%s\n","Sr.No", "Name", "Phone No.","Email ID");
    for(int i = 0; i < size; i++)
    {
       
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        //count++;
    }

    fclose(fptr);
  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    char str[500];

    FILE *fptr = fopen("contact1.csv", "r");

    if(fptr == NULL)
    {
        printf("File is Not Present.\n");
    }
    else
    {
        fscanf(fptr, "%[^\n]",str);
        int size = atoi(strtok(&str[1],"#"));

        addressBook->contactCount = size;

        for(int i = 0; i < size; i++)
        {
            fscanf(fptr," %[^\n]",str);
            
            strcpy(addressBook->contacts[i].name, strtok(str, ","));
            strcpy(addressBook->contacts[i].phone, strtok(NULL, ","));
            strcpy(addressBook->contacts[i].email, strtok(NULL, ","));
        }
    } 
    fclose(fptr);
}

