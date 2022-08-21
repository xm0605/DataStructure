#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


//***************************    β��βɾ,����ȳ�    ***************************



//��̬(����ʵ��)ջ
/*
typedef int STDataType;
#define MAX 1000
typedef struct Stack
{
	STDataType a[MAX];			//����ռ��㹻��
	int  top;					//ջ���±�
}Stack;
*/


//��̬(����ʵ��)ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;				//����ռ��㹻��
	int  top;					//ջ���±�
	int	 capacity;				//��ǰ������
}Stack;
//(����ʵ��)ջֻ����ʹ��ջ��λ��.



void StackInit(Stack* pst);
void StackDestory(Stack* pst);

void StackCheckCapacity(Stack* pst);

//ֻ����ջ������/ɾ������
//��ջ
void StackPush(Stack* pst,STDataType x);
//��ջ
void StackPop(Stack* pst);

//��ȡջ��Ԫ��
STDataType StackTop(Stack* pst);
//�����ݸ���
int StackSize(Stack* pst);
//�ж��Ƿ�Ϊ��
bool IsStackEmpty(Stack* pst);





















