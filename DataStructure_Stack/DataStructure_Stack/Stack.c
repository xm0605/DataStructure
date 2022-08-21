#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


//***************************    β��βɾ,����ȳ�    ***************************


void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = malloc(sizeof(STDataType)*4);
	assert(pst->a);
	pst->top = 0;
	//top(�±�)��ʼ�� 0,��ʾָ����Ч���ݵ���һ��λ��
	//top(�±�)��ʼ�� -1,�ű�ʾָ�����һ����Ч����
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


//��鲢����
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




//ֻ����ջ������/ɾ������
//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);

	//��鲢����
	StackCheckCapacity(pst);

	(pst->a)[pst->top] = x;
	(pst->top)++;
}
//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	//ջ����,Pop��Ч
	if ((pst->top)>0)
	{
		(pst->top)--;
	}
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack* pst)
{
	assert(pst);
	//����ЧԪ��Ϊ0,����ֹ����
	assert(pst->top > 0);
	return (pst->a)[pst->top - 1];
}
//�����ݸ���
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
//�ж��Ƿ�Ϊ��
bool IsStackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top==0;
	//���ݳ�ʼ����ȷ��
}

//***********************    �����,���ھ�    ***********************














































