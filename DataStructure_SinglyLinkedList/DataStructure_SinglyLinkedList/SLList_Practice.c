#define _CRT_SECURE_NO_WARNINGS 1

#include"SLList.h"





//1. 删除链表中等于给定值 val 的所有节点
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
struct ListNode* removeElements(struct ListNode* head, int val)				//返回节点指针用原指针接收,用来修改原头指针
{
	if (head==NULL)									//0节点链表,其实也在下列情况中,可省略
	{
		return head;
	}

	struct ListNode* pcur = head;					//指向当前节点,检查pcur->val
	struct ListNode* pprev = NULL;					//指向前一位节点,用于删除当前节点
	struct ListNode* phead = head;					//用于返回头节点指针
	int numNode = 0;								//记录已成功保留节点个数

	//循环中,如果pcur数据为val,则释放该节点,将下个节点连上pprev->next; 
	//如果不是val,则pcur指向后移,nunNode++
	while (pcur)									
	{
		if (pcur->val==val)
		{
			if (numNode!=0)							//前面已存在头节点(或用 pprev!=NULL 判断也可以)
			{
				pprev->next = pcur->next;
				free(pcur);
				pcur = pprev->next;
			}
			else									//当前为头节点,特殊情况
			{
				phead= pcur->next;
				free(pcur);
				pcur = phead;
			}	
		}
		else										//通过检查,更新pprev,pcur
		{
			pprev = pcur;
			pcur = pcur->next;
			numNode++;
		}
	}
	return phead;
}





//2. [************ 反转一个单链表 ************]
//给你单链表的头节点指针 head ，请你反转链表，并返回反转后的链表
//三指针迭代法:
struct ListNode* reverseList(struct ListNode* head) {
	if ((head==NULL)||(head->next==NULL))					//零节点或一节点直接返回
	{
		return head;
	}

	//把 pprev 存入 pcur->next 中,然后三者后移
	struct ListNode* pprev=head;
	struct ListNode* pcur=pprev->next;
	struct ListNode* pnext=pcur->next;

	head->next = NULL;						//原头结点变尾节点
	while (pnext)
	{
		pcur->next = pprev;					//赋值
		pprev = pcur;						//迭代更新
		pcur = pnext;
		pnext = pcur->next;
	}
	//(pcur->next==NULL)即pcur指向最后节点时退出循环
	pcur->next = pprev;						//pcur指向头节点

	return pcur;
}

//递归方法:每次把头节点next置空,移至尾节点
struct ListNode* reverseList_by_Recursion(struct ListNode* head)			
{
	if ((head == NULL) || (head->next == NULL))					//零节点或一节点直接返回,递归出口
	{
		return head;
	}
	else
	{
		struct ListNode* ret = reverseList_by_Recursion(head->next);
		//在返回的链表最后添加原头结点
		struct ListNode* ptail = ret;
		while (ptail->next)										//指向尾节点时,出循环
		{
			ptail = ptail->next;
		}
		ptail->next = head;
		head->next = NULL;

		return ret;
	}
}

//逐个头插法:按顺序取下节点, 依次头插进一个新链表(表头)中, 没有新建链表空间
struct ListNode* reverseList_by_PushFront(struct ListNode* head)
{
	struct ListNode* pnewhead = NULL;
	struct ListNode* pcur = head;

	while (pcur)
	{
		//pnext作为保存的中介
		struct ListNode* pnext = pcur->next;
		//头插
		pcur->next = pnewhead;
		pnewhead = pcur;
		//迭代
		pcur = pnext;
	}
	return pnewhead;
}





// 3. 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
//[************ 快慢指针问题 ************]
struct ListNode* middleNode(struct ListNode* head) 
{
	if (!head)
		return head;

	//"两步走->一步走"
	struct ListNode* pTwoStep = head;
	struct ListNode* pOneStep = head;
	int count = 1;							//计数器,初始值为0则是返回:第一个中间结点
	while (pTwoStep->next)					//pTwoStep一直走到指向最后节点退出,pOneStep两轮循环走一步
	{
		pTwoStep = pTwoStep->next;
		count++;
		if (count%2==0)
		{
			pOneStep = pOneStep->next;
		}
	}
	return pOneStep;

}
//简化版:
struct ListNode* simplify_middleNode(struct ListNode* head)
{
	//上面代码简化版
	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}





//4. 输入一个链表，输出该链表中倒数第k个结点
//[******  快慢指针问题  *******]:fast先走k步,再一起迭代,fast为空时返回slow
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;
	
	while (k)										//fast多迭代k次
	{
		k--;
		if (fast)
			fast = fast->next;
		else
			return NULL;							//循环未能迭代k次,即链表长度不够k个
	}
	while (fast)									//同时迭代直至fast指向空
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}





//5. 合并两个有序链表
//将两个升序(小->大)链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if (!list2)											//一支链表为空,直接返回另一个,排除了3种空特例
	{
		return list1;
	}
	else if(!list1)
	{
		return list2;
	}

	struct ListNode* newList = NULL;					//返回的新链表头
	struct ListNode* ptail = newList;					//新链表的尾节点	
	struct ListNode* pcur1 = list1;						//链表1迭代指针
	struct ListNode* pcur2 = list2;						//链表2迭代指针

	if (pcur1->val < pcur2->val)						//赋值新链表头指向newList
	{
		newList = pcur1;
		pcur1 = pcur1->next;
	}
	else
	{
		newList = pcur2;
		pcur2 = pcur2->next;
	}
	ptail = newList;									//新链表的尾节点	

	while (pcur1 && pcur2)
	{
		if (pcur1->val < pcur2->val)					//原链表1的当前数据更小
		{
			ptail->next = pcur1;
			pcur1 = pcur1->next;
		}
		else
		{
			ptail->next = pcur2;
			pcur2 = pcur2->next;
		}
		ptail = ptail->next;
	}
	if(pcur1)										//链表1还有剩余
	{
		ptail->next = pcur1;						//直接接上,不再处理尾指针,与动态数组不同
	}
	else if(pcur2)									//最好别直接用else,防止双空链表
	{
		ptail->next = pcur2;
	}

	return newList;
}
/*
带哨兵位的头节点:
    头指针->哨兵位->第一位有效数据位->...
可以在函数中先malloc一个节点,{    phead=malloc(sizeof(struct ListNode));    },
不存放有效数据,不必修改头指针指向/判断是否为NULL,可以直接使用"phead->next",便于"尾插"等方法实现,
返回"真正的头指针"-- phead->next,最后free(phead).
*/




//6.链表分割 + 重组
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在大于或等于x的结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针
struct ListNode* partition(struct ListNode* pHead, int x) 
{
	if (!pHead)
		return pHead;

	//采用"带哨兵位的头节点"方法
	//取节点下来尾插
	struct ListNode* SmallerHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(SmallerHead);
	struct ListNode* BiggerHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(BiggerHead);
	struct ListNode* pcur = pHead;
	struct ListNode* SmallerTail = SmallerHead;
	struct ListNode* BiggerTail = BiggerHead;
	SmallerHead->next = BiggerHead->next = NULL;				//最好先初始化

	while (pcur)												//分离链表
	{
		if (pcur->val < x)
		{
			SmallerTail->next = pcur;
			SmallerTail = SmallerTail->next;
			pcur = pcur->next;
		}
		else
		{
			BiggerTail->next = pcur;
			BiggerTail = BiggerTail->next;
			pcur = pcur->next;
		}
	}

	SmallerTail->next = BiggerHead->next;						//重组:较大数链表"真正的头"连接到较小数链表的尾
	BiggerTail->next = NULL;									//截断尾部置空 !!! (重要)

	struct ListNode* realHead = SmallerHead->next;
	free(BiggerHead);
	free(SmallerHead);
	
	return realHead;											//返回较小数链表"真正的头指针"
}





//7. 链表的回文结构
/*
对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构
回文:以中间对称,如"1->2->1"或"1->2->2->1"
*/
/*方法:	(可能破坏原链表结构)
*1.找到中间节点----左中间节点pmid
*2.将后半链表逆序----将slow->next链表逆序为B,尾部置空
*3.比较两个链表----B链表长度<=总长度一半,以B结束为标准结束循环
*/
bool chkPalindrome(struct ListNode* A) 
{
	if (A==NULL)									//排除特例--空链表
	{
		return true;
	}
	//1.使pmid指向左中位节点
	struct ListNode* pcur = A;
	struct ListNode* pmid = A;
	int num = 0;
	while (pcur->next)
	{
		pcur = pcur->next;
		num++;
		if (num%2==0)
		{
			pmid = pmid->next;
		}
	}
	//2.将链表pmid->next逆序为B,尾部置空
	struct ListNode* SecondHalf = pmid->next;
	struct ListNode* B = NULL;
	while (SecondHalf)								//逐个取下头插
	{
		struct ListNode* ptmp = SecondHalf->next;
		SecondHalf->next = B;
		B = SecondHalf;
		//迭代
		SecondHalf = ptmp;
	}												//循环已经将B链表尾部置空
	//3.逐个比较A和B,以B为结束标志
	while (B)
	{
		if (A->val != B->val)
		{
			return false;
		}
		A = A->next;
		B = B->next;
	}
	return true;
}







//8. 输入两个链表，找出它们的第一个公共结点(不考虑环)
/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null.
题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构
进阶：你能否设计一个时间复杂度 O(m + n) ,仅用 O(1) 内存的解决方案？
*/
//法一:[******  逆序再逆序?  *******]
//法二:先遍历一遍,求出节点数lenA,lenB;让长的链表先迭代差值步,再一起比较-迭代
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	if (!headA||!headB)							//排除空链表特例
	{
		return NULL;
	}
	int lenA = 0, lenB = 0;
	struct ListNode* pcurA = headA;
	struct ListNode* pcurB = headB;
	while (pcurA)
	{
		lenA++;
		pcurA = pcurA->next;
	}
	while (pcurB)
	{
		lenB++;
		pcurB = pcurB->next;
	}
	//得到A,B的节点数,接下来排除差值
	pcurA = headA;
	pcurB = headB;
	int gap = 0;								//存放差值
	if (lenA>=lenB)
	{
		gap = lenA - lenB;
		while (gap--)
		{
			pcurA = pcurA->next;
		}
	}
	else
	{
		gap = lenB - lenA;
		while (gap--)
		{
			pcurB = pcurB->next;
		}
	}
	//此时二者剩余节点数同步
	while (pcurA)
	{
		if (pcurA==pcurB)
		{
			return pcurA;
		}
		pcurA = pcurA->next;
		pcurB = pcurB->next;
	}
	return NULL;
}







//9. 给定一个链表，判断链表中是否有环
/*
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示(next本应当存放NULL的)链表尾连接到链表中的位置
索引从 0 开始:第一节点为 0 ...;pos 为 -1 或者链表中的一个 有效索引.
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/
bool hasCycle(struct ListNode* head) 
{
	//[******  快慢指针  *******]
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)					//已经过一次迭代,若无环,不可能相等;若有环,一定会相等
		{
			return true;
		}
	}
	return false;
}
//分析:链表带环问题求解原理:
/*
数学问题:
假设入环前有a个节点(标记为:0~~a-1),环中有n个节点(标记为:0~~n-1):
1.	入环前不可能相遇,slow(前进a步)初次指向入环第一个节点(标记为环中的0号位)时,
	fast(前进2*a步)指向节点(标记为环中的 [a%n] 号位),
	假设slow继续前进x步,二者相遇,则表示为:  (a%n)+2*x-x == k*n    ;(均为整数)
										---->		a+x == k'*n   ;(k与k'不一定相同)
	得到 x 的解集,显然,相邻的两次解 x 之差必定为 n ,
	即第二次相遇比第一次相遇slow多前进了 n 步,可以算出 环的节点个数;
2.	再次使用"快慢指针法",快指针先走 n 步;
	再一起逐步迭代,迭代几次相遇即表示 a 为多少;
	比如:未经过同步迭代即相遇,表示 a==0 ,即没有环外节点,"尾节点"指针直接指向"头节点".
*/







//10. 给定一个链表，返回链表开始入环的第一个节点(指针)。 如果链表无环，则返回 NULL
/*
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置
索引从 0 开始:第一节点为 0 ...;pos 为 -1 或者链表中的一个 有效索引.
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表.
*/
/*
法一:在(题9)中相遇位置断开(此节点next置空),即转换为两链表相遇问题(题8),之后再连上.
法二:根据(题9)后面的原理.
法三:根据结论:一指针从头节点和一指针从(题9)相遇点出发,逐步迭代,一定会在入环点相遇.
     证明:设环外节点数 a ,环内节点数 n ,相遇时slow在环中走了 x 步,
	      则:    2*(a+x) = a+x+k*n  (k>=1的整数)
		  ---->        a = k*n-x
		  即从头节点逐步迭代到入环点的步数 a ,从相遇点出发(k*n-x)步也正好到达入环点.
*/
struct ListNode* detectCycle(struct ListNode* head) 
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	int pos = 0;									//可以定位入环位置
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)					//已经过一次迭代,若无环,不可能相等;若有环,一定会相等
		{
			break;
		}
	}
	if (!fast || !fast->next)				//发现NULL,一定无环
	{
		pos = -1;									//无环
		return NULL;
	}
	//下面一定是fast==slow的情况
	struct ListNode* cur = head;
	struct ListNode* meet = fast;
	while (cur!=meet)						//相遇时退出循环
	{
		cur = cur->next;
		meet = meet->next;
		pos++;										//比如全环,第一位节点相遇,不进入循环,pos==0
	}
	return cur;
}






//11. 复制带随机指针的链表
/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝
深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。
返回复制链表的头节点。
用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
	val：一个表示 Node.val 的整数。
	random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
*/
/*
***********  方法:  **********
1.(开辟)复制每一个节点,接到被复制节点的后面,即拆散原链表(next),插入重组.(原链表长度*2)
2.赋值random:不需要考虑原random联系,只需要对每一个原节点: A->next->random=A->random->next.(random==NULL另算)
3.把新节点重新串联.
*/
struct Node* copyRandomList(struct Node* head) 
{
	if (!head)
	{
		return head;
	}
	//1.开辟,复制,插入
	struct Node* cur = head;
	while (cur)
	{
		struct Node* pnext = cur->next;
		cur->next = malloc(sizeof(struct Node));				//开辟,插入
		assert(cur->next);
		cur->next->next = pnext;								
		cur->next->val = cur->val;								//复制val
		cur = cur->next->next;									//迭代
	}
	//2.赋值random
	cur = head;
	while (cur)
	{
		if (cur->random)										//赋值random
		{
			cur->next->random = cur->random->next;
		}
		else
		{
			cur->next->random = NULL;
		}
		cur = cur->next->next;									//迭代
	}
	//3.重组
	struct Node* newhead = malloc(sizeof(struct Node));			//带哨兵位,应返回 newhead->next,且free
	assert(newhead);
	newhead->next = NULL;										//初始化,防止空链表时返回乱码
	struct Node* newcur = newhead;
	cur = head;
	while (cur)
	{
		struct Node* curcopy = cur->next;						
		cur->next = curcopy->next;								//重组原链表
		newcur->next = curcopy;									//串联新链表
		cur = cur->next;										//迭代
		newcur = newcur->next;
	}
	struct Node* realhead = newhead->next;
	free(newhead);												//free释放空间
	return realhead;
}







//12. 对链表进行插入排序(升序)
/*
插入排序 算法的步骤:
1.插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
2.每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
3.重复直到所有输入数据插入完为止。
*/
/*
创建一个新链表头(指针),依次取下head链表中的节点,判断并插入到新链表的适当位置
*/
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (!head)											//排除空链表
	{
		return NULL;
	}
	struct ListNode* newhead = malloc(sizeof(struct ListNode));
	assert(newhead);
	newhead->next=head;									//初始化新链表
	struct ListNode* newcur = newhead;					//用来遍历新链表
	head = head->next;									//指向剩下的链表(头指针)
	newcur->next->next = NULL;							//新链表尾部置空
	
	//上面步骤给新链表一个节点,旧链表后移一节点
	while (head)
	{
		newcur = newhead;								//每次从头遍历新链表
		struct ListNode* headnext = head->next;			//存放剩下的链表的次节点
		int x = head->val;
		while (newcur->next)							//从新链表第一个有意义节点开始遍历,不会自动结束,必须break跳出
		{
			//头插或中间插入
			if (x <= newcur->next->val)					//填充到newhead->next的前面
			{
				head->next = newcur->next;
				newcur->next = head;
				break;									//已插入到适当位置,去比较下一个剩余链表头
			}
			else
			{
				newcur = newcur->next;					//对新链表迭代
			}
			//尾插
			if (newcur->next==NULL)						//说明x大于新链表所有数据,应接到后面
			{
				newcur->next = head;
				newcur->next->next = NULL;				//新链表尾部置空
				break;
			}
		}
		head = headnext;								//对剩余链表迭代
	}
	struct ListNode* realhead = newhead->next;
	free(newhead);
	return realhead;
}






//13. 删除(升序)链表中重复的结点
/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表 1->2->3->3->4->4->5  处理后为 1->2->5
进阶：空间复杂度 O(n)\O(n)  ，时间复杂度 O(n) \O(n)
*/
//双指针定位,first--last
struct ListNode* deleteDuplication(struct ListNode* pHead) 
{
	if (!pHead||!(pHead->next))											//排除空链表和单节点链表
	{
		return pHead;
	}
	struct ListNode* prevHead = malloc(sizeof(struct ListNode));		//带哨兵位
	if (!prevHead)
		exit(-1);
	prevHead->next = pHead;
	struct ListNode* prev = prevHead;									//prev->next==first以便删除
	struct ListNode* first = prev->next;
	struct ListNode* last = first->next;

	while (1)
	{
		if (last && first->val == last->val)
		{
			while (last && first->val == last->val)						//last指向尾或指向不同值
			{
				struct ListNode* lastnext = last->next;
				//free(last);											//两处释放空间且不影响功能	
				last = lastnext;
			}
			//free(first);
			prev->next = last;											//去除中间等值节点,不改变prev
		}
		else
		{
			prev = prev->next;											//直接迭代prev
		}
		if (!prev || !(prev->next))										//完成遍历
		{
			break;
		}
		first = prev->next;												//三指针继续循环
		last = first->next;
	}
	struct ListNode* realHead = prevHead->next;
	free(prevHead);
	return realHead;
}



























