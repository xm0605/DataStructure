#define _CRT_SECURE_NO_WARNINGS 1

//***************************    β��ͷɾ,�Ƚ��ȳ�    ***************************

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>


typedef int QDataType;
typedef struct  QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct  Queue
{
	QNode* head;
	QNode* tail;
}Queue;




//�������ݽṹ��Queueָ����ʶ��е�head��tail,�൱�ڴ���ָ��head��tailָ��Ķ���ָ��
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

//��β��
void QueuePush(Queue* pq, QDataType x);
//��ͷ��
void QueuePop(Queue* pq);


//ȡ ��ͷ/��β ����
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//ȡ���ݸ���
int QueueSize(Queue* pq);
//�ж��Ƿ�Ϊ��
bool IsQueueEmpty(Queue* pq);










