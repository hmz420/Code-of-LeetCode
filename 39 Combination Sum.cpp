/*
  回溯算法：
  设置两个截止条件，然后通过循环向后推
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> buffer;
        sort(candidates.begin(), candidates.end());
        backsearch(candidates, target, res, 0, buffer);
        return res;
    }
    
    void backsearch(vector<int>& candidates, int target, vector<vector<int> >& res, int key, vector<int>& buffer) {
        if(target < 0) return;
        if(target == 0) {
            res.push_back(buffer);
            return;
        }
        for(int start(key); start < candidates.size(); ++start) {
            if(target < candidates[start]) break;
            buffer.push_back(candidates[start]);
            backsearch(candidates, target - candidates[start], res, start, buffer);
            buffer.pop_back();
        }
        return ;
    }
};

