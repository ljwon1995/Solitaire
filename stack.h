//
//  stack.h
//
//  Created by 이재원 on 14/05/2019.
//  Copyright © 2019 Jae Won. All rights reserved.
//

#ifndef stack_h
#define stack_h
#include <stdio.h>
#include <stdlib.h>
#include "card.h"

typedef struct{
    int capacity;
    int top;
    card *stc;
}stack;

void allocStack(stack** s, int capa);
boolean isEmpty(stack s);
boolean isFull(stack s);
void stackFull(stack* s);
void stackEmpty(void);
void push(stack* s, card e);
card pop(stack* s);
void stackFree(stack**s);



#endif /* stack_h */
