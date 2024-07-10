#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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


int seatChecker(int *seats, int size){
	int i, ctr = 0;
	if(size == 5){
		for(i = 0 ; i < size; i++){
			if(*(seats+i) == 1){
				ctr++;
			}
		}
	}
	else if(size == 10){
		for(i = size-5 ; i < size; i++){
			if(*(seats+i) == 1){
				ctr++;
			}
		}
	}
	
	if(ctr == 5 && size == 5){
		return 1;
	} 
	else if(ctr == 10 && size == 10){
		return 1;
	}
	else {
		return 0;
	}
}
int planeChecker(int *seats, int size){
	int i, ctr = 0;
	for(i = 0 ; i < size; i++){
		if(*(seats+i) == 1){
			ctr +=1;
		}
	}
	if(ctr == 10){
		return 1;
	}
	return 0;
}

void initSeats(int *seats, int size){
	int i;
	for(i = 0; i < size; i++){
		*(seats+i) = 0;
	}
	return;
}
void displaySeats(int *seats, int size){
	int i;
	gotoxy(1,4);printf("First Class Section   ");
	for(i = 0; i < size-5; i++){
		printf("[%d] ", *(seats+i));
	}
	gotoxy(1,5);printf("Economy Section       ");
	for(i = size-5; i < size; i++){
		printf("[%d] ", *(seats+i));
	}
}
int assignSeats(int *seats, int seatType){
	int i, seat, choice, ctr;
	gotoxy(1,14);printf("Please enter 1 for First Class Section");
	gotoxy(1,15);printf("Please enter 2 for Economy Section   ");
	gotoxy(1,16);printf("[0]Exit:      ");
	gotoxy(11,16);scanf("%d", &seatType);
	if(seatType == 0){
		return 0;
	}
	
	while(seatType < 1 || seatType > 2){
		printf("\nInvalid Input...Try again");
		scanf("%d", &seatType);
	}
	
	if(seatType == 1){
		gotoxy(1,21);printf("                                                ");
		seat = firstClassSection(seats, 10);
		
	}
	
	else if(seatType == 2){
		seat = economySection(seats, 10);
		gotoxy(1,21);printf("                                           ");
	}
	
	return seat;
}
int firstClassSection(int *seats, int size){
	int i, choice, seat = 0, ctr;
	for(i = 0; i < size-5; i++){
		if(*(seats+i) == 0){
			*(seats+i) = 1;
			seats++;
			break;
		}
	}
	if(i == 5){
		displaySeats(seats, 10);
		gotoxy(1,21);printf("Seats are Full...");
		gotoxy(1,22);printf("Would you like to be transfered to ");
		gotoxy(1,23);printf("Economy Section? [1]Yes [2]No:         ");
		gotoxy(33,23);scanf("%d", &choice);
		while(choice < 1 || choice > 2){
			printf("Invalid Input...Try again");
			scanf("%d", &choice);
		}
		if(choice == 1){
			gotoxy(1,21);printf("                                                                                           ");
			gotoxy(1,22);printf("                                                                                           ");
			gotoxy(1,23);printf("                                                                                           ");
			return ctr = economySection(seats, 10);
		}
		else if(choice == 2){
			gotoxy(1,21);printf("                                                                                           ");
			gotoxy(1,22);printf("                                                                                           ");
			gotoxy(1,23);printf("                                                                                           ");
			gotoxy(1,21);printf("Next Flight will be in 3 hours");
			return -1;
		}
		
	}

	return i+1;
}
int economySection(int *seats, int size){
	int i, choice;
	for(i = size-5; i < size; i++){
		if(*(seats+i) == 0){
			*(seats+i) = 1;
			break;
		}
	}
	if(seatChecker(seats, 10) == 1){
		gotoxy(1,21);printf("No seats available");
		return i+1;
	}
	return i+1;
}
void boardPass(int seat){
//	if(seat == -1){
//		return;
//	}

	
	gotoxy(0,7);drawDBox(0,0,30,4);
	gotoxy(5,8);printf("Board Pass");
	if(seat <= 5){
		gotoxy(5,9);printf("First Class Section    ");
	}
	else if(seat >= 6){
		gotoxy(5,9);printf("Economy Section         ");
	}
	gotoxy(5,10);printf("Seat #%d     ", seat);
	return;
}
//void end(void){
//	printf("No more available seats");
//}

void menu(){
	int *seats, size = 10, seat, seatType, ctr = 0;
	seats = (int*)malloc(size*sizeof(int));
	initSeats(seats, size);
	gotoxy(12,2);printf("Welcome to MGM Airlines");
	do{
		
		displaySeats(seats, size);
		seat = assignSeats(seats, seatType);
		if(seat == 11){
			gotoxy(1,21);printf("No more economy seats.");
			continue;
		}
		boardPass(seat);
	}while(planeChecker(seats, size) == 0);
	
	displaySeats(seats, size);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return;
}
