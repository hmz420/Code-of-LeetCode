/*
解法：采用快慢指针的方式，一个用来检索整个数组，另一个用来存储不重复的元素。
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        } 
        if(nums.size() == 1) {
            return 1;
        }
        
        int index(0);
        for(int i(1); i < nums.size(); ++i) {
            if(nums[index] != nums[i]) {
                ++index;
                nums[index] = nums[i];
            }
        }
        return ++index;
    }
};

