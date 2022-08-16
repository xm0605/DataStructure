#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"


//1. 原地移除数组中所有的元素val,要求时间复杂度为O(N),空间复杂度为O(1)
/*
给你一个数组 nums 和一个值 val，你需要 原地(在原数组空间内) 移除所有数值等于 val 的元素,并返回移除后数组的新长度.
元素的顺序可以改变,你不需要考虑数组中超出新长度后面的元素.
*/
int my_removeElement1(int* nums, int numsSize, int val) 
{
	int down = 0;					//发现的val个数,也是后续数据前移个数
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i]==val)			//配合i++,保持(i-down)不变; 没遇到val时,目标位置随i++变化
		{
			down++;
		}
		if (nums[i] != val)			//只有没遇到val时,才赋值
		{
			if (down)				//一直没遇到val,则不必赋值
			{
				nums[i - down] = nums[i];
			}
		}
	}
	return numsSize - down;

}

int removeElement(int* nums, int numsSize, int val) 
{
	//双下标指示
	int src = 0;					//源元素下标
	int dst = 0;					//目标位置下标
	for (src = 0; src < numsSize; src++)
	{
		//如果没遇到val,则赋值,并dst++,src++
		//如果遇到val,则不赋值,只有src++
		if (nums[src]!=val)
		{
			if (dst!=src)			//错位时才赋值
			{
				nums[dst] = nums[src];
			}
			dst++;
		}
	}
	return dst;
}

//因为不在乎顺序,也可以顺序寻找val,把逆序的数据赋给val的空间
//双向寻找需要考虑的状况太多了,不推荐
int my_removeElement2(int* nums, int numsSize, int val)
{
	if (numsSize == 0)						//居然还要考虑[],numsSize=0的情况,真奇葩
	{
		return 0;
	}
	int src = numsSize - 1;					//逆序,从最后一位作为预备
	while ((src >= 0)&&(nums[src] == val))		//但是赋值前要保证nums[src]!=val
	{
		src--;
	}
	if (src<0)								//要考虑[1],val=1的情况
	{
		return 0;
	}
	for (int i = 0; i < src; i++)			//结束条件不同
	{
		if (nums[i]==val)					//覆盖掉val,并更新替换的变量
		{
			nums[i] = nums[src];
			do
			{
				src--;
			} while (nums[src] == val);
		}
	}
	return src+1;							//下标0~src都是有效数据

}






//2. 删除排序数组中的重复项 (去重)
/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 
*/
int removeDuplicates(int* nums, int numsSize) 
{
	if (numsSize == 0)								//唯一特例
		return 0;

	int dest = 1;									//指向可能被覆盖的第一个元素,前面都是完成去重的元素
	int cur = 1;									//从nums[1]开始遍历数组,寻找新的元素
	
	for (cur = 1; cur < numsSize; cur++)			//numsSize==1时,不进入循环
	{
		if (nums[cur]!= nums[cur-1])				//nums[cur]与上一个元素相同则直接cur++; 遇到新元素则覆盖掉nums[dest]
		{
			nums[dest] = nums[cur];
			dest++;									//dest更新
		}
	}

	return dest;
}


//3. 合并两个有序数组
/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。
*/
void my_merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
	//如果n=0,nums1没有改动
	//如果m=0,
	if (m==0)
	{
		for (int i = 0; i < n; i++, m++)
		{
			nums1[m] = nums2[i];
		}
		return;
	}


	int mi = 0;										//mi循环内不归零
	int ni = 0;
	for (; ni < n; ni++)				
	{
		for (; mi < m; mi++)						//mi,m会改变
		{
			if (nums2[ni]< nums1[mi])
			{
				//原num1数组后移一位
				for (int i = m; i >mi; i--)
				{
					nums1[i] = nums1[i - 1];
				}
				nums1[mi] = nums2[ni];				//nums2[ni]插入
				m++;
				break;
			}
			if (mi==m-1)							//后续nums2直接接在nums1后面
			{
				for  (int i = ni;  i < n; i++,m++)
				{
					nums1[m] = nums2[i];
				}
				return;
			}
		}
	}
}

//法二:nums2拷贝nums1后面,然后排序

//法三:以空间换时间,空间复杂度O(m+n),时间复杂度O(m+n)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	if (n==0)
	{
		return;
	}
	if (m==0)
	{
		for (int i = 0; i < n; i++)
		{
			nums1[i] = nums2[i];
		}
		return;
	}
	int* ptmp = malloc(sizeof(int) * (m + n));
	assert(ptmp);
	int mi = 0;
	int ni = 0;
	int t = 0;					//ptmp的下标

	while (mi<m&&ni<n)
	{
		if (nums1[mi] <= nums2[ni])
		{
			ptmp[t] = nums1[mi];
			mi++;
			t++;
		}
		else
		{
			ptmp[t] = nums2[ni];
			ni++;
			t++;
		}
	}
	while (mi < m)
	{
		ptmp[t++] = nums1[mi++];
	}
	while (ni<n)
	{
		ptmp[t++] = nums2[ni++];
	}
	//上面三个while循环为下列代码的优化写法,更易读
	/*for (int i = 0; i < m + n; i++)
	{
		if (nums1[mi]<= nums2[ni])
		{
			ptmp[i] = nums1[mi];
			mi++;
		}
		else
		{
			ptmp[i] = nums2[ni];
			ni++;
		}

		//有效数据用完的情况:
		if (mi>=m)
		{
			for (int j= ni; j < n; j++)
			{
				ptmp[++i] = nums2[j];
			}
			break;
		}	
		if (ni>=n)
		{
			for (int j= mi; j < m; j++)
			{
				ptmp[++i] = nums1[j];
			}
			break;
		}
	}*/

	//赋值回nums1
	memmove(nums1, ptmp, sizeof(int) * (m + n));
	/*
	或:
	for (int i = 0; i < m + n; i++)
	{
		nums1[i] = ptmp[i];
	}*/
	free(ptmp);
}




//4. 向右旋转数组
/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
*/
/*
先处理:	k %= numsSize;
(1):每次右旋一位,旋转k次					时间复杂度O(k*n),空间复杂度O(1);
(2):开辟k位的空间,保存后k个值,整体移动		时间复杂度O(n),空间复杂度O(k);
(3):后k位逆序,前n-k位逆序,整体逆序			时间复杂度O(n),空间复杂度O(1);
*/
void reverse(int* arr, int left, int right)		//传递左右下标
{
	while (left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++; 
		right--;
	}
}
void rotate(int* nums, int numsSize, int k) 
{
	k %= numsSize;								//优化k值
	reverse(nums, 0, numsSize - 1 - k);
	reverse(nums, numsSize - k, numsSize - 1 );
	reverse(nums, 0, numsSize - 1);
}







//5. 数组形式的整数加法(大数计算超过long long,只能用数组)
/*
整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。
			例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
求给定 num 整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 ,返回一个动态开辟的数组空间
returnSize用于指示返回动态数组位数
*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
	int kSize = 0;
	int tmp = k;
	while (tmp)
	{
		kSize++;
		tmp/= 10;
	}
	int length = (numSize > kSize) ? numSize : kSize;
	int* retArr = malloc(sizeof(int) * (length + 1));			//开辟足够空间
	if (retArr==NULL)
	{
		exit(-1);
	}

	int add = 0;								//进位加数
	int set = 0;								//两方对应位置之和,下面判断是否 <=9
	int i = 0;
	for (i = 0;(numSize>0)||(k!=0)||add; i++)
	{
		//将数组[0]~[i-1]整体后移一位
		for (int j = i ; j >=1 ; j--)
		{
			retArr[j] = retArr[j-1];
		}

		numSize--;								//当前对应位置num[numSize],下面判断 numSize>=0
		if (numSize>=0)
		{
			set=num[numSize] + (k % 10)+add;
			if (set <= 9)
			{
				retArr[0] = set;
				add = 0;
			}
			else
			{
				retArr[0] = set%10;
				add = 1;
			}
		}
		else
		{
			set = 0 + (k % 10)+add;
			if (set <= 9)
			{
				retArr[0] = set;
				add = 0;
			}
			else
			{
				retArr[0] = set % 10;
				add = 1;
			}			
		}	
		k /= 10;								//更新k值
	}
	
	*returnSize = i;
	return retArr;
}



