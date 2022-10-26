/******************************************************************************

 File Name: terminal.c

 Description: Source file for terminal Module

 Author:Roqaia Khalid Wagih
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "terminal.h"
#include "card.h"

uint8_t TMTD[25] = { 0 };

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	//ask for the transaction data and store it in terminal data.
	printf("plase_enter_the_card_transaction_date_in_the_format_DD/MM/YYYY");

	// function get
	int i = 0;
	char X[25] = { 0 };
	int gets(name);
	for (i = 0; i < 25; i++)
	{
		TMTD[i] = X[i];
	}
	//check if Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022
	if ((strlen(TMTD) == 10))
	{
		// printf("TRUE");
		strcpy_s(termData->transactionDate, sizeof(termData->transactionDate), TMTD);
		return OK;
	}
	else
	{

		//If the transaction date is NULL, less than 10 characters or wrong format will return WRONG_DATE error
	//printf("FALSE");
		return WRONG_DATE;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData) {
	//store each date into string

	char card[6];
	strcpy_s(card, sizeof(card), cardData->cardExpirationDate);
	char term[6];
	int i = 5;
	for (i = 0; i < 5; i++)
	{
		term[i] = termData->transactionDate[i];
	}
	//compares the card expiry date with the transaction date with if condition 
	int result;
	result = strcmp(card, term);
		if (result == 0) {
			return OK;
		}
		else if (){

		}
		else
		{

			//if the card expiration date is before the transaction date will return EXPIRED_CARD
			return EXPIRED_CARD;
		}
}

/*EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {

	char Date[10];
	char TDATE[10];
	time_t t = time(NULL);
	struct tm* tm = localtime(&t);


	printf("Transaction_Date: %d/%02d/%02d \n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
	sprintf_s(TDATE, " % d / % 02d / % 02d \n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

	/*int i = 0;
    char name[25] = { 0 };
    int gets(name);
    for (i = 0; i < 25; i++)
    {
        CDHN[i] = name[i];
    }
	strcpy_s(termData->transactionDate, sizeof(termData->transactionDate), TDATE);
	sprintf_s(Date, "%02d/%02d \n", tm->tm_mon + 1, tm->tm_year - 100);
	printf("%s", Date);

	return OK_T;



	printf("Transaction_Date: %d/%02d/%02d \n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);


	return OK_T;
}*/