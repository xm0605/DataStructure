#define _CRT_SECURE_NO_WARNINGS 1

#include"DLList.h"



void TestDLList1()
{
	DLListNode* phead = NULL;
	DLListInit(&phead);
	DLListPushBack(phead, 1);
	DLListPushBack(phead, 2);
	DLListPushBack(phead, 3);
	DLListPushBack(phead, 4);
	PrintDLList(phead);
	DLListPopBack(phead);
	DLListPopBack(phead);
	DLListPopBack(phead);
	PrintDLList(phead);
	DLListPopBack(phead);
	DLListPopBack(phead);
	PrintDLList(phead);
	DLListPushFront(phead, 0);
	DLListPushFront(phead, -1);
	DLListPushFront(phead, -2);
	PrintDLList(phead);
	DLListPopFront(phead);
	DLListPopFront(phead);
	PrintDLList(phead);
	DLListPopFront(phead);
	DLListPopFront(phead);
	PrintDLList(phead);

	DLListDestory(&phead);
}

void TestDLList2()
{
	DLListNode* phead = NULL;
	DLListInit(&phead);
	DLListPushBack(phead, 1);
	DLListPushBack(phead, 2);
	DLListPushBack(phead, 3);
	DLListPushBack(phead, 4);
	PrintDLList(phead);
	//在3之前插入30;删除2;
	DLListNode* pos= LListNodeFindD(phead, 3);
	DLListInsert(pos, 30);
	PrintDLList(phead);
	pos = LListNodeFindD(phead, 2);
	DLListErase(pos);
	PrintDLList(phead);

	DLListDestory(&phead);

}



int main()
{
	//TestDLList1();
	TestDLList2();

	return 0;
}

