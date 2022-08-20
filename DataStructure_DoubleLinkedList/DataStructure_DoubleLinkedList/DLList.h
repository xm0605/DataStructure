#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DLLDataType;

typedef struct DLListNode
{
	DLLDataType data;
	struct DLListNode* prev;
	struct DLListNode* next;
} DLListNode;

//特点:
//结构复杂,操作简单,无需判断多种情况.
//一般不处理哨兵位头指针(phead)



//******************      函数功能实现     ******************


//创建新节点
DLListNode* CreatNewDLLNode(DLLDataType x);

//顺序打印双向链表
void PrintDLList(DLListNode* phead);



//初始化phead,即头节点循环指向自己
void DLListInit(DLListNode** pphead);				//需要修改phead指向


//清空链表(不包括哨兵位)
void DLListClear(DLListNode* phead);
//销毁(释放)链表
void DLListDestory(DLListNode** pphead);


//尾插,尾删,头插,头删
void DLListPushBack(DLListNode* phead, DLLDataType x);
void DLListPopBack(DLListNode* phead);
void DLListPushFront(DLListNode* phead, DLLDataType x);
void DLListPopFront(DLListNode* phead);

//查找节点,配合插入/删除操作
DLListNode* LListNodeFindD(DLListNode* phead ,DLLDataType x);

//在pos(指针)位置的前面插入x:(包括有效数据节点前面和哨兵位(phead)前面)
void DLListInsert(DLListNode* pos, DLLDataType x);
//删除pos位置节点(不能是phead)
void DLListErase(DLListNode* pos);























