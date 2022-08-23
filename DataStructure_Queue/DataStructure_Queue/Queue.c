#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//***************************    β��ͷɾ,�Ƚ��ȳ�    ***************************

//(��)���г�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//���ٶ���
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



//��β��
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//�������ݽڵ�
	QNode* newNode = malloc(sizeof(QNode));
	if (!newNode)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	if (pq->tail == NULL)						//������û��Ԫ��
	{
		pq->head = pq->tail = newNode;
	}
	else										//����������Ԫ��
	{
		(pq->tail)->next = newNode;				//����������
		pq->tail = newNode;						//�ƶ�β��
	}

}
//��ͷ��
void QueuePop(Queue* pq)
{
	assert(pq);
	//��֤���в�Ϊ��
	assert(pq->head);

	QNode* pnext = pq->head->next;
	free(pq->head);
	pq->head = pnext;

	if (pq->head==NULL)							//�ͷ������һ���ڵ�,��βҲ�ÿ� !!!!!!
	{
		pq->tail = NULL;
	}
}


//ȡ(��ͷ/��β)����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//���в���������
	assert(pq->head);

	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//���в���������
	assert(pq->tail);

	return pq->tail->data;
}



//ȡ���ݸ���
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
//�ж��Ƿ�Ϊ��
bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}










