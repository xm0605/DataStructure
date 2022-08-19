#define _CRT_SECURE_NO_WARNINGS 1

#include"SLList.h"


void TestSLListPushPop()
{
	SLLNode* plist = NULL;

	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);
	SLListPrint(plist);

	SLListPopBack(&plist);
	SLListPopBack(&plist);
	SLListPopBack(&plist); SLListPrint(plist);
	SLListPopBack(&plist); SLListPrint(plist);
	SLListPopBack(&plist);
	SLListPrint(plist);


	SLListPushFront(&plist, 0);
	SLListPushFront(&plist, -1);
	SLListPushFront(&plist, -2);
	SLListPrint(plist);

	SLListPopFront(&plist);
	SLListPopFront(&plist); SLListPrint(plist);
	SLListPopFront(&plist); SLListPrint(plist);
	SLListPopFront(&plist);
	SLListPrint(plist);

}

void TestSLListOthers()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);
	SLListPrint(plist);

	
	SLLNode* pcur= SLListFind(plist, 3);
	if (pcur)								//²éÕÒµ½3
	{
		pcur->data = 30;					//ÐÞ¸Ä3->30
	}
	SLListPrint(plist);

}


void ListNodePractice1()
{
	struct ListNode* plist = NULL;
	ListPushBack(&plist, 1);
	ListPushBack(&plist, 2);
	ListPushBack(&plist, 3);
	ListPushBack(&plist, 4);
	ListPrint(plist);
	plist = removeElements(plist, 4);
	ListPrint(plist);
	plist = reverseList(plist);
	ListPrint(plist);

}

void ListNodePractice2()
{
	struct ListNode* plist1 = NULL;
	ListPushBack(&plist1, 1);
	ListPushBack(&plist1, 2);
	ListPushBack(&plist1, 3);
	ListPushBack(&plist1, 4);
	ListPrint(plist1);
	struct ListNode* plist2 = NULL;
	ListPushBack(&plist2, 1);
	ListPushBack(&plist2, 2);
	ListPushBack(&plist2, 3);
	ListPushBack(&plist2, 4);
	ListPrint(plist1);

	struct ListNode* plist = mergeTwoLists(plist1, plist2);
	ListPrint(plist);
}


void ListNodePractice3()
{
	struct ListNode* plist = NULL;
	ListPushBack(&plist, 1);
	//ListPushBack(&plist, 4);
	ListPushBack(&plist, 2);
	//ListPushBack(&plist, 4);
	ListPrint(plist);
	//plist=partition(plist, 3);
	plist=insertionSortList(plist);
	plist=deleteDuplication(plist);
	ListPrint(plist);
}
int main()
{
	//TestSLListPushPop();
	//TestSLListOthers();
	//ListNodePractice1();
	//ListNodePractice2();
	ListNodePractice3();


	return 0;
}
