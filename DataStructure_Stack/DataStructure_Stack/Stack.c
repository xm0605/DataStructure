#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


//***************************    尾插尾删,后进先出    ***************************


void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = malloc(sizeof(STDataType)*4);
	assert(pst->a);
	pst->top = 0;
	//top(下标)初始赋 0,表示指向有效数据的下一个位置
	//top(下标)初始赋 -1,才表示指向最后一个有效数据
	pst->capacity = 4;
}
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}


//检查并扩容
void StackCheckCapacity(Stack* pst)
{
	assert(pst);
	if (pst->top >= pst->capacity)
	{
		STDataType* tmp = realloc(pst->a, sizeof(Stack) * (pst->capacity *2));
		if (!tmp)
		{
			printf("relloc fail!\n");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
}




//只会在栈顶插入/删除数据
//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);

	//检查并扩容
	StackCheckCapacity(pst);

	(pst->a)[pst->top] = x;
	(pst->top)++;
}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	//栈空了,Pop无效
	if ((pst->top)>0)
	{
		(pst->top)--;
	}
}

//读取栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	//若有效元素为0,则中止报错
	assert(pst->top > 0);
	return (pst->a)[pst->top - 1];
}
//求数据个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
//判断是否为空
bool IsStackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top==0;
	//根据初始条件确定
}

//***********************    低耦合,高内聚    ***********************














































