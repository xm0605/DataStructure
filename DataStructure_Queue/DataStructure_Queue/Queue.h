#define _CRT_SECURE_NO_WARNINGS 1

//***************************    尾插头删,先进先出    ***************************

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




//参数传递结构体Queue指针访问队列的head和tail,相当于传递指向head和tail指针的二级指针
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

//队尾入
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);


//取 队头/队尾 数据
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//取数据个数
int QueueSize(Queue* pq);
//判断是否为空
bool IsQueueEmpty(Queue* pq);










