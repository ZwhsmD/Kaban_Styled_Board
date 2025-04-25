#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen(){system("cls");}

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

#include "display.h"
#include "LoadFromFile.h"
#include "SaveToFile.h"
#include "EditList.h"
#include "EditBoard.h"

int main(void)
{
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


        while (scanf("%d", &userChoice) != 1 || userChoice <= 0 || userChoice > 6){
            printf("Invalid input, enter a valid input\n");
            while (getchar() != '\n');
        }




        if(userChoice == 1)
        {
            clearScreen();
            printf("Display board\n\n");
            displayBoard(board);
        }
        else if(userChoice == 2)
        {
            printf("Load board from a file\n");
            printf("What is the file name?: ");
            char fileName[80];
            scanf("%s",fileName);
            board = loadFromFile(fileName);
            //clearScreen();
        }
        else if(userChoice == 3)
        {
            printf("Edit list\n");
            editList(board);
        }
        else if(userChoice == 4)
        {
            printf("Edit board\n");
            editBoard(board);
        }
        else if(userChoice == 5)
        {
            printf("Save board to a file\n");
            printf("What is the file name?: ");
            char fileName[80];
            scanf("%s",fileName);
            saveFile(board,fileName);
        }
        else if(userChoice == 6)
        {
            //ascii art
            printf("..................................................................................................\n");
            printf("..................................................................................................\n");
            printf("..................................................................................................\n");
            printf("..................................................................................................\n");
            printf("..................................................................................................\n");
            printf("..................................................................................................\n");
            printf("...............................-#:...:#:-*%%%%#***+=-:::=#@=.....-#:................................\n");
            printf("..............................*-.....+#-:................-++.....#:...............................\n");
            printf(".............................#.....-#:......................+-....#...............................\n");
            printf("............................-=....-+.........................=+...*:..............................\n");
            printf("............................=-...:*...........................*:..:#:.............................\n");
            printf("...........................=*...:*............................-=.....:-**.........................\n");
            printf("..........................==....=-...#@%%=........=@@#.........:#.........#:.......................\n");
            printf(".........................#:.....#...-@@+@:.......%%+@@+.........#.........*:.......................\n");
            printf("........................=:.....++...:#*%%#........%%%%+@=.........#........:#........................\n");
            printf("........................+:....:*.....+*=....:....:++-..........#.......=*.........................\n");
            printf("........................=-....:*..........#-..*=..............:*...-+*=...........................\n");
            printf(".........................#:....:#..........=@*+...............*-::................................\n");
            printf("..........................:+%%%%%%+-#:........:@-...............#:...................................\n");
            printf("..................................=+......=-.#..............#.....................................\n");
            printf("...................................#@%%+....:-............-%%%%:.....................................\n");
            printf("..................................-+-+*+-..............+@-..#.....................................\n");
            printf("..................................=-.:%%:.:+%%%%+-:=++*%%*=*.....#....................................\n");
            printf("..................................#.....*#.........-&%+.......:#...................................\n");
            printf(".................................++........-=++++=:....=***:..+-..................................\n");
            printf("................................:+...................*=....-*.:=..................................\n");
            printf("................................#:....--............--........-=..................................\n");
            printf("...............................#:....:#..............#*==%%+..:#...................................\n");
            printf("..............................-=.....#...................*=++:....................................\n");
            printf("..............................#:=-:.==-----:....::::.....*-...:#..................................\n");
            printf(".........................:::-:**-+*@-.=-.-*.:#:.*.+=.*-.-=+**+==+++*+=*##@@-......................\n");
            printf("......................:=#-#%%@:-**#-#@@-.-@%-#..#@@.:#.%%@#..=*-@@#...#-#.+-+=......................\n");
            printf(".....................-%%%%+*+%%==#=#***@#+=@@*%%++*@@#*%%##@@*##%%##@@#*#@@@++*:@-......................\n");
            printf("....................=%%...................................................##=......................\n");
            printf("....................-@###################****####################*+++++=+#*:......................\n");
            return 0;
        }
    }




    return 0;

}
