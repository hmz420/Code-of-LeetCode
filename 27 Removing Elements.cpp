/*
解法：
    解法1：与26题相似，将满足要求的元素放到前面去，不需要排序;
    解法2：采用指针，若指针指向的元素的值不符合要求，删除;
 */

//指针：
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len(nums.size()), index(0);
        for(int i(0); i < len; ++i) {
            if(nums[i] != val) {
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }
};

//传统：
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end();)
		{
			if (*it == val)
			{
				it = nums.erase(it);
			}
			else
				it++;
		}
		return nums.size();

	}
};

