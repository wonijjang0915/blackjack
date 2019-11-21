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
	int ply; //플레이어 선언 
    
    printf("Input the number of players (MAX:5) : "); // 플레이어 인원을 입력 
    do
    {
    	scanf("%d", &ply); //입력한 값을 플레이어로 받는다 
    	if (5<ply) // 5명 이상이면 초과하므로 다시 플레이어 입력 
    	{
    		printf("Too many players!\n");
    		
    		printf("Input the number of players (MAX:5) : ");
	        scanf("%d", &ply);
		}
		else if (ply<1) // 1명보다 적으면 게임이 불가능하므로 다시 플레이어 입력 
		{
			printf("Too few players!\n");
	    	
	    	printf("Input the number of players (MAX:5) : ");
	        scanf("%d", &ply);
		}

	} 
	while(ply>5||ply<1); //1~5명 사이로 플레이어 입력하면 게임 시작  
	printf("-->card is mixed and put into the tray\n");
	
}
