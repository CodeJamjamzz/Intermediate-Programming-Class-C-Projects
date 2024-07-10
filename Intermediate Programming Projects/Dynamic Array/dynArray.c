#include <stdio.h>
#include <stdlib.h>

int getSize(){
	int n;
	printf("Enter size: ");
	scanf("%d", &n);
	return n;
}
void createArray(int* LA, int size){
	int i;
	printf("Enter elements: ");
	for(i = 0; i < size; i++){
		scanf("%d", LA+i);
	}
	return;
}
void printArray(int* LA, int size){
	int i;
	printf("Array: ");
	for(i = 0; i < size; i++){
		printf("%d ", *(LA+i));
	}
	return;
}
int sum(int* LA, int size){
	int sum = 0, i;
	for(i = 0; i < size; i++){
		sum += *(LA+i);
	}
	return sum;
}
int largest(int* LA, int size){
	int lar = *(LA+0), i;
	for(i = 0; i < size; i++){
		if(lar < *(LA+i)){
			lar = *(LA+i);
		}
	}
	return lar;
}
int smallest(int* LA, int size){
	int smol = *(LA+0), i;
	for(i = 0; i < size; i++){
		if(smol > *(LA+1)){
			smol = *(LA+i);
		}
	}
	return smol;
}
void resize(int* LA, int* size){
	*size *= 2;
}
int addElement(int*LA, int* size, int count, int item){
	LA = (int*)realloc(LA, *size * sizeof(int));
	*(LA + count) = item;
	return count+=1;
}

void menu(){
	int i, j, choice, count, lar, smol, sumOfArr, size, item;
	int *LA;
	while(choice){
		printf("\n\n~~~ARRAY~~~");
	 printf("\n[1]CREATEArray");
	 printf("\n[2]PRINTArray");
	 printf("\n[3]SUM");
	 printf("\n[4]LARGEST");
	 printf("\n[5]SMALLEST");
	 printf("\n[6]RESIZE");
	 printf("\n[7]ADD");
	 printf("\n[8]EXIT");
	 printf("\n\nEnter a valid choice[1-8]: ");
	 scanf("%d",&choice);
	 while(choice < 1 || choice > 8){
	 	printf("Invalid Input - Try again: ");
	 	scanf("%d", &choice);
	 }
	 
	 	switch(choice){
		 	case 1:
		 		size = getSize();
		 		LA = (int*)calloc(size, sizeof(int));
		 		createArray(LA, size);
		 		count = size;
		 		break;
		 	case 2:
		 		if(!count){
		 			printf("No array made");
		 			continue;
				 }
		 		printArray(LA, count);
		 		break;
		 	case 3:
		 		if(!count){
		 			printf("No array made");
		 			continue;
				 }
		 		sumOfArr = sum(LA, count);
		 		printf("\nSum of Array: %d", sumOfArr);
		 		break;
		 	case 4:
		 		if(!count){
		 			printf("No array made");
		 			continue;
				 }
		 		lar = largest(LA, count);
		 		printf("\nLargest Number: %d", lar);
		 		break;
		 	case 5:
		 		if(!count){
		 			printf("No array made");
		 			continue;
				 }
		 		smol = smallest(LA, count);
		 		printf("\nSmallest Number: %d", smol);
		 		break;
		 	case 6:
		 		if(!count){
		 			printf("No array made");
		 			continue;
				 }
		 		resize(LA, &size);
		 		printf("\nCurrent size: %d", size);
		 		break;
		 	case 7:
		 		if(!count){
		 			printf("No array made");
		 			continue;
				 }
				 if(count == size){
				 	printf("Array is not resized");
				 	continue;
				 }
		 		printf("\nEnter item: ");
		 		scanf("%d", &item);
		 		count = addElement(LA, &size, count, item);
		 		printf("\nNumber of elements: %d", count);
		 		break;
		 	case 8:
		 		printf("\nExiting Program...");
		 		exit(1);
		 		break;
		 }
	 
	}
	return;
}
