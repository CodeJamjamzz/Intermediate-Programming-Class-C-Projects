#include <stdio.h>
#include <stdlib.h>
#include "myTools.h"
#include "arrayOptn.h"

int main(){
	int size = 0, la[size], choice, item, index, k, a ,b;
	
	while(1){
		system("cls");
		menu();
		gotoxy(10,15); printf("Enter a valid choice[1-11]: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				system("cls");
				drawDBox(0,0,50,18);
				gotoxy(1,1); printf("Enter the size of array: ");
				scanf("%d", &size);
				createArray(la, size);
				break;
			case 2:
				system("cls");
				gotoxy(16,17);
				printArray(la, size);
				break;
			case 3:
				system("cls");
				gotoxy(16,17); printf("Enter item to insert: ");
				scanf("%d", &item);
				gotoxy(16,18); printf("Enter position to insert at: ");
				scanf("%d", &k);
				size = inserAtPos(la, size, item, k);
				break;
			case 4:
				system("cls");
				gotoxy(16,17); printf("Enter item to insert: ");
				scanf("%d", &item);
				insertFront(la, &size, item);
				break;
			case 5:
				system("cls");
				gotoxy(16,17); printf("Enter item to remove at: ");
				scanf("%d", &index);
				removeAtPos(la, &size, index);
				break;
			case 6:
				system("cls");
				gotoxy(16,17); printf("Enter item to remove: ");
				scanf("%d", &item);
				size = removeItem(la, size, item);
				break;
			case 7:
				system("cls");
				size = removeFront(la, &size);
				break;
			case 8:
				system("cls");
				gotoxy(16,17); printf("Enter item to locate: ");
				scanf("%d", &item);
				index = locateIndex(la, size, item);
				gotoxy(16,18); printf("Index: %d\n", index);
				break;
			case 9:
				system("cls");
				gotoxy(16,17); printf("Enter item to locate: ");
				scanf("%d", &item);
				if(locateItem(la, size, item)){
					gotoxy(16,18); printf("Item found!\n");
				}else{
					gotoxy(16,18); printf("Item not found!\n");
				}
				break;
			case 10:
				system("cls");
				gotoxy(16,18); sortAscending(la, size);
				printf("ARRAY list in ASCENDING order  :  \n");
				gotoxy(16,19); printArray(la, size);
				gotoxy(16,20); sortDescending(la, size);
				printf("ARRAY list in DESCENDING order  :  \n");
				gotoxy(16,21); printArray(la, size);
				break;
			case 11:
				exit(0);
			default:
				printf("Invalid choice!\n");
				break;
		}
		gotoxy(16,22); printf("Press any key to continue...");
		getch();
	}
	return 0;
}
