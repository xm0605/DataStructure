#pragma once

//顺序表:有效数据在数组内必须是连续的

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//************************************    (dynamic)动态顺序表设计(大小可变)    ***********************************


#define ADD_SIZE 4					//每次增大空间的变量个数
typedef int SLDatatype;				//便于修改数组变量类型

typedef struct SeqList 
{
	SLDatatype* a;					//指向动态内存的指针
	int size;						//当前有效数据的个数
	int capacity;					//当前总容量
}SeqList;


//尾插,尾删,头插,头删
void SeqListPushBack(SeqList* ps, SLDatatype x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDatatype x);
void SeqListPopFront(SeqList* ps);


//普通用户理解的第几位与数组下标不同,应当转换,但此处pos均表示下标,不转换
//自定义位置插入数据
void SeqListInsert(SeqList* ps, int pos, SLDatatype x);
//自定义位置删除数据
void SeqListErase(SeqList* ps, int pos);

//顺序表初始化
void SeqListInit(SeqList* ps);

//打印存入的数据,随数据类型而变化
void SeqListPrint(const SeqList* ps);

//检查容量,不够则扩容,作为添加数据时的内置函数
void SeqListCheckCapacity(SeqList* ps);

//顺序表动态内存销毁
void SeqListDestory(SeqList* ps);




 //查找指定数据(返回第一个数据的下标)
int SeqListPushFind(SeqList* ps, SLDatatype x);

//删除指定数据(直至数组里没有x)
void SeqListPush_Delete_All_X(SeqList* ps, SLDatatype x);



//***********************************************  练习题  ***********************************************

int removeElement(int* nums, int numsSize, int val);

int removeDuplicates(int* nums, int numsSize);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);




int* addToArrayForm(int* num, int numSize, int k, int* returnSize);