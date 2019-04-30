/*
Method:
  解法：15 3Sum 中已经探讨了三个数之和的较为有效率的算法，此题类似，采用三指针的方式；
  区别就是：此题的后两个指针在搜寻过程终止的条件发生了改变，通过与目标值之间的差值，对结果进行迭代；

Note:
  避免固化思维：定下一个指针，后两个指针的和与目标差值进行比较，这样会多出一步计算过程，即计算目标值与
  第一个指针数值之间的差值；此类情况有时方便，有时复杂，视情况而定；
*/

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int res = INT_MAX, len = nums.size();
		int left, right = 0;
		int nums0, sum, min_z = INT_MAX;

		for (int i = 0; i < len - 2; ++i)
		{
			nums0 = nums[i];
			for (left = i + 1, right = len - 1; left < right;)
			{
				sum = nums0 + nums[left] + nums[right];
				if (target == sum)
					return sum;
				if (abs(target - sum) < min_z)
				{
					res = sum;
					min_z = abs(target - sum);
				}
				if (sum > target)
					--right;
				else
					++left;
			}
		}
		return res;
	}
};

