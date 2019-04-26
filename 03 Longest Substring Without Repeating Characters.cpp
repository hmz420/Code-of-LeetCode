/*
Method:
  1）暴力解法：每一个后面出现的元素都跟前面的一段进行比较，没有就填进去，有就将初始位置向后推一位；
  2）双指针：第一个指针为数组中的一位，第二个指针遍历第一个指针之前的元素，如果没有重复，则将第一个指针向后移一位，第二个指针重新遍历;
    如果有重复，那么第二个指针直接跳到重复位置后面一位，因为重复的位置总会跟后面有重复，子串的长度通过下标进行反馈；
  3）双指针+ASCII：每一个字符都有自己的唯一的ASCII代号，那么判别是否有重复的方法就可以时通过ASCII代号找相应的位置，那么重复的字符出现时，跟第二种的后续方法一样；

Note:
  1）ASCII码可以看作一个字符经过哈希函数处理之后的坐标，所以用ASCII和vector则能够实现哈希表一样的定点访问，而不是遍历访问；
  2）vector<int> m(128, -1)是指创建128个-1；
  3）不能只考虑出现标志时才去计算某个东西，因为很有可能到达末尾都没有出发标志，解决方案就是每一次都计算，不管触没触发标志；
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int l = s.length();
		int key = -1;
		int len = 0;
		vector<int> m(128, -1);
		for (int i = 0; i < l; ++i)
		{
			if (m[s[i]] != -1 && m[s[i]] >= key) key = m[s[i]];
			if (i - key > len) len = i - key;
			len = (i - key > len) ? i - key : len;
			m[s[i]] = i;
		}
		return len;
	}
};

