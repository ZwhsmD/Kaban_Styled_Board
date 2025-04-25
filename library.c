#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{
    char name[80];
    struct Item *next;
}Item;

typedef struct List{
    char name[80];
    struct Item *first_item;
    struct List *next;
    struct List *prev;
}List;


void displayBoard(List* currentPtr){

    while(currentPtr != NULL){
        printf("%s \n",currentPtr->name);
        struct Item* currentItem;
        currentItem =currentPtr->first_item;

        while(currentItem!=NULL){
            printf("%s\n",currentItem->name);
            currentItem = currentItem->next;
        }
        currentPtr=currentPtr->next;
    }
}


List* loadFromFile(char fileName[80])
{
    FILE *ptr;
    List* first_list = NULL;
    List* current_ptr_list;
    Item* current_ptr_item;
    char str[200];

    if((ptr = fopen(fileName, "r"))==NULL){
        printf("Cannot open file\n");
    }
    else{
        fgets(str, sizeof(str), ptr);
        do
        {
            if(str[strlen(str)-2]==':')
            {
                /*to span the string to remove the new line
                *after the name of the list*/
                str[strcspn(str, "\n")] = 0;

                List* node = malloc(sizeof(List));
                if(node == NULL) printf("!!!! malloc for list failed!!!\n");

                strcpy(node->name, str);
                node->next = NULL;
                node->first_item = NULL;
                node->prev=NULL;


                if(first_list == NULL){
                    /*saving the first list to know where
                    * the list starts to be able to
                    *display the board*/
                    current_ptr_list = node;
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
                 * on the board*/
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
        return first_list;

    }
}


void saveFile(List* currentPtr, char file_name[80])
{
    FILE *ptr;
    if((ptr = fopen(file_name, "w"))==NULL)
        printf("cannot open file %s",file_name);

    else{
        while(currentPtr != NULL){
            fputs(currentPtr->name, ptr);
            fputs("\n",ptr);
            struct Item* currentItem;
            currentItem =currentPtr->first_item;

            while(currentItem != NULL ){
                fputs(currentItem->name, ptr);
                fputs("\n",ptr);
                currentItem = currentItem->next;
            }
            currentPtr=currentPtr->next;
        }
    }
    printf("\n");
    fclose(ptr);
}


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
                printf("Enter the new name for item '%s':"\n);
                //gets rid of new line character
                fgets(editNewName, 80, stdin);
                editNewName[strcspn(editNewName, "\n")] = '\0';

                //replaces old with new
                currentItem->name = editNewName;
            }

        }
        else if (choice == 2) {
            // add a new item
            char newItemToAdd[80];
            printf("Enter the name of the new item: ");

            //replacing new line with terminating character
            fgets(newItemToAdd, 80, stdin);
            newItemToAdd[strcspn(newItemToAdd, "\n")] = '\0';

            //allocate memory to make the new item
            Item* newItem = malloc(sizeof(Item));

            //first part of struct (name)
            strcpy(newItem->name, newItemToadd);

            //second part of struct (next)
            newItem->next = NULL;
        }
        else if (choice == 3) {
            //delete an item
            char itemToDelete[80];
            printf("Enter the name of the item to delete: ");
            //gets rid of new line character
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
                    //is this legal? currentInDelete = currentInDelete->next;
                    //something tells me thats wrong, because it's a pointer to a struct no?
                }
            }


        }
        else if (choice == 4) {
            // go back to menu

            //task to turn it into a function
            int menu();
        }
        else {
            printf("That is not an option"); //put it all into a while loop
        }

    }

}



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

    if (choice == 1) {
        //changing the name of the list
        printf("Enter the name of the list to edit: ");

        char oldName[80];
        char newName[80];

        //gets input and gets rid of new line character
        fgets(oldName, 80, stdin);
        oldName[strcspn(oldName, "\n")] = '\0';

        //looks if it exists
        while (currentBoard != NULL && strcmp(oldName, currentBoard->name) != 0) {
            currentBoard = currentBoard->next;
        }

        //if it doesn't exist
        if (currentBoard == NULL) {
            printf("Can't find list\n");
        }
        //if it does exist
        else {
            printf("Enter the new name for the list '%s': ", newName);

            //gets input and then replaces the new line character with the terminating character
            fgets(newName, 80, stdin);
            newName[strcspn(newName, "\n")] = '\0';

            currentBoard->name = newName;
        }
    }
    else if (choice == 2) {
        //adding a new list
        char newListName[80]
        printf("Enter the name of the new list: ");

        //gets the new list name
        fgets(newListName, 80, stdin);
        newListName[strcspn(newListName, "\n")] = '\0';

        List* newList = malloc(sizeof(List));

        //giving name to the list
        strcpy(newList->name, newListName);

        //next and prev have to be updated.
    }
    else if (choice == 3) {
        //deleting a list
        char listToDelete[80];
        printf("Enter the name of the list to delete: ");

        //gets the name of the list to delete and gets rid of the new line character
        fgets(listToDelete, 80, stdin);
        listToDelete[strcspn(listToDelete, "\n")] = '\0';

        
        List* curr = currentBoard->name;
        List* prev = NULL;

    }

}



//double check return type
int menu() {
    List* board = malloc(sizeof(List));
    //list 1: Abey
    List* list1 = malloc(sizeof(List));
    strcpy(list1->name, "Abey:");
    list1->next = NULL;
    Item* item1_1 = malloc(sizeof(Item));
    strcpy(item1_1->name, "Oculus Pro");
    Item* item1_2 = malloc(sizeof(Item));
    strcpy(item1_2->name, "Oculus Quest 1");
    item1_2->next = NULL;
    list1->first_item = item1_1;
    item1_1->next = item1_2;

    //list 2:Dante
    List* list2 = malloc(sizeof(List));
    strcpy(list2->name, "Dante:");
    list2->next = list1;
    Item* item2_1 = malloc(sizeof(Item));
    strcpy(item2_1->name, "Oculus Quest 1");
    item2_1->next = NULL;
    Item* item2_2 = malloc(sizeof(Item));
    strcpy(item2_2->name, "3070 RTX");
    item2_2->next = NULL;
    list2->first_item = item2_1;
    item2_1->next = item2_2;

    //list 3: Tim
    List* list3 = malloc(sizeof(List));
    strcpy(list3->name, "Tim:");
    list3->next = list2;
    Item* item3_1 = malloc(sizeof(Item));
    strcpy(item3_1->name, "Oculus Quest 2");
    list3->first_item = item3_1;
    item3_1->next = NULL;

    //List 4: Nick
    List* list4 = malloc(sizeof(List));
    strcpy(list4->name, "Nick:");
    Item* item4_1 = malloc(sizeof(Item));
    strcpy(item4_1->name, "3070 RTX");
    item4_1->next = NULL;
    list4->first_item = item4_1;

    //setting up the board
    list4->next = list3;
    list1->prev = list2;
    list2->prev = list3;
    list3->prev = list4;
    list4->prev = NULL;
    board = list4;

    //displayBoard(board);

    while(1){
        //variables
        int userChoice=0;


        //printing the menu
        printf("Menu:\n");
        printf("1. Display Board\n");
        printf("2. Load board from a file\n");
        printf("3. Edit list\n");
        printf("4. Edit Board\n");
        printf("5. Save board to a file\n");
        printf("6. Quit\n");




        // Gets the input AND if the user gives an invalid input, it repeats


            while(userChoice < 1 || userChoice > 6)
            {
                printf("Enter your choice (1-6): ");
                scanf("%d", &userChoice);
            }




        if(userChoice == 1)
        {
            printf("Display board\n\n");
            system("clear");
            //clearScreen();
            displayBoard(board);
        }
        else if(userChoice == 2)
        {
            printf("Load board from a file\n");
            printf("What is the file name?: ");
            char fileName[80];
            scanf("%s",fileName);
            board = loadFromFile(fileName);
            system("clear");
            //clearScreen();
        }
        else if(userChoice == 3)
        {
            printf("Edit list\n");
        }
        else if(userChoice == 4)
        {
            printf("Edit board\n");
        }
        else if(userChoice == 5)
        {
            printf("Save board to a file\n");
            printf("What is the file name?: ");
            char fileName[80];
            scanf("%s",fileName);
            saveFile(board,fileName);
            system("clear");
            //clearScreen();
        }
        else if(userChoice == 6)
        {
            return 0;
        }
    }




    }
