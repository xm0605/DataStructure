#define _CRT_SECURE_NO_WARNINGS 1

#include"DLList.h"



//创建新节点
DLListNode* CreatNewDLLNode(DLLDataType x)
{
	DLListNode* pnewnode = (DLListNode*)malloc(sizeof(DLListNode));
	assert(pnewnode);
	pnewnode->data = x;
	pnewnode->next = NULL;
	pnewnode->prev = NULL;

	return pnewnode;
}

//顺序打印双向链表
void PrintDLList(DLListNode* phead) 
{
	assert(phead);
	DLListNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}


//初始化phead,即头节点循环指向自己
void DLListInit(DLListNode** pphead)
{
	assert(pphead);
	DLListNode* phead= (DLListNode*)malloc(sizeof(DLListNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;

	*pphead = phead;
}

//清空链表(保留哨兵位,继续使用)
void DLListClear(DLListNode* phead)
{
	assert(phead);
	DLListNode* pcur = phead->next;
	while (pcur != phead)								//释放所有有效节点
	{
		pcur = pcur->next;
		free(pcur->prev);
	}
}
//销毁(释放)链表(包括销毁哨兵位)
void DLListDestory(DLListNode** pphead)
{
	assert(*pphead);
	DLListClear(*pphead);
	//根据实际需要确定是否free(phead)	
	free(*pphead);
	*pphead = NULL;
}



//尾插,尾删,头插,头删
void DLListPushBack(DLListNode* phead, DLLDataType x)			//phead不改变
{
	//画图,改变四个指针
	assert(phead);
	DLListNode* ptail = phead->prev;
	DLListNode* pnewnode = CreatNewDLLNode(x);

	ptail->next = pnewnode;
	pnewnode->next = phead;
	phead->prev = pnewnode;
	pnewnode->prev = ptail;
}
void DLListPopBack(DLListNode* phead)
{
	//画图,改变两个指针,free
	assert(phead);
	DLListNode* pnewtail = phead->prev->prev;
	if (phead != phead->prev)							        //零(有效)节点时不允许free
	{
		free(phead->prev);
	}
	phead->prev = pnewtail;
	pnewtail->next = phead;
}
void DLListPushFront(DLListNode* phead, DLLDataType x)
{
	//画图,改变四个指针
	assert(phead);
	DLListNode* pnext = phead->next;
	DLListNode* pnewnode = CreatNewDLLNode(x);

	phead->next = pnewnode;
	pnewnode->next = pnext;
	pnext->prev = pnewnode;
	pnewnode->prev = phead;
}
void DLListPopFront(DLListNode* phead)
{
	assert(phead);
	DLListNode* pnewfirst = phead->next->next;
	if (phead != phead->next)							        //零(有效)节点时不允许free
	{
		free(phead->next);
	}
	phead->next = pnewfirst;
	pnewfirst->prev = phead;
}





//查找节点,配合插入/删除操作
DLListNode* LListNodeFindD(DLListNode* phead, DLLDataType x)
{
	assert(phead);
	DLListNode* pcur = phead->next;								//从第一个有效节点开始

	while (phead!=pcur)
	{
		if (pcur->data==x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//在pos(指针)位置的前面插入x:(包括有效数据节点前面和哨兵位(phead)前面)
void DLListInsert(DLListNode* pos, DLLDataType x)
{
	//类似尾插(在phead之前)
	assert(pos);
	DLListNode* posPrev = pos->prev;
	DLListNode* pnewnode = CreatNewDLLNode(x);

	posPrev->next = pnewnode;
	pnewnode->next = pos;
	pos->prev = pnewnode;
	pnewnode->prev = posPrev;
}

//删除pos位置节点(不能是phead)
void DLListErase(DLListNode* pos)				//不可传入phead,但函数内无法判断
{
	//前节点,后节点连接
	DLListNode* pNext = pos->next;
	DLListNode* pPrev = pos->prev;
	free(pos);
	pNext->prev = pPrev;
	pPrev->next = pNext;
}


//******************  代码复用  ********************  

//尾插,尾删,头插,头删
/*
void DLListPushBack(DLListNode* phead, DLLDataType x)
{
	DLListInsert(phead, x);
}
void DLListPopBack(DLListNode* phead)
{
	if (phead != phead->prev)							        //零(有效)节点时不允许free
		DLListErase(phead->prev);
}
void DLListPushFront(DLListNode* phead, DLLDataType x)
{
	DLListInsert(phead->next, x);
}
void DLListPopFront(DLListNode* phead)
{
	if (phead != phead->next)							        //零(有效)节点时不允许free
		DLListErase(phead->next);
}
*/




