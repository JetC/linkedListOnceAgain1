//
//  main.c
//  linkedListOnceAgain
//
//  Created by 孙培峰 on 1312/07/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct oneAlsoTwoLinkedStructure{
    
    int data;
    struct oneAlsoTwoLinkedStructure *next;
    struct oneAlsoTwoLinkedStructure *prev;
    
}oneAlsoTwoLinkedStructure, *OneWayLinkedList, *TwoWaysLinkedList;


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
    list->prev = NULL;
    
    for (int i = 1;i <= lengthOfTheCreatingList; i++)
    {
        p = (TwoWaysLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
        p->data = i;
        p->next = NULL;
        p->prev = NULL;
        
        if (i == 1)
        {
            list->next = p;
        }
        else
        {
            q->next = p;
            p->prev = q;
        }
        q = p;
        
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







int main(int argc, const char * argv[])
{

    //printOneWayLinkedList(initOneWayLinkedList(50));
    printOneWayLinkedList(initTwoWaysLinkedList(5));
    printf("The first num is %i, and 2nd num is %i, its  prev is %i\n",
           
           (int)initTwoWaysLinkedList(5)->next->data,
           (int)initTwoWaysLinkedList(5)->next->next->data,
           (int)initTwoWaysLinkedList(5)->next->next->prev->data
           
          );
    return 0;
}

