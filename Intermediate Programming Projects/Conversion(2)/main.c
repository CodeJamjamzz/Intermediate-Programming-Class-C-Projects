#include "myTools.h"
#include "Conversion.h"
#include <stdlib.h>

int main(){
	
	int time, hours, mins, sec, coinValue, quarter, dime, penny, dis;
	char choose;
	
	do {
	drawSBox(0,0,30,15);
	menu();
	choose = ch();
	
	switch (choose){
		case 'a':
			system("cls");
			drawSBox(0,0,30,15);
			time = getTime();
			convertTime(time, &hours, &mins, &sec);
			system("cls");
			break;
		case 'b':
			do {
			system("cls");
			drawSBox(0,0,30,15);
			coinValue = getCoin();
			system("cls");
			} while (coinValue > 100 || coinValue < 0);
			computeCoin(coinValue, &quarter, &dime, &penny);
			break;
		case 'c':
			system("cls");
			drawSBox(0,0,30,15);
			dis = d();
			system("cls");
			drawSBox(0,0,30,15);
			if(dis == 1){
				displayTime(time, &hours, &mins, &sec);
			} else 
				displayCoin(coinValue, &quarter, &dime, &penny);
			break;
		case 'd':
			system("cls");
			menu();
			drawSBox(0,0,30,15);
			
			break;
		}  
	} while (choose != 'd');
	
	return 0;
}

