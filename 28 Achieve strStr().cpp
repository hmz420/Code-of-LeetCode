/*
解法：needle的第一个元素和字符串的元素相等时，开始比较后面的，常规操作;
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.length() < needle.length()) return -1;
        for(int i(0), index(0), flag(1); i < (haystack.length() - needle.length() + 1); ++i) {
            if(haystack[i] == needle[0]) {
                index = i;
                for(int j(0); j < needle.length(); ++j) {
                    if(needle[j] != haystack[i + j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    return index;
                } else {
                    flag = 1;
                }
            }
        }
        return -1;
    }
};

