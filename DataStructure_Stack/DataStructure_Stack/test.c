#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


//***************************    β��βɾ,����ȳ�    ***************************



int main()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//ջ��ֹ�������
	while (!IsStackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestory(&st);
	return 0;
}




