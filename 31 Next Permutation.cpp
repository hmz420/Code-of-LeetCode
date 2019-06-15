/*
解法：首先自己用笔手写一遍1356这四个数从小到大排列的全组合，你会怎么写？
    你肯定会先从最接近个位数的地方开始，而不是位数更高的地方开始;从而得到1365;
    之后，你会开始找3的麻烦，因为你要把这个数再变大只能把高一位的数变大，
    那么你肯定会从3后面找一个比3大，但是又最小的数来代替3,那就是5,那么是1563？
    当然不，而是1536;
    在把3和5的位置调换后，你会将5后面的数重新从小到大重新排列以得到最小的数。
    这就是解法。
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tar(INT_MAX), index(0), len(nums.size());
        for(int i(len - 1); i > 0; --i) {
            if(nums[i - 1] < nums[i]) {
                for(int j(len - 1); j > i - 1; --j) {
                    if(nums[j] > nums[i - 1] && nums[j] < tar) {
                        tar = nums[j];
                        index = j;
                    }
                }
                nums[index] = nums[i - 1];
                nums[i - 1] = tar;
                sort(nums.begin()+i, nums.end());
                return ;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};