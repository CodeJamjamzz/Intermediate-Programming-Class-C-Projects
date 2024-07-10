#include <stdio.h>
#include "myTools.h"
#include "arrayOptn.h"
#include <stdbool.h>

bool inArray(int la[], int size, int item){
	int i;
	for(i = 0; i < size; i++){
		if(la[i] == item){
			return true;
		}
	}
	return false;
}

void createArray(int la[], int size){
	gotoxy(16,18);
	printf("Enter %d unique integer numbers for the array: \n", size);
	int count = 0;
	int i;
	for(i = 0; i < size; i++){	
		int num;
		scanf("%d", &num);
		while(inArray(la, count, num)){
			gotoxy(16,19);
			printf("inputted integer already exists, try another no.\n");
			scanf("%d", &num);
		}
		la[count] = num; 
		count++;
	}
	return;
}
void printArray(int la[],int size){
	int i;
	printf("Array = {");
	for(i = 0; i < size; i++){
		if(i == size-1){
			printf("%d}", la[i]);
		}
		else
			printf(" %d,", la[i]);
	}
	printf("\n");
	return;
}

int inserAtPos(int  la[], int size, int item, int k){
	if(size == 0){
		printf("Invalid array size, please try again.");
		return -1;
	}
	system("cls");
	gotoxy(16,17);printf("Enter item to insert: ");
	scanf("%d", &item);
	gotoxy(16,18);
	printf("Enter position to insert at: ");
	scanf("%d", &k);
	if(inArray(la, size, item)){
		gotoxy(16,19);
		printf("Data item you wish to add already exists in the array...try another!");
		return size;
	}
	int i;
	for(i = size -1; i >= k; i--){
		la[i + 1] = la[i];
	}
	la[k] = item;
	return size+1;
}

void insertFront(int  la[], int *size, int  item){
	if(*size <= 0){
		return;
	}
	system("cls");
	gotoxy(16,17); printf("Enter item to insert: ");
	scanf("%d", &item);
	if(inArray(la, *size, item)){
		printf("item to insert already exists...try again");
		return;
	}
	int i;
	for(i = *size - 1; i >= 0; i--){
		la[i + 1] = la[i];
	}
	la[0] = item;
	*size += 1;
}

void removeAtPos(int la[], int *size, int index){
	if(*size == 0){
		return;
	}
	if(index < 0 || index >= *size){
		return;
	}
	int i;
	for(i = index; i < *size - 1; i++){
		la[i] = la[i + 1];
	}
	*size -= 1;
}

int removeItem(int la[], int size, int item){
	if(size == 0){
		return -1;
	}
	int index = locateIndex(la, size, item);
	if(index == -1){
		return -1;
	}
	removeAtPos(la, &size, index);
	return size;
}

int removeFront(int la[], int *size){
	if(*size == 0){
		return -1;
	}
	int item = la[0];
	int i;
	for(i = 0; i < *size -1; i++){
		la[i] = la[i + 1];
	}
	(*size)--;
	return *size;
}

int locateIndex(int  la[],int size, int item){
	int i;
	for(i = 0; i < size; i++){
		if(item == la[i]){
			return i;
		}
	}
	return -1;
}


int locateItem(int  la[],int size, int item){
	int i;
	for(i = 0; i < size; i++){
		if(item == la[i]){
			return 1;
		}
	}
	return 0;
}

void sortAscending(int la[], int size){
	int i, j;
	for(i = 0; i < size - 1; i++){
		for(j = i+1; j<size -1 -i; j++){
			if(la[i] > la[+1]){
				int temp = la[j];
				la[j] = la[j+1];
				la[j+1] = temp;
			}
		}
	}
	return;
}

void sortDescending(int la[],int size){
	int i, j;
	for(i = 0; i < size - 1; i++){
		for(j = i+1; j<size -1 -i; j++){
			if(la[i] < la[+1]){
				int temp = la[j];
				la[j] = la[j+1];
				la[j+1] = temp;
			}
		}
	}
	return;
}

//void exit(){
//}

