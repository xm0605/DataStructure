#pragma once

//˳���:��Ч�����������ڱ�����������

//************************************    (static)��̬˳������(�̶���С)    ***********************************
#define N 100						//�����С,�����㹻��
typedef int SLDatatype;				//�����޸������������

struct SeqList
{
	SLDatatype a[N];
	int size;						//��¼��Ч���ݸ���
};

void SeqListPushBack(struct SeqList* ps, SLDatatype x);
//β��,��psָ��Ľṹ�����->a[N]����ĩβ��¼������x	
void SeqListPopBack(struct SeqList* ps);
//βɾ,��������ɾ�����һ����Ч����		
void SeqListPushFront(struct SeqList* ps, SLDatatype x);
//ͷ��,������λ��¼������x		
void SeqListPopFront(struct SeqList* ps);
//ͷ��,��������ɾ����һ����Ч����

//����ʵ����,�붯̬˳������˼·����

