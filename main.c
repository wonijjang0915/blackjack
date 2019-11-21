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


//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag


//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
}


//print the card information (e.g. DiaA)
void printCard(void) {
	char card[51];  //ī�� �迭  
	int i;
	
	for(i=0;i<=12;i++) //�迭���� ī�� ��ȣ�� ���� �ο��Ѵ� 
	{
		card[i]=CLV(i+1);
	}
	for(i=13;i<=25;i++)
	{
		card[i]=DIA(i-12);
	}
	for(i=26;i<=38;i++)
	{
		card[i]=HRT(i-25);
	}
	for(i=39;i<=51;i++)
	{
		card[i]=SPD(i-38);
	}
}


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	extern char card[51];
	int Max = 52; // �迭 ����  
	
	int i,n;
	int Tmp;
	
	srand(time(NULL)); // �������� ���� �ο� 
	
	for(i=51;i>=0;i--) // �������� ī�� �迭 
	{
		n=rand()%Max;
		Tmp = card[i];
		card[i]=card[n];
		card[n]=Tmp;
		
	}
}

//get one card from the tray
int pullCard(void) {
}


//playing game functions -----------------------------

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

void offerCards(void){  //ī�带 �÷��̾�鿡�� �����ش�. 
	printf("-------CARD OFFERING-------\n");
	printf("---server :");
}

int getAction(void) {
    printf("---------GAME start---------\n");
	printf(">>>my turn! ---------\n");	
}

int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}



