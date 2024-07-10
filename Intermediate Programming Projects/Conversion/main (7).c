#include <stdio.h>
#include "gotoxy.h"

int main (){
	
	int i, j;
	for(i = 0; i < 10; i++){
		gotoxy(10, 10+i);
//		gotoxy(15, 15); printf("Jam Pugi");
		for(j = 0; j < 10; j++){
			if(i == 0){
				printf("_");
			}
			
			if(i != 0 && i != 9 && j != 0 && j != 9){
				printf("_");
			}
			
			if(j== 0 && i > 0 && i < 9){
				printf("|");
			}
				
			
			if(j== 9 && i > 0 && i < 9){
				printf("|");
			}
				
		}
		printf("\n");  
		}
		
		
		gotoxy(11, 12); printf("Jam Pugi");
	}
	
