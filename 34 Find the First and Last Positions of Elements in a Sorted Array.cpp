/*
解法：分治法，与33题中的做法类似。
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<int> {-1, -1};
        
        int len(nums.size());
        
        if(len == 1) {
            if(nums[0] == target) 
                return vector<int> {0, 0};
            else
                return vector<int> {-1, -1};
        }
        
        int mid(len / 2), flag(0);
        vector<int> res, result;
        
        if(target <= nums[mid - 1]) {
            for(int i(0); i < mid; ++i) {
                if(nums[i] == target) {
                    res.push_back(i);
                    for(int j(mid - 1); j >= i; --j) {
                        if(nums[j] == target) {
                            res.push_back(j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        if(target >= nums[mid]) {
            for(int i(mid); i < len; ++i) {
                if(target == nums[i]) {
                    res.push_back(i);
                    for(int j(len - 1); j >= i; --j) {
                        if(target == nums[j]) {
                            res.push_back(j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        if(res.empty()) 
            return vector<int> {-1, -1};
        else {
            result.push_back(res[0]);
            result.push_back(res[res.size() - 1]);
        }
        
        return result;
    }
};

