#ifndef EDITLIST_H_INCLUDED
#define EDITLIST_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void editList(List* board) {

    char userIn[80];

    //asks for the name of the list
    printf("Enter the name of the list to edit:\n");
    scanf("%s", userIn);

    //contains the address of that board
    List* current = board;

    //for as long as we aren't at the end and the input isn't the same as the list name, move on to the next
    while (current != NULL && strcmp(userIn, current->name) != 0) {
        current = current->next;
    }

    //if it wasn't found
    if (current == NULL) {
        printf("Can't find list\n");
    }
    else {
        // if it can find the list, here is the menu. ask the user what they want to do
        printf("Options:\n");
        printf("1. Edit an item\n");
        printf("2. Add a new item\n");
        printf("3. Delete an item\n");
        printf("4. Return to main menu\n");
        printf("Enter your option: ");


        //scanning user input.
        int choice=0;
        scanf("%d",&choice);

        if (choice == 1) {
            // edit the name
            char editOldName[80];
            char editNewName[80];


            printf("Enter the name of the item to edit:\n");
            //gets rid of new line character
            fflush(stdin);
            fgets(editOldName, 80, stdin);
            editOldName[strcspn(editOldName, "\n")] = '\0';

            //check if the item is even there
            Item* currentItem = current->first_item;
            while (currentItem != NULL && strcmp(editOldName, currentItem->name) != 0) {
                currentItem = currentItem->next;
            }


            //if it doesn't exist
            if (currentItem == NULL) {
                printf("Item not found\n");
            }
            //if it is found, ask for the new name
            else {
                printf("Enter the new name for item '%s':\n");
                //gets rid of new line character
                fflush(stdin);
                fgets(editNewName, 80, stdin);
                editNewName[strcspn(editNewName, "\n")] = '\0';

                //replaces old with new
                strcpy(currentItem->name, editNewName);
            }

        }
        else if (choice == 2) {
            // add a new item
            char newItemToAdd[80];
            printf("Enter the name of the new item: ");

            //replacing new line with terminating character
            fflush(stdin); //got the new line from the previous fgets
            fgets(newItemToAdd, 80, stdin);
            newItemToAdd[strcspn(newItemToAdd, "\n")] = '\0';

            //allocate memory to make the new item
            Item* newItem = malloc(sizeof(Item));

            //first part of struct (name)
            strcpy(newItem->name, newItemToAdd);

            //second part of struct (next)
            newItem->next = NULL;

            Item* currentPtr;
            if(current->first_item==NULL)
            {
                current->first_item = newItem;
            }else{

                currentPtr= current->first_item;

                while(currentPtr->next != NULL){
                    currentPtr = currentPtr->next;
                }

                currentPtr->next = newItem;
            }
        }
        else if (choice == 3) {
            //delete an item
            char itemToDelete[80];
            printf("Enter the name of the item to delete: ");
            //gets rid of new line character
            fflush(stdin);
            fgets(itemToDelete, 80, stdin);
            itemToDelete[strcspn(itemToDelete, "\n")] = '\0';

            Item* currentInDelete = current->first_item;
            Item* previousInDelete = NULL;

            //goes through the items to see which one to delete
            while (currentInDelete != NULL && strcmp(itemToDelete, currentInDelete->name) != 0) {
                previousInDelete = currentInDelete;
                currentInDelete = currentInDelete->next;
            }

            //if the item isn't there
            if (currentInDelete == NULL) {
                printf("Item not found\n");
            }
            //if it is, delete it
            else {
                //base case: meaning if it is the first item
                if (previousInDelete == NULL) {
                    current->first_item = currentInDelete->next;
                }
                else {
                    previousInDelete->next= currentInDelete->next;
                }
            }


        }
        else if (choice == 4) {
            return 0;
        }
        else {
            printf("That is not an option"); //put it all into a while loop
        }

    }

}


#endif // EDITLIST_H_INCLUDED
