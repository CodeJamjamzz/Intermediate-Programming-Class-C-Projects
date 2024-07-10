#include <stdio.h>


//REVIEW
void createArray(int la[], int size){
	
	int i, j, num;
	gotoxy(1,2);printf("Enter [5] Elements in Array: ");
	
	for(i = 0; i < size; i++){
		gotoxy(1,3+i);printf("[%d]: ", i); scanf("%d", &num);
				gotoxy(5,18);printf("                                                ");
		for(j = 0; j < i; j++){
			if(la[j] == num){
				gotoxy(5,18);printf("inputted integer already exists, try another num");
				i--;
				break;
			}
		}
		if (j == i){
			la[i] = num;
		}
	}
}

//DONE
void printArray(int la[], int size){
	int i;
	printf("ARRAY: ");
	for(i = 0; i < size; i++){
		printf("%d ", la[i]);
	}
}

//DONE
int inserAtPos(int la[], int size, int item, int k){
	int choose = 0, i, temp = 0;
	
	choose = locateItem(la,size,item);
	if (choose == 1){
		gotoxy(1,2);printf("Data item you wish to add already exists in the array...");
		gotoxy(1,3);printf("try another!");
		return size;
	} else {
		for(i = size; i >= k; i--){
			if(i == k){
			la[k] = item;
		} else {
			temp = la[i];
			la[i] = la[i-1];
			la[i-1] = temp;
			}
		}
		
	size++;
	return size;
	}
		
}

//REVIEW
void insertFront(int la[], int *size, int item){
	int i, temp = 0, choose;
	
	choose = locateItem(la,*size,item);
	if (choose == 1){
		gotoxy(1,2);printf("Data item you wish to add already exists in the array...");
		gotoxy(1,3);printf("try another!");
		return;
	} else {
	(*size)++;	
		for(i = *size; i >= 0; i--){
			if(i == 0){
				la[0] = item;
			} else {
				temp = la[i];
				la[i] = la[i-1];
				la[i-1] = temp;
			}
		}
	}
	return;
}

//DONE
void removeAtPos(int la[], int *size, int index){
	int i, temp = 0;
	la[index] = 0;
	
	for(i = index; i < *size; i++){
		temp = la[i];
		la[i] = la[i+1];
		la[i+1] = temp;
	}
	
	(*size)--;
}

//REVIEW
int removeItem(int la[], int size, int item){
	int choose,i;
	choose = locateIndex(la,size,item);
	if(choose == -1){
		return -1;
	} else {
		removeAtPos(la, &size, choose);
		return size;
	}
}
//DONE
int removeFront(int la[], int size){
	int i, temp = 0;
	la[0] = 0;
	for(i = 0; i < size; i++){
		temp = la[i];
		la[i] = la[i+1];
		la[i+1] = temp;
	}
	size--;
	return size;
}
//DONE
int locateIndex(int la[], int size, int item){
	int i;
	for(i = 0; i < size; i++){
		if(la[i] == item){
			return i;
		}
	}
	
	return -1;
}
//DONE
int locateItem(int la[], int size, int item){
	int i;
	for(i = 0; i < size; i++){
		if(la[i] == item){
			return 1;
		}
	}
	
	return 0;
}

//DONE
void sortAscending(int la[], int size){
	
	int la2[size];
	int i, j, temp = 0;
	
	for(i = 0; i < size; i++){
		la2[i] = la[i];
	}
	
	for(i = 0; i < size - 1; i++){
	    int min = i;
	        for(j = i + 1; j < size; j++){
	            if (la2[min] > la2[j]){
	                min = j;
	            }
	        }
	        temp = la2[i]; 
	        la2[i] = la2[min];
	        la2[min] = temp;
	    }
	    
	printf("ARRAY list in Ascending Order: ");
	gotoxy(1,2);
	for(i = 0; i < size; i++){
		printf("%d ", la2[i]);
	}
	
	return;
}

//DONE
void sortDescending(int la[], int size){
	int la2[size];
	int i, j, temp = 0;
	
	for(i = 0; i < size; i++){
		la2[i] = la[i];
	}
	
	for(i = 0; i < size - 1; i++){
	    int min = i;
	        for(j = i + 1; j < size; j++){
	            if (la2[min] < la2[j]){
	                min = j;
	            }
	        }
	        temp = la2[i]; 
	        la2[i] = la2[min];
	        la2[min] = temp;
	    }
	    
	printf("ARRAY list in Descending Order: ");
	gotoxy(1,5);
	for(i = 0; i < size; i++){
		printf("%d ", la2[i]);
	}
	return;
}


