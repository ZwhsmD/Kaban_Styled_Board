Questions:
●How do you load a board 
● How did you edit lists and items 
● How do you save a board 

How do you load the board?

To load the board, a function loadFromFile is used. It takes in a singular parameter called filename (which was asked in main.c)
The first if statement is opening the file and if it fails to open (returns null) it will state that the file cannot be opened.
Otherwise, it gets the contents of the file using fgets. Then if the last character (denoted by [strlen(str)-2] ) is “:”  it will look for the new line character and remove it(replace with 0)
Then node is initialised and dynamically allocated a place in memory. If it is unable to allocate memory, it will state so, otherwise the memory address of the string array “str” is copied into node’s name’s memory address. Node’s next, first item and previous is set to null. 
    This is because values have not yet been assigned to either parts of the node.
 


Then we connect the new scanned from file node to the last list scanned. If the new node is the first list in the board it is saved under first_list, and the prev property of the new node stays as NULL. If it is not the first list in the board, its prev property is set to current_ptr_list(list scanned before our node) and the current_ptr_list next property is set to our node, so the list are linked together.
If the scanned element does not have ‘:’ at the end, the program treats it as an item. It dynamically allocates memory for the new item node and sets its next property to null as it will be at the end of the list. 
If the new item node is the first element of the list it is linked straight to the list by setting the list’s first_item property to the new item node. If it is not the first item of the list, then it is linked to the previous item by setting the previous item’s next property to our new item node
Then a pointer to the first list scanned on board is returned to main.c and the file is closed


How did you edit lists and items?
how to edit list:

it asks the user what is the name of the list they want to edit.
we create current which is the pointer to the board
it keeps looking through the board to see where the input is using strcasecmp, if it is not equal to it and for as long as it doesn't reach the end of the link list, it will go to the next list
if it isn't found, it will say it cant find the list
if it can, it will print a menu which asks you what you would like to do if it. 
if the user enters 1 they are asking to change the name, it asks for the name of the item you want to edit and looks for it. if it is not in the list, it will state so, if it finds it, it will prompt the user to give a new name. 
    It will then make the item's name the new name by -> into the item's name.
if the user enters 2 they are asking to add an item. it asks the user to input a name for the new item then it allocates memory for the item using malloc. it copies the name of the new item. 
    The next items of new item is NULL because it that is the last item.
if the user enters 3 they are to delete an item. it again asks the user which item to delete, two structs of the name currentInDelete and previousInDelete are made. currentInDelete is set to the first item of the board and previous is set as null. we look through each item and compare it to the user's input and if they find it, it deletes. the way it deletes is that we first have a base case. if the item is the first item in the list (meaning the item does have a previous ie, previousInDelete is NULL), 
  then it will set the first one to the next one in the list. if not, it changes the current to the next one (previousInDelete->next which is current).
if the user enters 4, it returns back to the menu, to do that, we just use return.


to edit the board, the same things apply

if the user enters 1 it copies the input into currentBoard->name which modifies the list name.
if the user enters 2 it asks for the name of the new list. it assigns memory to add it in and then it copies the list name to the name of the new list. since this is a new list that is being created, newList's next and previous is NULL (it is empty). we check if the board is empty and if it is, it makes the first list as the new list or else,
    it will go all the way to the end of the board and once it does, it will make the next of that the newList and previous becomes the temp (which is the last list found)
If the user enters 3, it asks for which list to delete, it looks through the board, and if it doesn't exist (ie, it returns NULL), it will state so, otherwise, we have the base case again. if there is no previous list, 
    then the currentBoard would become curr->next which is the next list or else, the previous' next (which is the current) would be the next (which is prev->next = curr->next)
lastly, if the user enters 2, it returns to the menu through return.
otherwise it will state it is not an option.



How do you save a board?

To save the board to a file, a function saveFile is used.
    It takes in a singular parameter called file_name (which was asked in main.c) and opens that file in write mode. If it cannot do so, it prints “cannot open file <file name>”. 
Using a while loop, it iterates over every element of the board while checking for the condition that currentPtr != NULL(currentPtr is the last element). 
    It writes the name of the list to the file using fputs function. 
Then it dynamically allocates memory for the current Item of the list. It then iterates over every item of the list which was just put to the file until currentItem == NULL(last item). 
    It writes using fputs each element to the file adding a new line after each.
After all items of the list is written to the file, the currentPtr is changed to its next property to access next list and the cycle repeates.
When all is written to the file (currentPtr points to NULL == end of the board) then a newline is printed to assure proper display if the file would be loaded into the program after. The file is closed.

