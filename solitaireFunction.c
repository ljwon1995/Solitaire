//
//  solitaireFunction.c
//  Solitaire
//
//  Created by 이재원 on 28/05/2019.
//  Copyright © 2019 Jae Won. All rights reserved.
//

#include "solitaireFunction.h"



void makeCardAndPutToStock(stack *stock){
    card c;
    int cardNum, cardShape;
    
    for(cardShape = heart; cardShape <= spade; cardShape++){
        for(cardNum = A; cardNum <= K; cardNum++){
            c.shp = cardShape;
            c.num = cardNum;
            c.faceUp = False;
            push(stock, c);
        }
    }
    
}

void swap(stack *stock, int rNum1, int rNum2){
    card temp;
    temp = stock->stc[rNum1];
    stock->stc[rNum1] = stock->stc[rNum2];
    stock->stc[rNum2] = temp;
    
}

void mixStock(stack *stock){ //choose random 2 numbers between 0~51 and switch.
    int rNum1, rNum2;
    int loop;
    
    srand((int)time(NULL));
    
    for(loop = 0; loop < MIX_TIMES; loop++){
        rNum1 = rand() % 52;
        rNum2 = rand() % 52;
        swap(stock, rNum1, rNum2);
    }
}

void dealCards(stack *stock, stack *playArea[7]){ //deal cards to stock, playArea.
    int loop1, loop2;
    card c;
    
    for(loop1 = 0; loop1 < 7; loop1++){
        for(loop2 = loop1; loop2 < 7; loop2++){
            c = pop(stock);
            
            if(loop2 == loop1)
                c.faceUp = True;
            
            push(playArea[loop2], c);
        }
    }    
}

void printByRule(card c){
    char specialChar[5];
    char specialNum;
    
    
    if(c.faceUp == False)
        printf(" ? ");
    
    else{
        switch (c.shp) {
            case heart:
                strcpy(specialChar, "♥");
                break;
            case diamond:
                strcpy(specialChar, "◆");
                break;
            case clover:
                strcpy(specialChar, "♣");
                break;
            case spade:
                strcpy(specialChar, "♠");
                break;
                
            default:
                break;
        }
        switch (c.num) {
            case A:
                specialNum = 'A';
                break;
            case J:
                specialNum = 'J';
                break;
            case Q:
                specialNum = 'Q';
                break;
            case K:
                specialNum = 'K';
                break;
            default:
                break;
        }
        
        if(c.num == A || (c.num >= J) ){
            printf("%s %c", specialChar, specialNum);
        }
        else{
            printf("%s%2d", specialChar, c.num);
        }
    }
    
}

int lineToPrint(stack *playArea[]){
    int max, pileNum;
    
    max= playArea[0]->top;
    for(pileNum = 0; pileNum < PLAYPILE_NUM; pileNum++)
        if(max < playArea[pileNum]->top)
            max = playArea[pileNum]->top;
    
    max++;
    if(max < MIN_LINES)
        return MIN_LINES;
    else
        return max;
}

void showCurBoard(stack stock, stack waste, stack* playArea[7], stack* outputArea[4]){
    int maxLine, line, pileNum;
    //check how many lines we need to print.
    
    maxLine = lineToPrint(playArea);
    for(line = 0; line < maxLine; line++){
        //from stock ifExist, print by rule ifnot print X
        if(line < 4){
            if(line == 0){
                if(isEmpty(stock))
                    printf(" X ");
                else{
                    printByRule(stock.stc[stock.top]);
                }
            }
            
            else{
                if(waste.top - 3 + line < 0){
                    printf(" X ");
                }
                else{
                    printByRule(waste.stc[waste.top - 3 + line]);
                }
            }
        }
        else{
            printf("   ");
        }
        
        
        printf("     ");
        //from playarea pile 0~6, ifexist print by rule ifnot print space
        for(pileNum = 0; pileNum < PLAYPILE_NUM; pileNum++){
            if(line <= playArea[pileNum]->top)
                printByRule(playArea[pileNum]->stc[line]);
            else{
                printf("   ");
            }
            printf("  ");
        }
        printf("     ");
        
        //from outputArea ifexist print by manual
        if(line < OUTPUTPILE_NUM){
            if(isEmpty(*outputArea[line])){
                printf(" X ");
            }
            else{
                printByRule(outputArea[line]->stc[outputArea[line]->top]);
            }
        }
        
        
        
        printf("\n");
    }
    
    printf("\n\n\n\n");

}

movement getMove(){ //get Movement command from user
    movement move;

    move.error = False;
    
    printf("Move from?(1 : Stock, 2 : Waste, 3 : outputArea, A~G : playArea) : ");
    scanf("%c", &move.from);
    
    switch (move.from) {
        case '1':
            return move;
            break;
        case '2':
        case '3':
        case 'A':
        case 'a':
        case 'B':
        case 'b':
        case 'C':
        case 'c':
        case 'D':
        case 'd':
        case 'E':
        case 'e':
        case 'F':
        case 'f':
        case 'G':
        case 'g':
            printf("Move to?(1 : outputArea, A~G : playArea) : ");
            scanf("%c", &move.to);
            switch (move.to) {
                case '1':
                    return move;
                    break;
                case 'A':
                case 'a':
                case 'B':
                case 'b':
                case 'C':
                case 'c':
                case 'D':
                case 'd':
                case 'E':
                case 'e':
                case 'F':
                case 'f':
                case 'G':
                case 'g':
                    switch (move.from) {
                        case '2':
                        case '3':
                            break;
                            
                        default:
                            printf("How many cards? : ");
                            scanf("%d", &move.amount);
                            break;
                    }
                
                    return move;
                    break;
                    
                default:
                    move.error = True;
                    return move;
                    break;
            }
            break;
            
        default:
            move.error = True;
            return move;
            break;
    }
}

void moveCard(){ // move cards according to user's comand.
    /*
     For Stock
     1. pop one card, open it, and push to wasteArea;
     2. if all of the cards in stock run out, pop from waste, hide it, and push to stock (reset)
     
     For waste
     1. pop one and push to playArea if valid.
     2. pop one and push to output area if valid.
     
     For playArea
     1. pop cards(could be more than one) and push it to temp and again pop and push to destin playArea if valid
     2. pop a card and push it to output area if valid
     3. if no opened card on top in pile open the nearest card.
     
     For outputArea
     1. pop a card and push it to playArea if valid
     */
    
    //1 : Stock, 2 : Waste, 3. outputArea, A~G : playArea
    
    

}


