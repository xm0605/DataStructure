#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>


typedef int SLListDataType;

typedef struct SLListNode			//单链表节点
{
	SLListDataType data;
	struct SLListNode* next;
}SLLNode;




/*******************************************************************************
可能修改 链表头指针phead的值(第一个节点地址) 的函数一定要传址(用二级指针)!!!!!
*******************************************************************************/


//创建一个新节点
SLLNode* CreateSLLNode(SLListDataType x);



// 单链表尾插
void SLListPushBack(SLLNode** pplist, SLListDataType x);
// 单链表的尾删
void SLListPopBack(SLLNode** pplist);

// 单链表的头插
void SLListPushFront(SLLNode** pplist, SLListDataType x);
// 单链表头删
void SLListPopFront(SLLNode** pplist);



//打印单链表
void SLListPrint(const SLLNode* plist);

//单链表查找,返回第一个相同值所在结构体指针
SLLNode* SLListFind(const SLLNode* plist, SLListDataType x);





// 单链表在pos节点之后插入x(的节点)
// 分析思考为什么不在pos位置之前插入？
void SSListInsertAfter(SLLNode* pos, SLListDataType x);
// 单链表删除pos节点位置下一个的节点
// 分析思考为什么不删除pos位置？
void SSListEraseAfter(SLLNode* pos);






//*******************************************  练习题  **************************************************


//力扣单链表练习题中,预先节点类型:
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* CreateListNode(int x);
void ListPushBack(struct ListNode** pplist, int x);
void ListPrint(const struct ListNode* plist);


//1. 删除链表中等于给定值 val 的所有节点
struct ListNode* removeElements(struct ListNode* head, int val);


//2. 反转一个单链表
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* reverseList_by_Recursion(struct ListNode* head);
struct ListNode* reverseList_by_PushFront(struct ListNode* head);


// 3. 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
struct ListNode* middleNode(struct ListNode* head);


//4. 输入一个链表，输出该链表中倒数第k个结点
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k);



//5. 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);



//6.链表分割 + 重组
struct ListNode* partition(struct ListNode* pHead, int x);




//7. 链表的回文结构
bool chkPalindrome(struct ListNode* A);




//8. 输入两个链表，找出它们的第一个公共结点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);




//9. 给定一个链表，判断链表中是否有环
bool hasCycle(struct ListNode* head);




//10. 给定一个链表，返回链表开始入环的第一个节点(指针)。 如果链表无环，则返回 NULL
struct ListNode* detectCycle(struct ListNode* head);




//11. 复制带随机指针的链表
struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};
struct Node* copyRandomList(struct Node* head);




//12. 对链表进行插入排序(升序)
struct ListNode* insertionSortList(struct ListNode* head);





//13. 删除链表中重复的结点
struct ListNode* deleteDuplication(struct ListNode* pHead);










