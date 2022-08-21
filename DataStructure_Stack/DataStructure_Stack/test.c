#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


//***************************    尾插尾删,后进先出    ***************************



int main()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//栈禁止随意遍历
	while (!IsStackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestory(&st);
	return 0;
}




