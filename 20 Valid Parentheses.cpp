/*
Method:
  解题思路：模拟人的思维方式，如果是你人为去判断这个东西是不是有效的，一个常见的思路就是：
  从最相邻的配对符号入手，看到一对删除一对，一直发现删除不了的一对，就证明这不是有效的；
  如果删除完了，那么这就是有效的；
  
  算法思路：让计算机跟人一样地直接找出一对很难，由于数组的顺序性，我们需要从头到尾去遍历，
  那么遇到一对我们就忽略一对，直到找到不匹配为止；

Note:
  1)string类型若初始化为空的，只能从后面添加元素，而无法访问坐标；
  2)若要访问坐标，可以先分配空间，这是需要考虑到越界；
  3)若采用地址的用法，那么首地址+1才是第一个元素的位置；
*/


Class Solution {
public:
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


