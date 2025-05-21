// 使用uthash.h库实现"两数之和"问题
//前置步骤:将'uthash.h'存储在项目文件夹里
#include <stdio.h>
#include "uthash.h"

// 定义哈希表结构体
struct hashTable
{
	int key;
	int val;
	UT_hash_handle hh;		//uthash必需字段
};

//全局哈希表指针
struct hashTable* hashtable = NULL;

//查找函数find
struct hashTable* find(int ikey)
{
	struct hashTable* tmp = NULL;
	//查找键,若找到返回该键对应的地址,否则返回空
	HASH_FIND_INT(hashtable, &ikey, tmp);
	return tmp;
}

//插入函数 
void insert(int ikey, int ival) {
	struct hashTable* it = find(ikey);
	if (it == NULL) {
		//如果target-x不存在于哈希表中
		//则将x插入哈希表,key为x的值,value为x在数组里的下标
		struct hashTable* tmp = (struct hashTable*)malloc(sizeof(struct hashTable));
		tmp->key = ikey;
		tmp->val = ival;
		//将节点链接到哈希表对应的位置.
		HASH_ADD_INT(hashtable, key, tmp);

	}
	else
	{
		it->val = ival;
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	hashtable = NULL;
	for (int i = 0; i < numsSize;i++)
	{
		int comp = target - nums[i];
		struct hashTable* it = find(comp);

		if (it != NULL)
		{
			int* result = (int*)malloc(sizeof(int) * 2);
			result[0] = it->val;
			result[1] = i;
			*returnSize = 2;
			return result;
		}
		
		insert(nums[i], i);
	}
	*returnSize = 0;
	return NULL;

}

// 测试main函数
int main() {
	int nums[] = { 2, 7, 11, 15 };
	int target = 9;
	int returnSize;
	int* indices = twoSum(nums, 4, target, &returnSize);

	if (indices != NULL) {
		printf("Indices: [%d, %d]\n", indices[0], indices[1]);
		free(indices);
	}
	else {
		printf("No solution found.\n");
	}

	return 0;
}