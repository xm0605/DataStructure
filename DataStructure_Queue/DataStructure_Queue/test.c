#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"


//***************************    β��ͷɾ,�Ƚ��ȳ�    ***************************


void TestQueue()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);

	//�Ӷ�ͷȡ����
	while (que.head)
	{
		printf("%d ", QueueFront(&que));				 //����ʹ�ú����ӿ�
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