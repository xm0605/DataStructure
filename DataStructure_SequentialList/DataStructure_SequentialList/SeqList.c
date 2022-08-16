#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


//初始化
void SeqListInit(SeqList* ps)
{
	ps->a = malloc(sizeof(SLDatatype) * ADD_SIZE);
	if (ps->a==NULL)
	{
		printf("申请内存失败\n");
		exit(-1);								//强制退出程序
	}
	ps->size=0;						
	ps->capacity=ADD_SIZE;
}

//打印,随数据类型而变化
void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", (ps->a)[i]);
	}
	printf("\n");
}

//检查容量,不够则扩容
void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size >= ps->capacity)
	{
		//增4个,对大批数据会盘符扩容
		//增二倍,空间越大之后可能的浪费越大
		//两种方案各有利弊,此处增二倍
		SLDatatype* tmp = realloc(ps->a, sizeof(SLDatatype) * (2 * ps->capacity));
		if (!tmp)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

//顺序表动态内存销毁
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}



//尾插,尾删,头插,头删
/*
void SeqListPushBack(SeqList* ps, SLDatatype x)
{
	assert(ps);

	//如果空间满了,需要增容
	SeqListCheckCapacity(ps);

	(ps->a)[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps) 
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SeqList* ps, SLDatatype x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	//原数据整体后移一位
	for (int end = ps->size - 1; end >= 0; end--)
	{
		(ps->a)[end + 1] = (ps->a)[end];
	}

	(ps->a)[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	//原数据整体前移一位
	for (int start = 0; start < (ps->size - 1); start++)
	{
		(ps->a)[start] = (ps->a)[start + 1];
	}

	ps->size--;
}
*/


//自定义位置插入数据
void SeqListInsert(SeqList* ps, int pos, SLDatatype x)
{
	assert(ps);
	assert((pos <= ps->size) && (pos >= 0));				//插入位置可以是下标size(尾插)
	SeqListCheckCapacity(ps);

	//部分后移一位
	for (int end = ps->size - 1; end >= pos; end--)
	{
		(ps->a)[end + 1] = (ps->a)[end];
	}

	(ps->a)[pos] = x;
	ps->size++;


}
//自定义位置删除数据
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert((pos < ps->size) && (pos >= 0));

	//部分前移一位
	for (int start = pos; start < (ps->size - 1); start++)
	{
		(ps->a)[start] = (ps->a)[start + 1];
	}

	ps->size--;
}


//****************    尾插,尾删,头插,头删可以使用 Insert/Erase 来实现    ****************

void SeqListPushBack(SeqList* ps, SLDatatype x)
{
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopBack(SeqList* ps)
{
	SeqListErase(ps, ps->size-1);
}
void SeqListPushFront(SeqList* ps, SLDatatype x)
{
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps)
{
	SeqListErase(ps, 0);
}



 
//查找指定数据(返回第一个数据的下标)
int SeqListPushFind(SeqList* ps, SLDatatype x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x==(ps->a)[i])
		{
			return i;
		}
	}
	return -1;
}


//删除指定数据
void SeqListPush_Delete_All_X(SeqList* ps, SLDatatype x)
{
	while (1)
	{
		int ret = SeqListPushFind(ps, x);
		if (-1 == ret)
		{
			break;
		}
		SeqListErase(ps, ret);
	}
}





