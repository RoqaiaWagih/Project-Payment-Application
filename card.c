/******************************************************************************

 File Name: card.c

 Description: Source file for Card Module

 Author:Roqaia Khalid Wagih
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "card.h"

uint8_t CDHN[25] = {0};
uint8_t CDEX[25] = { 0 };
char CDPN[24] = { 0 };


EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

    //ask to get cardholder's name and store it into card data.
    //ST_cardData_t card;
    //uint8_t CDHN[25];

    printf("plase_enter_cardholder's_name");
   // gets(CDHN);
    int i = 0;
    char name[25] = { 0 };
    int gets(name);
    for (i = 0; i < 25; i++)
    {
        CDHN[i] = name[i];
    }
    ///****uint8_t fgets(cardData->cardHolderName, max, stdin);
    //uint8_t CDHN = card.cardHolderName;
    //printf("cardholder's_name %s", CDHN);******/

    //name is 24 characters string max and 20 min.

    if ((strlen(CDHN) <= 24) && (strlen(CDHN) >= 20))
    {
        //printf("TRUE");
        strcpy_s(cardData->cardHolderName, sizeof(cardData->cardHolderName), CDHN);
        return OK;
    }
    else
    {
        //name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error
       // printf("FALSE");
        return WRONG_NAME;
    }
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
    //ask for the card expiry date and store it in card data.
    printf("plase_enter_the_card_expiry_date_in_the_format_(MM/YY)");

    // function get
    int i = 0;
    char X[25] = { 0 };
    int gets(name);
    for (i = 0; i < 25; i++)
    {
        CDEX[i] = X[i];
    }
    //check if Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25"
    if ((strlen(CDEX) == 6))
    {
       // printf("TRUE");
        strcpy_s(cardData->cardExpirationDate, sizeof(cardData->cardExpirationDate), CDEX);
        return OK;
    }
    else
    {
        //If the card expiry date is NULL, less or more than 5 characters, or has the wrong format return wrong 
        //printf("FALSE");
        return WRONG_EXP_DATE;

    }

}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
    //ask for the card's Primary Account Number and store it in card 
    printf("plase_enter_the_card's_Primary_Account_Number");

    //get function 
    int i = 0;
    char X[24] = { 0 };
    int gets(name);
    for (i = 0; i < 24; i++)
    {
        CDPN[i] = X[i];
    }
    //check PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
    if ((strlen(CDPN) <= 19 && strlen(CDPN) <= 16))
    {
       // printf("TRUE");
        strcpy_s(cardData->primaryAccountNumber, sizeof(cardData->primaryAccountNumber), CDPN);
        return OK;
    }
   
    else
    {
        //If the PAN is NULL, less than 16 or more than 19 characters, will return
        //printf("FALSE");
        return WRONG_PAN;
    }
}