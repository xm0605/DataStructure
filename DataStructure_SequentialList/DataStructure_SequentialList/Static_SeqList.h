#pragma once

//顺序表:有效数据在数组内必须是连续的

//************************************    (static)静态顺序表设计(固定大小)    ***********************************
#define N 100						//数组大小,必须足够大
typedef int SLDatatype;				//便于修改数组变量类型

struct SeqList
{
	SLDatatype a[N];
	int size;						//记录有效数据个数
};

void SeqListPushBack(struct SeqList* ps, SLDatatype x);
//尾插,在ps指向的结构体变量->a[N]数组末尾中录入数据x	
void SeqListPopBack(struct SeqList* ps);
//尾删,在数组中删除最后一个有效数据		
void SeqListPushFront(struct SeqList* ps, SLDatatype x);
//头插,数组首位中录入数据x		
void SeqListPopFront(struct SeqList* ps);
//头插,在数组中删除第一个有效数据

//具体实现略,与动态顺序表设计思路类似

