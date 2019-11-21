#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

//mix the card sets and put in the array
int mixCardTray(void) {
	extern char card[51];
	int Max = 52; // 배열 길이  
	
	int i,n;
	int Tmp;
	
	srand(time(NULL)); // 랜덤으로 숫자 부여 
	
	for(i=51;i>=0;i--) // 랜덤으로 카드 배열 
	{
		n=rand()%Max;
		Tmp = card[i];
		card[i]=card[n];
		card[n]=Tmp;
		
	}
}
