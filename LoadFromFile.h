//header guards so the file is not processed multiple times
#ifndef LoadFromFile.h
#define LoadFromFile.h

#include <stdio.h>
#include <stdlib.h>

List* loadFromFile(char fileName[80])
{
    FILE *ptr;

    /*to know where the list starts. Also to set the 
     *first list prev property to NULL*/
    List* first_list = NULL;

    List* current_ptr_list;
    Item* current_ptr_item;

    char str[200];

    //file is opened. If it doesnt exist it displays appropriate error message
    if((ptr = fopen(fileName, "r"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    else{
        fgets(str, sizeof(str), ptr);
        do
        {
            //if str ends with : then it is treated as the name of the list
            if(str[strlen(str)-2]==':')
            {
                /*to span the string to remove the new line
                *after the name of the list*/
                str[strcspn(str, "\n")] = 0;

                List* node = malloc(sizeof(List));
                if(node == NULL) printf("!!!! malloc for list failed!!!\n");

                /*setting new nodes properties to NULL as it 
                 *will be at the end of the list.
                 *Newly created items will be later joined to it*/
                strcpy(node->name, str);
                node->next = NULL;
                node->first_item = NULL;
                node->prev=NULL;

                /*if it is the first list of the board it
                 *is directly linked to the board itself by
                 *being then returned to main.c*/
                if(first_list == NULL){

                    current_ptr_list = node;

                    /*saving the first list to know where
                    * the list starts to be able to
                    *display the board*/
                    first_list=node;

                    current_ptr_list->next=NULL;
                }
                else{
                    node->prev=current_ptr_list;
                    current_ptr_list = current_ptr_list->next = node;
                }
            }
            else{
                str[strcspn(str, "\n")] = 0;
                Item* nod = malloc(sizeof(Item));
                if(nod == NULL) printf("!!!! malloc for item failed!!!\n");

                strcpy(nod->name, str);
                nod->next = NULL;

                /* connecting the list of items to the actual list
                 * by setting list's first_item property to the nod*/
                if(current_ptr_list->first_item==NULL)
                {
                    current_ptr_list->first_item = nod;
                    current_ptr_item = nod;
                }
                else{
                    current_ptr_item = current_ptr_item->next = nod;
                }
            }
        }while(fgets(str, sizeof(str), ptr)!=NULL);

        fclose(ptr);

        //pointer to the first list in the board is returned to main.c
        return first_list;

    }
}

#endif LoadFromFile.h

