#ifndef EDITBOARD_H_INCLUDED
#define EDITBOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void editBoard(List* board) {
    //prints option menu
    printf("Options:\n");
    printf("1. Edit the name of the list\n");
    printf("2. Add a new list\n");
    printf("3. Delete an list\n");
    printf("4. Return to main menu\n");
    printf("Enter your option: ");

    int choice=0;
    scanf("%d",&choice);

    List* currentBoard = board;


    /*while (currentBoard != NULL && strcmp(choice, currentBoard->name) != 0) {
        currentBoard = currentBoard->next;
    }*/


    if (choice == 1) {
        //changing the name of the list
        printf("Enter the name of the list to edit: ");

        char oldName[80];
        char newName[80];

        //gets input and gets rid of new line character
        fflush(stdin);
        fgets(oldName, 80, stdin);
        oldName[strcspn(oldName, "\n")] = '\0';


        //looks if it exists
        //List* curr = board;
        while (currentBoard != NULL && strcmp(oldName, currentBoard->name) != 0) {
            currentBoard = currentBoard->next;
        }

        //if it doesn't exist
        if (currentBoard == NULL) {
            printf("Can't find list\n");
        }
        //if it does exist
        else {
            printf("Enter the new name for the list '%s': ", oldName);

            //gets input and then replaces the new line character with the terminating character
            fgets(newName, 80, stdin);
            newName[strcspn(newName, "\n")] = '\0';

            strcpy(currentBoard->name, newName);
        }
    }
    else if (choice == 2) {

        //adding a new list
        char newListName[80];
        printf("Enter the name of the new list: ");

        //gets the new list name
        fflush(stdin);
        fgets(newListName, 80, stdin);
        newListName[strcspn(newListName, "\n")] = '\0';

        List* newList = malloc(sizeof(List));


        //first part of struct (name)
        strcpy(newList->name, newListName);

        newList->next = NULL;
        newList->first_item=NULL;

        List* currentPtr;

        currentPtr = currentBoard;

                //if the board is empty
            if(currentBoard == NULL) {
                currentBoard = newList;
            }
            else {
                List* temp = currentBoard;

                while (temp->next != NULL){
                    temp = temp->next;
                }

            temp->next = newList;
            newList->prev = temp;

            }

        }
        else if (choice == 3) {
        //deleting a list
        char listToDelete[80];
        printf("Enter the name of the list to delete: ");

        //gets the name of the list to delete and gets rid of the new line character
        fflush(stdin);
        fgets(listToDelete, 80, stdin);
        listToDelete[strcspn(listToDelete, "\n")] = '\0';


        List* curr = currentBoard;
        List* prev = NULL;

        //goes through the board to see which one to delete
            while (curr != NULL && strcmp(listToDelete, curr->name) != 0) {
                prev = curr;
                curr = curr->next;
            }

            //if the item isn't there
            if (curr == NULL) {
                printf("List not found\n");
            }
            //if it is, delete it
            else {
                //base case: meaning if it is the first list
                if (prev == NULL) {
                    currentBoard = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
            }
    }
    else if (choice == 4){
        return;
    }
    else{
        printf("That is not an option");
    }

}


#endif // EDITBOARD_H_INCLUDED
