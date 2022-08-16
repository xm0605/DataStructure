#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


//测试顺序表头尾插入删除功能
void TestSeqListPUshPop()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);


	//不要忘记销毁
	SeqListDestory(&s);
}


//练习题
void Test1()
{
	int nums[] = { 0,1,2,2,3,0,4,2 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret= removeElement(nums, numsSize, 2);

}


void Test3()
{
	int nums1[10] = { 1,3,5,7,9 };
	int nums2[5] = { 0,2,4,6,8 };
	int nums1Size = 10;
	int nums2Size = 5;
	int m = 5;
	int n = 5;
merge(nums1,nums1Size,m,nums2,nums2Size,n);
}

void Test4()
{
	;
}


void Test5()
{
	int num[] = { 2,7,4 };
	int retSize = 0;

	addToArrayForm(num, 3, 181, &retSize);
}

int main()
{
	//TestSeqListPUshPop();

	//Test1();
	Test3();
	
	//Test5();

	return 0;
}












