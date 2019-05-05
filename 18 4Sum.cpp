/*
Method:
  双指针：前面已经有了三数之和的算法，那么四数之和就变成了三数之和嵌套一层循环；
  以前面两个为固定，后面两个变量用双指针进行搜索，同时通过各类条件对重复的元素进行剔除；

Note:
  有些带有判断的算法中，我们可以去思考如何让程序提前结束或者跳跃，比如最大值、最小值；
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		int len = nums.size();

		for (int i = 0, sum = 0; i < len - 3; ++i) {
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			for (int j = i + 1; j < len - 2; j++) {
				if (j != i + 1 && nums[j] == nums[j - 1])
					continue;
				if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target)
					continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				int left = j + 1, right = len - 1;
				while (left < right) {
					sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum < target)
						++left;
					else if (sum > target)
						--right;
					else {
						res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
						while (left < right && nums[left + 1] == nums[left])
							++left;
						while (left < right && nums[right - 1] == nums[right])
							--right;
						++left;
						--right;
					}
				}
			}
		}
		return res;
	}
};

