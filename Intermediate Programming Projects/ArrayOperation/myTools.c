#include <stdio.h>
#include "gotoxy.h"


void drawDBox(int x1, int y1, int x2, int y2){
	int i , j;

	
	for(i = x1; i <= x2; i++){
		gotoxy(i,y1);printf("%c", 196);
		gotoxy(i,y2);printf("%c", 196);
	}
	
	for(j = y1; j <= y2; j++){
		gotoxy(x1,j);printf("%c", 179);
		gotoxy(x2,j);printf("%c", 179);
	}
	
	gotoxy(x1,y1);printf("%c", 218);
	gotoxy(x1,y2);printf("%c", 192);
	gotoxy(x2,y1);printf("%c", 191);
	gotoxy(x2,y2);printf("%c", 217);
	

}

void menu(){

	gotoxy(12,1);printf("~~~~~~~ ARRAY OPERATIONS ~~~~~~~");
	gotoxy(17,3);printf("1.CREATEArray");
	gotoxy(17,4);printf("2.PRINTArray");
	gotoxy(17,5);printf("3.INSERTAtPos");
	gotoxy(17,6);printf("4.INSERTFront");
	gotoxy(17,7);printf("5.REMOVEAtPos");
	gotoxy(17,8);printf("6.REMOVETerm");
	gotoxy(17,9);printf("7.REMOVEFront");
	gotoxy(17,10);printf("8.LOCATEIndx");
	gotoxy(17,11);printf("9.LOCATETerm");
	gotoxy(17,12);printf("10. SORT(Ascending & Descending)");
	gotoxy(17,13);printf("11. EXIT");
	gotoxy(15,14);printf("Enter a valid choice[1-11]: ");

}
