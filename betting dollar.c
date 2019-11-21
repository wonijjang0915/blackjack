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

//betting
int betDollar(void) {
	int betdolr; //베팅달러 변수 선언  
	
	printf("-------BETTING STEP-------\n"); // 베팅 스텝임을 알림  
	
	printf("--> your betting (total : $50) : "); // 베팅 달러가 최대 50임을 알림  
	do
    {
    	scanf("%d", &betdolr); //입력받은 값을 베팅 달러로 받음  
    	if (50<betdolr) // 50을 초과하면 다시 입력  
    	{
    		printf("You only have $50! bet again\n");
    		
    		printf("--> your betting (total : $50) : ");
	        scanf("%d", &betdolr);
		}

	} 
	while(betdolr>50); // 50이하로 입력하면 달러 베팅  
	printf("-->your betting (total: $50) : %d", betdolr);
	
}
