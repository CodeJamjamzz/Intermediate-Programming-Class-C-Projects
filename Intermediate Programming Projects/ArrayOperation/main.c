#include <stdio.h>
#include <stdlib.h>
#include "myTools.h"
#include "arrayOptn.h"

int main(){
	int size = 0, la[size], choice, item, index, k, a ,b;
	
	do{
		system("cls");
		drawDBox(0,0,58,20);
		menu();
		scanf("%d", &choice);

		switch(choice) {
			case 1: //DONE
				system("cls");
				drawDBox(0,0,58,20);
				size = 5;
//				gotoxy(1,1); printf("Input size of array: ");
//				scanf("%d", &size);
				createArray(la, size);
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 2: //DONE
				system("cls");
				//drawDBox(0,0,58,20);
				gotoxy(1,1);
				printArray(la, size);
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 3://DONE
				system("cls");drawDBox(0,0,58,20);
				
				if (size == 0){
					gotoxy(1,1);printf("Array is Empty. Create an Array First.");
				} else {				
				gotoxy(1,1); printf("Item to insert: ");
				scanf("%d", &item);			
				gotoxy(1,2); printf("Index to insert item: ");
				scanf("%d", &k);
				}
				
				if (k > size - 1 || k < 0){
					gotoxy(1,3);printf("Please Try again");
				} else {
				size = inserAtPos(la, size, item, k);
				}
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 4: //REVIEW
				system("cls");
				drawDBox(0,0,58,20);
				if (size == 0){
					gotoxy(1,1);printf("Array is Empty. Create an Array First.");
				} else {
				gotoxy(1,1); printf("Item to insert: ");
				scanf("%d", &item);
				insertFront(la, &size, item);
				}
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 5: //DONE
				system("cls");
				drawDBox(0,0,58,20);
				gotoxy(1,2); printf("Index to remove item: ");
				scanf("%d", &index);
				if (index > size - 1 || index < 0){
					gotoxy(1,3);printf("Please Try again");
				} else {
				removeAtPos(la, &size, index);
				}
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 6: //REVIEW
				system("cls");
				drawDBox(0,0,58,20);
				gotoxy(1,1); printf("Item to remove: ");
				scanf("%d", &item);
				size = removeItem(la, size, item);
				if(size == -1){
					gotoxy(1,3);printf("Data item you wish to remove does not exist in the array");
					gotoxy(1,4);printf("try another!");
					}
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 7: //DONE PERO REVIEW KAY NEED IMPROV
				system("cls");
				size = removeFront(la, size);
				drawDBox(0,0,58,20);
				break;
			case 8: //DONE
				system("cls");
				drawDBox(0,0,58,20);
				gotoxy(1,1); printf("Item to locate: ");
				scanf("%d", &item);
				index = locateIndex(la, size, item);
				system("cls");
				drawDBox(0,0,58,20);
				if (index == -1){
					gotoxy(1,1); printf("Item is not found");
				} else {
					gotoxy(1,1); printf("Item is at Index: %d", index);
				}
				
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 9: //DONE
				system("cls");
				drawDBox(0,0,58,20);
				gotoxy(1,1); printf("Item to locate: ");
				scanf("%d", &item);
				if(locateItem(la, size, item)){
					gotoxy(1,2); printf("Item exists!");
				}else{
					gotoxy(1,2); printf("Item does not exists!");
				}
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 10: //DONE
				system("cls");
				drawDBox(0,0,58,20);
				gotoxy(1,1); sortAscending(la, size);
				
				gotoxy(1,4); sortDescending(la, size);
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
			case 11: //DONE
				menu();
				drawDBox(0,0,58,20);
				break;
			default:
				gotoxy(23,17);printf("Invalid Input");
				gotoxy(15,18); printf("Press Enter Inorder to Proceed");
				getch();
				break;
		}	
	} while (choice != 11);
	
	return 0;
}
