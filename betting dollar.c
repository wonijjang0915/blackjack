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
	int betdolr; //���ô޷� ���� ����  
	
	printf("-------BETTING STEP-------\n"); // ���� �������� �˸�  
	
	printf("--> your betting (total : $50) : "); // ���� �޷��� �ִ� 50���� �˸�  
	do
    {
    	scanf("%d", &betdolr); //�Է¹��� ���� ���� �޷��� ����  
    	if (50<betdolr) // 50�� �ʰ��ϸ� �ٽ� �Է�  
    	{
    		printf("You only have $50! bet again\n");
    		
    		printf("--> your betting (total : $50) : ");
	        scanf("%d", &betdolr);
		}

	} 
	while(betdolr>50); // 50���Ϸ� �Է��ϸ� �޷� ����  
	printf("-->your betting (total: $50) : %d", betdolr);
	
}
