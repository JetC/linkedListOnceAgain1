//
//  eader.h
//  linkedListOnceAgain
//
//  Created by 孙培峰 on 1312/11/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//

#ifndef linkedListOnceAgain_eader_h
#define linkedListOnceAgain_eader_h


#endif



#define SIZE_OF_STACK 100


typedef struct oneAlsoTwoLinkedStructure{
    
    int data;
    struct oneAlsoTwoLinkedStructure *next;
    struct oneAlsoTwoLinkedStructure *prev;
    
}oneAlsoTwoLinkedStructure, *OneWayLinkedList, *TwoWaysLinkedList;

typedef int DataType;





typedef struct structOfStack{
    
    int stackSize;
    int base;
    int top;
    
}structOfStack, *StackToOperate;


void printOneWayLinkedList(oneAlsoTwoLinkedStructure *listToBePrinted);
StackToOperate initStack(StackToOperate s);
OneWayLinkedList initOneWayLinkedList(int lengthOfTheCreatingList);
TwoWaysLinkedList initTwoWaysLinkedList(int lengthOfTheCreatingList);
void convertMyLinkedListToConverse(oneAlsoTwoLinkedStructure *listToBeConverted);




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
//
//  linkedList.c
//  linkedListOnceAgain
//
//  Created by 孙培峰 on 1312/11/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//









OneWayLinkedList initOneWayLinkedList(int lengthOfTheCreatingList)
{
    OneWayLinkedList p = NULL, r =NULL, list = NULL;
    
    
    //p负责建立新节点,r负责临时存储
    
    list = (OneWayLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
    list->data = 0;
    list->next = NULL;
    list->prev = NULL;
    
    for (int i = 1; i <= lengthOfTheCreatingList; i++)
    {
        p = (OneWayLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
        //r = (OneWayLinkedList)malloc(sizeof(oneWayLinkedStructure));
        
        p->data = i;
        p->next = NULL;
        p->prev = NULL;
        
        if (i == 1)
        {
            list->next = p;
        }
        else if (i >= 2)
        {
            r->next = p;
        }
        
        r = p;
        
    }
    
    return list;
}


TwoWaysLinkedList initTwoWaysLinkedList(int lengthOfTheCreatingList)
{
    TwoWaysLinkedList p = NULL, q = NULL, list = NULL;
    
    list = (TwoWaysLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
    list->data = 0;
    list->next = NULL;
    list->prev = NULL;//初始化list的第一个数据，
    
    //从此处开始进入循环
    for (int i = 1;i <= lengthOfTheCreatingList; i++)
    {
        p = (TwoWaysLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));//每次循环都新建节点p
        p->data = i;//给每次新建的p赋值
        p->next = NULL;//初始化每次新建的p
        p->prev = NULL;
        
        if (i == 1)
        {
            list->next = p;//如果是第一次循环,把list->next指向的地址设为p
        }
        else
        {
            q->next = p;//q此时即为上次循环中的list->next节点,在本次循环中只需要把本次新建的p赋值给q->next(即为list->next->next)
            p->prev = q;//q此时即为上次循环中的list->next节点,本句即是设置q为p的前节点(即list->next->prev)
        }
        
        q = p;//无论是第几次循环,都把q的地址存在p
        //q此时即为本次循环中的list->next节点,在下次循环中只需要把下次新建的p赋值给q->next(即为list->next->next)
        
    }
    
    return list;
    
}


void printOneWayLinkedList(oneAlsoTwoLinkedStructure *listToBePrinted)
{
    OneWayLinkedList p = NULL;
    p = listToBePrinted;
    while (p->next)
    {
        printf("%i\n",p->data);
        p = p->next;
    }
    printf("%i\n",p->data);
}


void convertMyLinkedListToConverse(oneAlsoTwoLinkedStructure *listToBeConverted)
{
    oneAlsoTwoLinkedStructure *p = NULL;
    
    
}



