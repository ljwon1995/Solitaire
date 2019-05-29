//
//  stack.c
//  PrefixEvalAndTrans
//
//  Created by 이재원 on 14/05/2019.
//  Copyright © 2019 Jae Won. All rights reserved.
//

#include "stack.h"

void allocStack(stack** s, int capa){
    *s = (stack*)calloc(1, sizeof(stack));
    (*s)->stc = (card*)calloc(capa, sizeof(card));
    (*s)->capacity = capa;
    (*s)->top = -1;
}

boolean isEmpty(stack s){
    if(s.top == -1)
        return True;
    return False;
}

boolean isFull(stack s){
    if(s.top == s.capacity - 1)
        return True;
    return False;
}

void stackFull(stack* s){
    s->capacity *= 2;
    s->stc = (card*)realloc(s->stc, s->capacity * sizeof(card));
}

void stackEmpty(){
    fprintf(stderr, "ERROR! Stack is empty");
    exit(EXIT_FAILURE);
}

void push(stack* s, card e){
    if(isFull(*s))
        stackFull(s);
    s->stc[++(s->top)] = e;
}

card pop(stack* s){
    if(isEmpty(*s))
        stackEmpty();
    return s->stc[(s->top)--];
}

void stackFree(stack** s){
    free((*s)->stc);
    free(*s);
}
