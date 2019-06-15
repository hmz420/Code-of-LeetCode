/*
解法：
    将这个数组进行了旋转反倒让我们变得轻松，可以视为题目帮我们做了分治的第一步;
    我们首先需要确定在前面一段进行搜索，还是后面一段进行搜索，那么比较两端的数就可以知道;
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len(nums.size());
        if(nums.empty()) 
            return -1;
        if(nums[0] == target) 
            return 0;
        if(nums[0] < target) {
            for(int i(0); i < len - 1; ++i) {
                if(nums[i] == target) 
                    return i;
                else if(nums[i] < nums[0]) 
                    return -1;
            }
        }
        if(nums[len - 1] >= target) {
            for(int i(len - 1); i > 0; --i) {
                if(nums[i] == target) 
                    return i;
                else if(nums[i] > nums[len - 1]) 
                    return -1;
            }
        }
        return -1;
    }
};

