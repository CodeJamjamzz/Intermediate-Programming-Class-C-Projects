#include <stdio.h>
#include "myTools.h"
#include "arrayOptn.h"
#include "windows.h"

void drawDBox(int x1, int y1, int x2, int y2){
	int i, j;
	for( i = y1; i <= y2; i++, printf("\n")) {
		for(j = 0; j <= x1 + x2; j++){
			if(j >= x1){
				if(i == y1){
					if(j == x1){
						printf("\xDA");
					}else if(j == x1 + x2){
						printf("\xBF");
					}else{
						printf("\xC4");
					}
				}else if(i == y2){
					if(j == x1){
						printf("\xC0");
					}else if(j == x1 + x2){
						printf("\xD9");
					}else{
						printf("\xC4");
					}
				}else if(j == x1 || j == x1 + x2){
					printf("\xB3");
				}else{
					printf(" ");
				}
			}
			else{
				printf(" ");
			}		
		}
	}
	return;
}
void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
	return;
}
void clrscr(){
	system("cls");
	return;
}
void getInput(char* resp){
	gotoxy(26,10);
	scanf(" %c", resp);
	getchar();
	return;
}

void getValue(char* str, int* num){
	gotoxy(0,13);
	printf(" %s", str);
	scanf("%d", num);
	return;
}
void menu(){
	drawDBox(1,1,60,30);
	gotoxy(14,2);
	printf("~~~ARRAY OPERATIONS~~~");
	gotoxy(16,4);
	printf("1. CREATEArray");
	gotoxy(16,5);
	printf("2. PRINTArray");
	gotoxy(16,6);
	printf("3. INSERTAtPos");
	gotoxy(16,7);
	printf("4. INSERTFront");
	gotoxy(16,8);
	printf("5. REMOVEAtPos");
	gotoxy(16,9);
	printf("6. REMOVEItem");
	gotoxy(16,10);
	printf("7. REMOVEFront");
	gotoxy(16,11);
	printf("8. LOCATEIndx");
	gotoxy(16,12);
	printf("9. LOCATEItem");
	gotoxy(16,13);
	printf("10. SORT(Ascending & Descending)");
	gotoxy(16,14);
	printf("11. EXIT\n");
	gotoxy(16,15);
	gotoxy(16,16);
	
}
