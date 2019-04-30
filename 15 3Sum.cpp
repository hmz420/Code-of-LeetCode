/*
Method:
  1）三指针法：三指针或者双指针有时候能够将时间复杂度降低一维；第一个指针用来定下第一个元素，第二三个指针用来搜索；
  第二三个指针位于剩余元素的两端，通过两者之和与目标值的大小关系从两端不断逼近正确结果；
  2)哈希表法：将第一个元素固定，那么就变成了两个数求和；根据Two Sum得知，两数之和有几种方法，可以调用；

Note:
  1）sort可以进行vector的元素大小排序；
  2）双指针法，对于有序数组来说，通过逼近的方法可以降低时间复杂度；
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		int l = nums.size();

		if (l <= 2) return res;
		else
		{
			for (int i = 0; i < l - 2; i++)
			{
				if (nums[i] > 0) return res;
				if (i == 0 || nums[i] != nums[i - 1])
				{
					int left = i + 1, right = l - 1;
					int target = -nums[i];

					while (left < right)
					{
						if (nums[left] + nums[right] == target)
						{
							res.push_back(vector<int>{nums[i], nums[left], nums[right]});

							while (left < right && nums[left + 1] == nums[left]) 
								++left;
							while (left < right && nums[right - 1] == nums[right]) 
								--right;
							
							++left;
							--right;
						}
						else if (nums[left] + nums[right] <= target) 
							++left;
						else 
							--right;
					}
				}
			}
			return res;
		}
	}
};

