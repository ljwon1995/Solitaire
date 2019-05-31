//
//  solitaireFunction.h
//  Solitaire
//
//  Created by 이재원 on 28/05/2019.
//  Copyright © 2019 Jae Won. All rights reserved.
//

#ifndef solitaireFunction_h
#define solitaireFunction_h

#include <stdio.h>
#include "card.h"
#include "stack.h"
#include <time.h>
#include <string.h>

#define MAX_STOCK__CARDNUM 54
#define MAX_PLAYPILE_CARDNUM 25
#define MAX_OUTPUTPILE_CARDNUM 15
#define PLAYPILE_NUM 7
#define OUTPUTPILE_NUM 4
#define MIX_TIMES 500
#define MIN_LINES 4

typedef struct{
    char from;
    char to;
    int amount;
    boolean error;
}movement;


void makeCardAndPutToStock(stack *stock);
void mixStock(stack *stock);
void dealCards(stack *stock, stack *playArea[7]); //deal cards to stock, playArea.
void showCurBoard(stack stock, stack waste, stack* playArea[7], stack *outputArea[4]); //drawing current board
movement getMove(void); //get Movement command from user
//printMovErrorMessage(); //print movement can't be allowed.
void moveCard(); // move cards according to user's comand.


#endif /* solitaireFunction_h */
