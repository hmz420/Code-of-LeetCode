/*
1）暴力解法：通过两个循环嵌套，对各个元素之和进行遍历；
2）两遍哈希表：先创建哈希表，然后对哈希表进行搜索；
3）一遍哈希表：思路即是一边创建哈希表的部分元素，一边进行搜索，根据数据规律（从小到大），
   那么目标值一定在此数的后面，所以从后面创建，并搜索，既可以保证不需要进行过多重复的计算;

Note:
  1）哈希表包含的头文件：#include <unordered_map>；
  2）哈希表的创建：unordered_map<int, int> hash；
  3）hash.find()函数返回的是指针而不是一个int；
*/
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> v;
		unordered_map<int, int> hash;
		for (int i = nums.size() - 1; i >= 0; hash[nums[i]] = i, i--)
		{
			if (hash.find(target - nums[i]) == hash.end()) continue;
			v.push_back(i);
			v.push_back(hash[target - nums[i]]);
		}
		return v;
	}
};