#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"


//***************************    尾插头删,先进先出    ***************************


void TestQueue()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);

	//从队头取数据
	while (que.head)
	{
		printf("%d ", QueueFront(&que));				 //尽量使用函数接口
		QueuePop(&que);
	}
	printf("\n");

	QueueDestory(&que);
}

int main()
{
	TestQueue();

	return 0;
}