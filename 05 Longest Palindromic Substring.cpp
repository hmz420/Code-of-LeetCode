/*
Method:
  1）暴力算法：每一个元素都去寻找一个跟它一样的元素，然后判断两个元素之间的字符串是不是回文字符串；
  2）反向做法：将字符串反过来，然后判断两个字符串中相同的字符子串；
  3）中心拓展算法：每一元素或者每两个相同的元素，都可以向两边拓展，直到对称位置出现不同的元素；

Note:
  1）有的条件可以放到for或者while循环当中，这样能够让程序语句更精炼；
  2）对于有边界的数组来说，可以考虑将条件进行判断后再累加，而不是先累加再判断，通过改变条件的位置即可实现；
 */

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		else
		{
			int l = s.length();
			int i = 0, start = 0, end = 0;
			int len = 0, len_max = 0, index = 0;
			
			while (i < l)
			{
				start = i;
				end = i;
				while (s[end] == s[end + 1] && end < l - 1) ++end;
				i = end + 1;
				while (start > 0 && end < l - 1 && s[start - 1] == s[end + 1])
				{
					--start;
					++end;
				}
				len = end - start + 1;
				if (len > len_max)
				{
					index = start;
					len_max = len;
				}
			}

			return s.substr(index, len_max);
		}
	}
};

