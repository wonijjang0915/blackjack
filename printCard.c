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


//print the card information (e.g. DiaA)
void printCard(void) {
	static char card[51];  //ī�� �迭  
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


