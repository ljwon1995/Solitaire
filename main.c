#include <stdio.h>
#include "solitaireFunction.h"
#include "stack.h"

int main(){
    stack *stock, *playArea[7], *outPutArea[4];
    int loop;
    
    allocStack(&stock, 54);
    for(loop = 0; loop < 7; loop++)
        allocStack(&playArea[loop], 25);
    for(loop = 0; loop < 4; loop++)
        allocStack(&outPutArea[loop], 15);
    
    
    //create cards, mix cards and deal the cards
    makeCardAndPutToStock(stock);
    mixStock(stock);
    dealCards(stock, playArea);
    showCurBoard(*stock, *playArea, *outPutArea);
   
    
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
}
