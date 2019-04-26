/*
Method:
  解法1：暴力解法，用两个循环遍历所有的可能性；
  解法2：双指针，用两个初始化在两端的指针，将短的一边不断地像内部移动，以降低短板效应

Note:
  算法需要具有适应性，我们不需要将所有地情况都单独地列出来放在程序上，也是不能这样地，
  因为这样在时间复杂度上面不会有降低，只能降低频次。需要总结方法来降低时间复杂度
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int left = 0, right = height.size() - 1;
		while (left < right)
		{
			res = max(res, min(height[left], height[right]) * (right - left));
			(height[left] < height[right]) ? ++left : --right;
		}
		return res;
	}
};

