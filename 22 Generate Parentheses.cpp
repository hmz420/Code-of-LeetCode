/*
  解法1：暴力解法
  先列举所有的括号组合，然后根据17题的算法对每一种组合进行有效性判断;
  解法2：回溯算法
  在列举的过程当中便进行判断，如果'('的数量小于n，那么可以加'('，如果')'的数据小于'('，可以加')';
 */

// Solution1:

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
            return res;
        string tar = "()";
        int len(2*n);
        int index(0);
        func(res, "", tar, len, 0);
        len = res.size();
        while(index < len) {
            if(!isValid(res[index])) {
                res.erase(res.begin() + index);
                --index;
                --len;
            }
            ++index;
        }
        return res;
    }
    
    void func(vector<string>& res, string str, string tar, int len, int k) {
        if (str.length() == len) {
          res.push_back(str);
          return;
        }
        for (int i = 0; i < 2; ++i) {
          str += tar[i];
          func(res, str, tar, len, k + 1);
          str.erase(str.end() - 1);
        }
        return;
    }
    
    bool isValid(string s) {
        int len = s.length();
        if(s.empty())
            return true;
        else if(len % 2 == 1)
            return false;
        else {
            int key = 0;
            char* res = (char*)malloc(len + 1);
            for(int i = 0; i < len; ++i) {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    ++key;
                    *(res + key) = s[i];
                }
                else if(s[i] == *(res + key) + 1 || s[i] == *(res + key) + 2) 
                    --key;
                else
                    return false;
            }
            return (!key)? true : false;
        }
        return 1;
    }
};

// Solution2:

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
            return res;
        func(res, "", 0, 0, n);
        return res;
    }
    
    void func(vector<string>& res, string str, int open, int close, int k) {
        if (str.length() == 2 * k)
        {
            res.push_back(str);
            return;
        }
        if(open < k) {
            func(res, str + '(', open + 1, close, k);
        }
        if(close < open) {
            func(res, str + ')', open, close + 1, k);
        }
    }

};