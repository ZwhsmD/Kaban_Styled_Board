//header guards so the file is not processed multiple times
#ifndef SaveToFile.h
#define SaveToFile.h

#include <stdio.h>
#include <stdlib.h>

void saveFile(List* currentPtr, char file_name[80])
{
    FILE *ptr;

    /*opening the file and checking if the file exists.
     * If not, appropiate message is displayed to console*/
    if((ptr = fopen(file_name, "w"))==NULL)
        printf("cannot open file %s",file_name);

    else{

        //iterating over each list until reached end of Board
        while(currentPtr != NULL){
            fputs(currentPtr->name, ptr);
            fputs("\n",ptr);

            /*new memory is allocated to hold a pointer to 
             *the item of the list which is being written to file.
             *it is set to first item of the list that was just written to file*/
            struct Item* currentItem;
            currentItem =currentPtr->first_item;

            //iterating over each item until reached end of list
            while(currentItem != NULL ){
                fputs(currentItem->name, ptr);
                fputs("\n",ptr);
                currentItem = currentItem->next;
            }

            //pointer to the next list is created
            currentPtr=currentPtr->next;
        }
    }

    /*adding a new line after to ensure proper display
     *if the file is to be loaded into the program again*/
    printf("\n");

    fclose(ptr);
}

#endif SaveToFile.h
