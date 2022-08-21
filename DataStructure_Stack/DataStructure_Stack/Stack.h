#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


//***************************    尾插尾删,后进先出    ***************************



//静态(数组实现)栈
/*
typedef int STDataType;
#define MAX 1000
typedef struct Stack
{
	STDataType a[MAX];			//必须空间足够大
	int  top;					//栈顶下标
}Stack;
*/


//动态(数组实现)栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;				//必须空间足够大
	int  top;					//栈顶下标
	int	 capacity;				//当前总容量
}Stack;
//(数组实现)栈只允许使用栈顶位置.



void StackInit(Stack* pst);
void StackDestory(Stack* pst);

void StackCheckCapacity(Stack* pst);

//只会在栈顶插入/删除数据
//入栈
void StackPush(Stack* pst,STDataType x);
//出栈
void StackPop(Stack* pst);

//读取栈顶元素
STDataType StackTop(Stack* pst);
//求数据个数
int StackSize(Stack* pst);
//判断是否为空
bool IsStackEmpty(Stack* pst);





















