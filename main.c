#include <stdio.h>
#include "solitaireFunction.h"
#include "stack.h"


int main(){
    stack *stock, *playArea[7], *outputArea[4], *wasteArea;
    int loop;
    
    allocStack(&stock, MAX_STOCK__CARDNUM);
    allocStack(&wasteArea, MAX_STOCK__CARDNUM);
    for(loop = 0; loop < PLAYPILE_NUM; loop++)
        allocStack(&playArea[loop], MAX_PLAYPILE_CARDNUM);
    for(loop = 0; loop < OUTPUTPILE_NUM; loop++)
        allocStack(&outputArea[loop], MAX_OUTPUTPILE_CARDNUM);
    
    
    
    //create cards, mix cards and deal the cards/
    makeCardAndPutToStock(stock);
    mixStock(stock);
    dealCards(stock, playArea);
    showCurBoard(*stock, *wasteArea, playArea, outputArea);
   
/*
    while(!All the cards are set in the output area){
        //get movement input from user
        getMove();
        //when it is possible movement, move it,
        while(move != valid){
        //when it is not show Error message and get input again.
            printErrorMessage();
            getMove();
        }
        moveCard();
        showCurBoard();
    }
 
 
 
 free all of the stacks
    */
    
    
}
