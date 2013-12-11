//
//  stack.c
//  linkedListOnceAgain
//
//  Created by 孙培峰 on 1312/11/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_STACK 100


typedef struct structOfStack{
    
    int stackSize;
    int base;
    int top;
    
}structOfStack, *StackToOperate;
StackToOperate initStack(StackToOperate s)
{
    s->base = (int)malloc(sizeof(int)*SIZE_OF_STACK);
    if (!s->base)
    {
        printf("Failed to find s->base");
        exit(100);
    }
    s->top = s->base;
    s->stackSize = SIZE_OF_STACK;
    
    return s;
}


//
//StackToOperate pushElementIntoStack(int lengthOfTheCreatingStack)
//{
//    StackToOperate stack,q,p;
//    stack = (StackToOperate)malloc(sizeof(structOfStack));
//    stack->data = 0;
//    stack->top = NULL;
//    stack->base = stack;
//
//}