//
//  main.c
//  linkedListOnceAgain
//
//  Created by 孙培峰 on 1312/07/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#define SIZE_OF_STACK 100
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//typedef struct oneAlsoTwoLinkedStructure{
//    
//    int data;
//    struct oneAlsoTwoLinkedStructure *next;
//    struct oneAlsoTwoLinkedStructure *prev;
//    
//}oneAlsoTwoLinkedStructure, *OneWayLinkedList, *TwoWaysLinkedList;
//
typedef int DataType;


typedef struct{
    SElemType *base;
    SElemType *top;
    int stackSize;
} Sqstack;



Status initStack(Sqstack &s)//这里提示&的使用有问题.....剩下几个函数的问题类似
{
    s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s.base)
    {
        exit(100);
    }
    s.top = s.base;
    s.stackSize = STACK_INIT_SIZE;
    return OK;
}

Status getTop(Sqstack s,SElemType &e)
{
    if (s.top == s.base)
    {
        e = *(s.top - 1);
        return OK;
    }
}

Status push(Sqstack &s,SElemType e)
{
    if (s.top-s.base >= s.stackSize)
    {
        s.base = (SElemType)realloc(s.base, (s.stackSize + STACKINCREMENT)*sizeof(SElemType));
        if (!s.base)
        {
            exit(101);
        }
        s.top = s.base + s.stackSize;
        s.stackSize += STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

Status pop(Sqstack &s,SElemType e)
{
    if (s.top == s.base)
    {
        return ERROR;
    }
    e=*--s.top;
    return OK;
}



//OneWayLinkedList initOneWayLinkedList(int lengthOfTheCreatingList)
//{
//    OneWayLinkedList p = NULL, r =NULL, list = NULL;
//    
//    
//    //p负责建立新节点,r负责临时存储
//    
//    list = (OneWayLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
//    list->data = 0;
//    list->next = NULL;
//    list->prev = NULL;
//    
//    for (int i = 1; i <= lengthOfTheCreatingList; i++)
//    {
//        p = (OneWayLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
//        //r = (OneWayLinkedList)malloc(sizeof(oneWayLinkedStructure));
//        
//        p->data = i;
//        p->next = NULL;
//        p->prev = NULL;
//        
//        if (i == 1)
//        {
//            list->next = p;
//        }
//        else if (i >= 2)
//        {
//            r->next = p;
//        }
//        
//        r = p;
//        
//    }
//    
//    return list;
//}
//
//
//TwoWaysLinkedList initTwoWaysLinkedList(int lengthOfTheCreatingList)
//{
//    TwoWaysLinkedList p = NULL, q = NULL, list = NULL;
//    
//    list = (TwoWaysLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));
//    list->data = 0;
//    list->next = NULL;
//    list->prev = NULL;//初始化list的第一个数据，
//    
//    //从此处开始进入循环
//    for (int i = 1;i <= lengthOfTheCreatingList; i++)
//    {
//        p = (TwoWaysLinkedList)malloc(sizeof(oneAlsoTwoLinkedStructure));//每次循环都新建节点p
//        p->data = i;//给每次新建的p赋值
//        p->next = NULL;//初始化每次新建的p
//        p->prev = NULL;
//        
//        if (i == 1)
//        {
//            list->next = p;//如果是第一次循环,把list->next指向的地址设为p
//        }
//        else
//        {
//            q->next = p;//q此时即为上次循环中的list->next节点,在本次循环中只需要把本次新建的p赋值给q->next(即为list->next->next)
//            p->prev = q;//q此时即为上次循环中的list->next节点,本句即是设置q为p的前节点(即list->next->prev)
//        }
//        
//        q = p;//无论是第几次循环,都把q的地址存在p
//        //q此时即为本次循环中的list->next节点,在下次循环中只需要把下次新建的p赋值给q->next(即为list->next->next)
//        
//    }
//    
//    return list;
//    
//}
//
//
//void printOneWayLinkedList(oneAlsoTwoLinkedStructure *listToBePrinted)
//{
//    OneWayLinkedList p = NULL;
//    p = listToBePrinted;
//    while (p->next)
//    {
//        printf("%i\n",p->data);
//        p = p->next;
//    }
//    printf("%i\n",p->data);
//}
//
//
//void convertMyLinkedListToConverse(oneAlsoTwoLinkedStructure *listToBeConverted)
//{
//    oneAlsoTwoLinkedStructure *p = NULL;
//    
//    
//}
//
//




int main(int argc, const char * argv[])
{
    
    //printOneWayLinkedList(initOneWayLinkedList(5));
    //printOneWayLinkedList(initTwoWaysLinkedList(5));
    // printf("The first num is %i, and 2nd num is %i, its  prev is %i\n",
    
    //        (int)initTwoWaysLinkedList(5)->next->data,
    //        (int)initTwoWaysLinkedList(5)->next->next->data,
    //        (int)initTwoWaysLinkedList(5)->next->next->prev->data
    
    //       );
    
    return 0;
    
}

