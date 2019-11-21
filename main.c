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
	char card[51];  //카드 배열  
	int i;
	
	for(i=0;i<=12;i++) //배열마다 카드 번호와 폼을 부여한다 
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

//get one card from the tray
int pullCard(void) {
}


//playing game functions -----------------------------

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

void offerCards(void){  //카드를 플레이어들에게 나눠준다. 
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



