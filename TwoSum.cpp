// ʹ��uthash.h��ʵ��"����֮��"����
//ǰ�ò���:��'uthash.h'�洢����Ŀ�ļ�����
#include <stdio.h>
#include "uthash.h"

// �����ϣ��ṹ��
struct hashTable
{
	int key;
	int val;
	UT_hash_handle hh;		//uthash�����ֶ�
};

//ȫ�ֹ�ϣ��ָ��
struct hashTable* hashtable = NULL;

//���Һ���find
struct hashTable* find(int ikey)
{
	struct hashTable* tmp = NULL;
	//���Ҽ�,���ҵ����ظü���Ӧ�ĵ�ַ,���򷵻ؿ�
	HASH_FIND_INT(hashtable, &ikey, tmp);
	return tmp;
}

//���뺯�� 
void insert(int ikey, int ival) {
	struct hashTable* it = find(ikey);
	if (it == NULL) {
		//���target-x�������ڹ�ϣ����
		//��x�����ϣ��,keyΪx��ֵ,valueΪx����������±�
		struct hashTable* tmp = (struct hashTable*)malloc(sizeof(struct hashTable));
		tmp->key = ikey;
		tmp->val = ival;
		//���ڵ����ӵ���ϣ���Ӧ��λ��.
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

// ����main����
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