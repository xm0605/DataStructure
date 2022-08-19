#define _CRT_SECURE_NO_WARNINGS 1

#include"SLList.h"


//����һ���½ڵ�
SLLNode* CreateSLLNode(SLListDataType x)
{
	SLLNode* pnewNode = malloc(sizeof(SLLNode));
	if (!pnewNode)
	{
		printf("����ڵ�ʧ��!\n");
		exit(-1);
	}
	pnewNode->data = x;
	pnewNode->next = NULL;

	return pnewNode;
}




// ������β��
void SLListPushBack(SLLNode** pplist, SLListDataType x)
{
	//����һ���½ڵ�,���ص�ַ
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

// �������βɾ
void SLListPopBack(SLLNode** pplist)
{
	//3�����: ������;һԪ������;��Ԫ������;
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

// �������ͷ��
void SLListPushFront(SLLNode** pplist, SLListDataType x)
{
	SLLNode* pnewNode = CreateSLLNode(x);

	pnewNode->next = *pplist;
	*pplist = pnewNode;
}

// ������ͷɾ
void SLListPopFront(SLLNode** pplist)
{
	if (*pplist==NULL)
		return;
	
	SLLNode* ptmp=*pplist;
	*pplist = (*pplist)->next;
	free(ptmp);
}




//��ӡ������
void SLListPrint(const SLLNode* plist)				// plistָ���һ���ڵ�,���޸�
{
	SLLNode* pcur =(SLLNode*)plist;							//ָ��ǰ�ڵ�
	while (pcur)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;								//��������һ���ڵ�
	}
	printf("\n");
}

//���������,���ص�һ����ֵͬ���ڽṹ��ָ��
SLLNode* SLListFind(const SLLNode* plist, SLListDataType x)
{
	SLLNode* pcur = (SLLNode*)plist;
	while (pcur)								//����������ѭ��
	{
		if (pcur->data==x)						//��������x,һ����ѭ���з���
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;	
}






// ��������pos�ڵ�֮�����x(�Ľڵ�)
void SSListInsertAfter(SLLNode* pos, SLListDataType x)
{
	assert(pos);
	SLLNode* pnewNode = CreateSLLNode(x);

	pnewNode->next = pos->next;
	pos->next = pnewNode;
}
// ������ɾ��pos�ڵ�λ����һ���Ľڵ�
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






/*********************************************  ��ϰ��  ************************************************/

//����һ���½ڵ�
struct ListNode* CreateListNode(int x)
{
	struct ListNode* pnewNode = malloc(sizeof(struct ListNode));
	if (!pnewNode)
	{
		printf("����ڵ�ʧ��!\n");
		exit(-1);
	}
	pnewNode->val = x;
	pnewNode->next = NULL;

	return pnewNode;
}

// ������β��
void ListPushBack(struct ListNode** pplist, int x)
{
	//����һ���½ڵ�,���ص�ַ
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

//��ӡ������
void ListPrint(const struct ListNode* plist)				// plistָ���һ���ڵ�,���޸�
{
	struct ListNode* pcur = (struct ListNode*)plist;							//ָ��ǰ�ڵ�
	while (pcur)
	{
		printf("%d ", pcur->val);
		pcur = pcur->next;								//��������һ���ڵ�
	}
	printf("\n");
}