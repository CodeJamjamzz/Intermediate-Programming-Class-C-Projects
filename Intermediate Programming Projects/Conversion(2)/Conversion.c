#include <stdio.h>

void convertTime(int time, int* hours, int* mins, int* sec){
	*hours = time / 3600;
	*mins = (time % 3600) / 60;
	*sec = time % 60;
}

void displayTime(int time, int* hours, int* mins, int* sec){
	gotoxy(2,12);printf("%d seconds is equal to ",time, *hours);
	gotoxy(2,13);printf("%d hours(s), %d min(s)",*hours,*mins);
	gotoxy(2,14);printf("and %d second(s).",*sec);
}

void computeCoin(int coinValue, int* quarter, int* dime, int* penny){
	*quarter = coinValue / 25;
	coinValue %= 25;
	*dime = coinValue / 10;
	coinValue %= 10;
	*penny = coinValue;
}

void displayCoin(int coinValue, int* quarter, int* dime, int* penny){
	gotoxy(2,12);printf("%d cents can be given as",coinValue);
	gotoxy(2,13);printf("%d quarter(s) %d dime(s) ", *quarter, *dime);
	gotoxy(2,14);printf("and %d penny(pennies).",*penny);
}

char ch(){
	char choose;
	gotoxy(2,10);printf("Enter your choice: ");
	gotoxy(21,10);scanf("%c", &choose);
	return choose;
}

int getTime(){
	int hours;
	gotoxy(1,1);printf("Enter number of seconds: ");
	gotoxy(1,2);scanf("%d", &hours);
	return hours;
}

int getCoin(){
	int coinValue;
	gotoxy(1,1);printf("Enter amount of coins: ");
	gotoxy(1,2);scanf("%d", &coinValue);
	return coinValue;
}

int d(){
	int dis;
	gotoxy(1,1);printf("Display [1]Time or [2]Coin: ");
	gotoxy(1,2);scanf("%d", &dis);
	return dis;
}
