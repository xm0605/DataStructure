#pragma once

//˳���:��Ч�����������ڱ�����������

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//************************************    (dynamic)��̬˳������(��С�ɱ�)    ***********************************


#define ADD_SIZE 4					//ÿ������ռ�ı�������
typedef int SLDatatype;				//�����޸������������

typedef struct SeqList 
{
	SLDatatype* a;					//ָ��̬�ڴ��ָ��
	int size;						//��ǰ��Ч���ݵĸ���
	int capacity;					//��ǰ������
}SeqList;


//β��,βɾ,ͷ��,ͷɾ
void SeqListPushBack(SeqList* ps, SLDatatype x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDatatype x);
void SeqListPopFront(SeqList* ps);


//��ͨ�û����ĵڼ�λ�������±겻ͬ,Ӧ��ת��,���˴�pos����ʾ�±�,��ת��
//�Զ���λ�ò�������
void SeqListInsert(SeqList* ps, int pos, SLDatatype x);
//�Զ���λ��ɾ������
void SeqListErase(SeqList* ps, int pos);

//˳����ʼ��
void SeqListInit(SeqList* ps);

//��ӡ���������,���������Ͷ��仯
void SeqListPrint(const SeqList* ps);

//�������,����������,��Ϊ�������ʱ�����ú���
void SeqListCheckCapacity(SeqList* ps);

//˳���̬�ڴ�����
void SeqListDestory(SeqList* ps);




 //����ָ������(���ص�һ�����ݵ��±�)
int SeqListPushFind(SeqList* ps, SLDatatype x);

//ɾ��ָ������(ֱ��������û��x)
void SeqListPush_Delete_All_X(SeqList* ps, SLDatatype x);



//***********************************************  ��ϰ��  ***********************************************

int removeElement(int* nums, int numsSize, int val);

int removeDuplicates(int* nums, int numsSize);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);




int* addToArrayForm(int* num, int numSize, int k, int* returnSize);