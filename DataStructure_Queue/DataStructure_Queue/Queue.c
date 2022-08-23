#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//***************************    尾插头删,先进先出    ***************************

//(空)队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//销毁队列
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* pcur = pq->head;
	while (pcur)
	{
		QNode* pnext = pcur->next;
		free(pcur);
		pcur = pnext;
	}
	pq->head = pq->tail = NULL;
}



//队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//创建数据节点
	QNode* newNode = malloc(sizeof(QNode));
	if (!newNode)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	if (pq->tail == NULL)						//队列中没有元素
	{
		pq->head = pq->tail = newNode;
	}
	else										//队列中已有元素
	{
		(pq->tail)->next = newNode;				//队列连接上
		pq->tail = newNode;						//移动尾部
	}

}
//队头出
void QueuePop(Queue* pq)
{
	assert(pq);
	//保证队列不为空
	assert(pq->head);

	QNode* pnext = pq->head->next;
	free(pq->head);
	pq->head = pnext;

	if (pq->head==NULL)							//释放了最后一个节点,把尾也置空 !!!!!!
	{
		pq->tail = NULL;
	}
}


//取(队头/队尾)数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//队列不能无数据
	assert(pq->head);

	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//队列不能无数据
	assert(pq->tail);

	return pq->tail->data;
}



//取数据个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* pcur = pq->head;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}
	return size;
}
//判断是否为空
bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}










