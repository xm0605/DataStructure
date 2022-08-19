#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>


typedef int SLListDataType;

typedef struct SLListNode			//������ڵ�
{
	SLListDataType data;
	struct SLListNode* next;
}SLLNode;




/*******************************************************************************
�����޸� ����ͷָ��phead��ֵ(��һ���ڵ��ַ) �ĺ���һ��Ҫ��ַ(�ö���ָ��)!!!!!
*******************************************************************************/


//����һ���½ڵ�
SLLNode* CreateSLLNode(SLListDataType x);



// ������β��
void SLListPushBack(SLLNode** pplist, SLListDataType x);
// �������βɾ
void SLListPopBack(SLLNode** pplist);

// �������ͷ��
void SLListPushFront(SLLNode** pplist, SLListDataType x);
// ������ͷɾ
void SLListPopFront(SLLNode** pplist);



//��ӡ������
void SLListPrint(const SLLNode* plist);

//���������,���ص�һ����ֵͬ���ڽṹ��ָ��
SLLNode* SLListFind(const SLLNode* plist, SLListDataType x);





// ��������pos�ڵ�֮�����x(�Ľڵ�)
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SSListInsertAfter(SLLNode* pos, SLListDataType x);
// ������ɾ��pos�ڵ�λ����һ���Ľڵ�
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SSListEraseAfter(SLLNode* pos);






//*******************************************  ��ϰ��  **************************************************


//���۵�������ϰ����,Ԥ�Ƚڵ�����:
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* CreateListNode(int x);
void ListPushBack(struct ListNode** pplist, int x);
void ListPrint(const struct ListNode* plist);


//1. ɾ�������е��ڸ���ֵ val �����нڵ�
struct ListNode* removeElements(struct ListNode* head, int val);


//2. ��תһ��������
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* reverseList_by_Recursion(struct ListNode* head);
struct ListNode* reverseList_by_PushFront(struct ListNode* head);


// 3. ����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
struct ListNode* middleNode(struct ListNode* head);


//4. ����һ����������������е�����k�����
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k);



//5. �ϲ�������������
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);



//6.����ָ� + ����
struct ListNode* partition(struct ListNode* pHead, int x);




//7. ����Ļ��Ľṹ
bool chkPalindrome(struct ListNode* A);




//8. �������������ҳ����ǵĵ�һ���������
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);




//9. ����һ�������ж��������Ƿ��л�
bool hasCycle(struct ListNode* head);




//10. ����һ��������������ʼ�뻷�ĵ�һ���ڵ�(ָ��)�� ��������޻����򷵻� NULL
struct ListNode* detectCycle(struct ListNode* head);




//11. ���ƴ����ָ�������
struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};
struct Node* copyRandomList(struct Node* head);




//12. ��������в�������(����)
struct ListNode* insertionSortList(struct ListNode* head);





//13. ɾ���������ظ��Ľ��
struct ListNode* deleteDuplication(struct ListNode* pHead);










