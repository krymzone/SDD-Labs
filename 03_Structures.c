#include <stdio.h>
#define CARD_NUMBER_SIZE 16

struct Date 
{
	char month;
	char year; //only last 2 letter are stored
};

typedef struct Date Date;

struct BankCard 
{
	char* holder; // 4 bytes
	char card_no[CARD_NUMBER_SIZE + 1]; // 17 bytes
	Date exp_date; // 2 bytes
	char* issuer; // 4 bytes
	float balance; //4 bytes

};//

typedef struct BankCard BankCard;

int main() 
{
	printf("Size of structure BankCARD = %d", sizeof(BankCard));

	return 0;
}