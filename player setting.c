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

//player settiing
int configUser(void) {
	int ply; //�÷��̾� ���� 
    
    printf("Input the number of players (MAX:5) : "); // �÷��̾� �ο��� �Է� 
    do
    {
    	scanf("%d", &ply); //�Է��� ���� �÷��̾�� �޴´� 
    	if (5<ply) // 5�� �̻��̸� �ʰ��ϹǷ� �ٽ� �÷��̾� �Է� 
    	{
    		printf("Too many players!\n");
    		
    		printf("Input the number of players (MAX:5) : ");
	        scanf("%d", &ply);
		}
		else if (ply<1) // 1���� ������ ������ �Ұ����ϹǷ� �ٽ� �÷��̾� �Է� 
		{
			printf("Too few players!\n");
	    	
	    	printf("Input the number of players (MAX:5) : ");
	        scanf("%d", &ply);
		}

	} 
	while(ply>5||ply<1); //1~5�� ���̷� �÷��̾� �Է��ϸ� ���� ����  
	printf("-->card is mixed and put into the tray\n");
	
}
