#define _CRT_SECURE_NO_WARNINGS 1

#include"SLList.h"


//创建一个新节点
SLLNode* CreateSLLNode(SLListDataType x)
{
	SLLNode* pnewNode = malloc(sizeof(SLLNode));
	if (!pnewNode)
	{
		printf("申请节点失败!\n");
		exit(-1);
	}
	pnewNode->data = x;
	pnewNode->next = NULL;

	return pnewNode;
}




// 单链表尾插
void SLListPushBack(SLLNode** pplist, SLListDataType x)
{
	//开辟一个新节点,返回地址
	SLLNode* pnewNode = CreateSLLNode(x);

	if (*pplist==NULL)
	{
		*pplist = pnewNode;
		return;
	}

	SLLNode* ptail = *pplist;
	while (ptail->next)
	{
		ptail = ptail->next;
	}
	ptail->next = pnewNode;
}

// 单链表的尾删
void SLListPopBack(SLLNode** pplist)
{
	//3种情况: 空链表;一元素链表;多元素链表;
	if (*pplist == NULL)
	{
		;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SLLNode* ptail = *pplist;
		while ((ptail->next)->next)
		{
			ptail = ptail->next;
		}
		free(ptail->next);
		ptail->next = NULL;
	}
}

// 单链表的头插
void SLListPushFront(SLLNode** pplist, SLListDataType x)
{
	SLLNode* pnewNode = CreateSLLNode(x);

	pnewNode->next = *pplist;
	*pplist = pnewNode;
}

// 单链表头删
void SLListPopFront(SLLNode** pplist)
{
	if (*pplist==NULL)
		return;
	
	SLLNode* ptmp=*pplist;
	*pplist = (*pplist)->next;
	free(ptmp);
}




//打印单链表
void SLListPrint(const SLLNode* plist)				// plist指向第一个节点,不修改
{
	SLLNode* pcur =(SLLNode*)plist;							//指向当前节点
	while (pcur)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;								//更新至下一个节点
	}
	printf("\n");
}

//单链表查找,返回第一个相同值所在结构体指针
SLLNode* SLListFind(const SLLNode* plist, SLListDataType x)
{
	SLLNode* pcur = (SLLNode*)plist;
	while (pcur)								//空链表不进入循环
	{
		if (pcur->data==x)						//链表中有x,一定在循环中返回
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;	
}






// 单链表在pos节点之后插入x(的节点)
void SSListInsertAfter(SLLNode* pos, SLListDataType x)
{
	assert(pos);
	SLLNode* pnewNode = CreateSLLNode(x);

	pnewNode->next = pos->next;
	pos->next = pnewNode;
}
// 单链表删除pos节点位置下一个的节点
void SSListEraseAfter(SLLNode* pos)
{
	assert(pos);
	if (pos->next==NULL)
	{
		return;
	}
	SLLNode* ptmp = (pos->next)->next;
	free(pos->next);
	pos->next = ptmp;
}






/*********************************************  练习题  ************************************************/

//创建一个新节点
struct ListNode* CreateListNode(int x)
{
	struct ListNode* pnewNode = malloc(sizeof(struct ListNode));
	if (!pnewNode)
	{
		printf("申请节点失败!\n");
		exit(-1);
	}
	pnewNode->val = x;
	pnewNode->next = NULL;

	return pnewNode;
}

// 单链表尾插
void ListPushBack(struct ListNode** pplist, int x)
{
	//开辟一个新节点,返回地址
	struct ListNode* pnewNode = CreateListNode(x);

	if (*pplist == NULL)
	{
		*pplist = pnewNode;
		return;
	}

	struct ListNode* ptail = *pplist;
	while (ptail->next)
	{
		ptail = ptail->next;
	}
	ptail->next = pnewNode;
}

//打印单链表
void ListPrint(const struct ListNode* plist)				// plist指向第一个节点,不修改
{
	struct ListNode* pcur = (struct ListNode*)plist;							//指向当前节点
	while (pcur)
	{
		printf("%d ", pcur->val);
		pcur = pcur->next;								//更新至下一个节点
	}
	printf("\n");
}