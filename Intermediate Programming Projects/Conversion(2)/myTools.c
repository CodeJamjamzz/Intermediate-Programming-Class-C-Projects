#include <stdio.h>
#include "gotoxy.h"

void drawSBox(int x1, int y1, int x2, int y2){
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
	
	gotoxy(8,1);printf("Conversion\n\n");
	gotoxy(2,3);printf("[a]Time\n");
	gotoxy(2,4);printf("[b]Coin\n");
	gotoxy(2,5);printf("[c]Display\n");
	gotoxy(5,6);printf("[1]Time\n");
	gotoxy(5,7);printf("[2]Coin\n");
	gotoxy(2,8);printf("[d]Exit\n");
	gotoxy(21,10);printf("   ");
	//gotoxy(0,13);printf("                                                              \n\n\n");
	//gotoxy(0,14);printf("                                                              ");
//	gotoxy(2,10);printf("Enter your choice: ");
//	gotoxy(21,10);scanf("%c", &choose);
	
	return;
}

