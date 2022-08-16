#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


//��ʼ��
void SeqListInit(SeqList* ps)
{
	ps->a = malloc(sizeof(SLDatatype) * ADD_SIZE);
	if (ps->a==NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);								//ǿ���˳�����
	}
	ps->size=0;						
	ps->capacity=ADD_SIZE;
}

//��ӡ,���������Ͷ��仯
void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", (ps->a)[i]);
	}
	printf("\n");
}

//�������,����������
void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size >= ps->capacity)
	{
		//��4��,�Դ������ݻ��̷�����
		//������,�ռ�Խ��֮����ܵ��˷�Խ��
		//���ַ�����������,�˴�������
		SLDatatype* tmp = realloc(ps->a, sizeof(SLDatatype) * (2 * ps->capacity));
		if (!tmp)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

//˳���̬�ڴ�����
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}



//β��,βɾ,ͷ��,ͷɾ
/*
void SeqListPushBack(SeqList* ps, SLDatatype x)
{
	assert(ps);

	//����ռ�����,��Ҫ����
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

	//ԭ�����������һλ
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

	//ԭ��������ǰ��һλ
	for (int start = 0; start < (ps->size - 1); start++)
	{
		(ps->a)[start] = (ps->a)[start + 1];
	}

	ps->size--;
}
*/


//�Զ���λ�ò�������
void SeqListInsert(SeqList* ps, int pos, SLDatatype x)
{
	assert(ps);
	assert((pos <= ps->size) && (pos >= 0));				//����λ�ÿ������±�size(β��)
	SeqListCheckCapacity(ps);

	//���ֺ���һλ
	for (int end = ps->size - 1; end >= pos; end--)
	{
		(ps->a)[end + 1] = (ps->a)[end];
	}

	(ps->a)[pos] = x;
	ps->size++;


}
//�Զ���λ��ɾ������
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert((pos < ps->size) && (pos >= 0));

	//����ǰ��һλ
	for (int start = pos; start < (ps->size - 1); start++)
	{
		(ps->a)[start] = (ps->a)[start + 1];
	}

	ps->size--;
}


//****************    β��,βɾ,ͷ��,ͷɾ����ʹ�� Insert/Erase ��ʵ��    ****************

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



 
//����ָ������(���ص�һ�����ݵ��±�)
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


//ɾ��ָ������
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





