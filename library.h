#ifndef LIBRARY_H
#define LIBRARY_H
void displayBoard(List* currentPtr);
List* loadFromFile(char fileName[80]);
void saveFile(List* currentPtr, char file_name[80]);

#endif //LIBRARY_H
