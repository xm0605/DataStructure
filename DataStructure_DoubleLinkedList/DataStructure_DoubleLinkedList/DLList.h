#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DLLDataType;

typedef struct DLListNode
{
	DLLDataType data;
	struct DLListNode* prev;
	struct DLListNode* next;
} DLListNode;

//�ص�:
//�ṹ����,������,�����ж϶������.
//һ�㲻�����ڱ�λͷָ��(phead)



//******************      ��������ʵ��     ******************


//�����½ڵ�
DLListNode* CreatNewDLLNode(DLLDataType x);

//˳���ӡ˫������
void PrintDLList(DLListNode* phead);



//��ʼ��phead,��ͷ�ڵ�ѭ��ָ���Լ�
void DLListInit(DLListNode** pphead);				//��Ҫ�޸�pheadָ��


//�������(�������ڱ�λ)
void DLListClear(DLListNode* phead);
//����(�ͷ�)����
void DLListDestory(DLListNode** pphead);


//β��,βɾ,ͷ��,ͷɾ
void DLListPushBack(DLListNode* phead, DLLDataType x);
void DLListPopBack(DLListNode* phead);
void DLListPushFront(DLListNode* phead, DLLDataType x);
void DLListPopFront(DLListNode* phead);

//���ҽڵ�,��ϲ���/ɾ������
DLListNode* LListNodeFindD(DLListNode* phead ,DLLDataType x);

//��pos(ָ��)λ�õ�ǰ�����x:(������Ч���ݽڵ�ǰ����ڱ�λ(phead)ǰ��)
void DLListInsert(DLListNode* pos, DLLDataType x);
//ɾ��posλ�ýڵ�(������phead)
void DLListErase(DLListNode* pos);























