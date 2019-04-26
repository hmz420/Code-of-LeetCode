/*
Method:
  解法1：所以随便选择一个字符串作为标准，把它的前缀串，与其他所有字符串进行判断，看是否是它们所有人的前缀子串；
  解法2：纵向扫描：从下标0开始，判断每一个字符串的下标0，判断是否全部相同。直到遇到不全部相同的下标；
  解法3：横向扫描：前两个字符串找公共子串，将其结果和第三个字符串找公共子串……直到最后一个串

 Note:
   return的用法要悉知，有时可以代替break的作用。有的地方是否需要flag要谨慎，程序终止的方法可以用return进行简化
 */

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];

		int l = strs[0].length();
		int m = strs.size();
		string res = "";

		for (int i = 0; i < l; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (strs[j].length() < i || strs[j][i] != strs[0][i]) return res;
			}
			res += strs[0][i];
		}

		return res;
	}
};
