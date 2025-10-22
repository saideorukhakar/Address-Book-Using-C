//SORT CONTACT

#include<stdio.h>
#include<string.h>
#include "contact.h"

void sortContacts(AddressBook *addressBook,int sortCriteria, int size)
{
    //SORT CONTACT BY NAME, PHONE NUMBER AND EMAIL ID
    int i,j;
    Contact temp;
    switch(sortCriteria)
    {
        case 1 : 
                for(i = 0; i < size - 1; i++)
                {
                    for(j = 0; j < size - i - 1; j++)
                    {
                        if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) > 0)
                        {
                            temp = addressBook->contacts[j];
                            addressBook->contacts[j] = addressBook->contacts[j+1];
                            addressBook->contacts[j+1] = temp;
                        }
                    }
                }
            break;
        case 2 : 
                for(i = 0; i < size - 1; i++)
                {
                    for(j = 0; j < size - i - 1; j++)
                    {
                        if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone) > 0)
                        {
                            temp = addressBook->contacts[j];
                            addressBook->contacts[j] = addressBook->contacts[j+1];
                            addressBook->contacts[j+1] = temp;
                        }
                    }
                }
            break;
        case 3 : 
                for(i = 0; i < size - 1; i++)
                {
                    for(j = 0; j < size - i - 1; j++)
                    {
                        if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email) > 0)
                        {
                            temp = addressBook->contacts[j];
                            addressBook->contacts[j] = addressBook->contacts[j+1];
                            addressBook->contacts[j+1] = temp;
                        }
                    }
                }
            break;
        
    }

}