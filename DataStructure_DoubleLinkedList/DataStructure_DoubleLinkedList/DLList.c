#define _CRT_SECURE_NO_WARNINGS 1

#include"DLList.h"



//�����½ڵ�
DLListNode* CreatNewDLLNode(DLLDataType x)
{
	DLListNode* pnewnode = (DLListNode*)malloc(sizeof(DLListNode));
	assert(pnewnode);
	pnewnode->data = x;
	pnewnode->next = NULL;
	pnewnode->prev = NULL;

	return pnewnode;
}

//˳���ӡ˫������
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


//��ʼ��phead,��ͷ�ڵ�ѭ��ָ���Լ�
void DLListInit(DLListNode** pphead)
{
	assert(pphead);
	DLListNode* phead= (DLListNode*)malloc(sizeof(DLListNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;

	*pphead = phead;
}

//�������(�����ڱ�λ,����ʹ��)
void DLListClear(DLListNode* phead)
{
	assert(phead);
	DLListNode* pcur = phead->next;
	while (pcur != phead)								//�ͷ�������Ч�ڵ�
	{
		pcur = pcur->next;
		free(pcur->prev);
	}
}
//����(�ͷ�)����(���������ڱ�λ)
void DLListDestory(DLListNode** pphead)
{
	assert(*pphead);
	DLListClear(*pphead);
	//����ʵ����Ҫȷ���Ƿ�free(phead)	
	free(*pphead);
	*pphead = NULL;
}



//β��,βɾ,ͷ��,ͷɾ
void DLListPushBack(DLListNode* phead, DLLDataType x)			//phead���ı�
{
	//��ͼ,�ı��ĸ�ָ��
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
	//��ͼ,�ı�����ָ��,free
	assert(phead);
	DLListNode* pnewtail = phead->prev->prev;
	if (phead != phead->prev)							        //��(��Ч)�ڵ�ʱ������free
	{
		free(phead->prev);
	}
	phead->prev = pnewtail;
	pnewtail->next = phead;
}
void DLListPushFront(DLListNode* phead, DLLDataType x)
{
	//��ͼ,�ı��ĸ�ָ��
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
	if (phead != phead->next)							        //��(��Ч)�ڵ�ʱ������free
	{
		free(phead->next);
	}
	phead->next = pnewfirst;
	pnewfirst->prev = phead;
}





//���ҽڵ�,��ϲ���/ɾ������
DLListNode* LListNodeFindD(DLListNode* phead, DLLDataType x)
{
	assert(phead);
	DLListNode* pcur = phead->next;								//�ӵ�һ����Ч�ڵ㿪ʼ

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

//��pos(ָ��)λ�õ�ǰ�����x:(������Ч���ݽڵ�ǰ����ڱ�λ(phead)ǰ��)
void DLListInsert(DLListNode* pos, DLLDataType x)
{
	//����β��(��phead֮ǰ)
	assert(pos);
	DLListNode* posPrev = pos->prev;
	DLListNode* pnewnode = CreatNewDLLNode(x);

	posPrev->next = pnewnode;
	pnewnode->next = pos;
	pos->prev = pnewnode;
	pnewnode->prev = posPrev;
}

//ɾ��posλ�ýڵ�(������phead)
void DLListErase(DLListNode* pos)				//���ɴ���phead,���������޷��ж�
{
	//ǰ�ڵ�,��ڵ�����
	DLListNode* pNext = pos->next;
	DLListNode* pPrev = pos->prev;
	free(pos);
	pNext->prev = pPrev;
	pPrev->next = pNext;
}


//******************  ���븴��  ********************  

//β��,βɾ,ͷ��,ͷɾ
/*
void DLListPushBack(DLListNode* phead, DLLDataType x)
{
	DLListInsert(phead, x);
}
void DLListPopBack(DLListNode* phead)
{
	if (phead != phead->prev)							        //��(��Ч)�ڵ�ʱ������free
		DLListErase(phead->prev);
}
void DLListPushFront(DLListNode* phead, DLLDataType x)
{
	DLListInsert(phead->next, x);
}
void DLListPopFront(DLListNode* phead)
{
	if (phead != phead->next)							        //��(��Ч)�ڵ�ʱ������free
		DLListErase(phead->next);
}
*/




