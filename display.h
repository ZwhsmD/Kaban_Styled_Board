//header guards so the file is not processed multiple times
#ifndef display.h
#define display.h

#include <stdio.h>
#include <stdlib.h>

void displayBoard(List* currentPtr){

    //iterating over each list name until reached the end of board
    while(currentPtr != NULL){
        printf("%s \n",currentPtr->name);

        /*memory dynamically allocated to hold the 
         *pointer to the item being displayed. It is set
         *to the first element of the list*/
        struct Item* currentItem;
        currentItem =currentPtr->first_item;

        while(currentItem!=NULL){
            printf("   %s\n",currentItem->name);
            currentItem = currentItem->next;
        }
        printf("\n");

        //pointer changed to point at the next list in the board
        currentPtr=currentPtr->next;
    }
}

#endif display.h
