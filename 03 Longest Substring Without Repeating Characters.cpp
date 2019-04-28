/*
Method:
  1）双指针法：先固定后面的元素，然后让前面的元素与这个元素依次比较，由于从0开始，所以保证了收纳进来的元素都符合要求；
     由于一直都在迭代最长长度，所以出现重复元素时，前面的部分可以直接扔掉；
  2）双指针+ASCII：每一个字符都有自己的唯一的ASCII代号，那么判别是否有重复的方法就可以通过ASCII代号找相应的位置，那么重复的字符出现时，跟上一种的后续方法一样；

Note:
  1）ASCII码可以看作一个字符经过哈希函数处理之后的坐标，所以用 ASCII 和 vector 则能够实现哈希表一样的定点访问，而不是遍历访问；
  2）vector<int> m(128, -1) 是指创建 128 个 -1；
  3）不能只考虑出现标志时才去计算某个东西，因为很有可能到达末尾都没有出发标志，解决方案就是每一次循环都计算，不管触没触发标志，不影响时间复杂度；
*/

/* 双指针 + ASCII */
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

/* 双指针 */
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int l = s.length();
		int len = 1;
		if (s.empty()) len = 0;
		else
		{
			int key = 0;

			for (int i = 0; i < l; i++)
			{
				for (int j = key; j < i; j++)
				{
					if (s[j] == s[i])
					{
						key = j + 1;
						break;
					}
				}
				len = max(len, i - key + 1);
			}

		}

		return len;
	}
};

