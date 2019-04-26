/*
Method:
  暴力解法：将字母按照Z排列，会连着地n个数组成一个周期，那么围绕着这个周期展开，记住最后一个周期地数不知道有多少，所以可以对最后一个周期单独设置筛选条件

Note:
  for(int i=0; i<…; j++)这个结构里面，不仅第一个位置能够填别的，第二个空的限制条件也可以有多个
*/

class Solution {
public:
	string convert(string s, int numRows) {
		string res;
		if (numRows == 1) res = s;
		else
		{
			int n = 2 * numRows - 2;
			int l = s.length();
			int cycle = l / n;
			for (int i = 0; i < numRows; ++i)
			{
				if (i == 0 || i == numRows - 1)
				{
					for (int j = 0; j <= cycle; ++j)
					{
						if (j < cycle) res += s[i + n * j];
						else if (j == cycle && i + n * j < l) res += s[i + n * j];
					}
				}
				else
				{
					for (int j = 0; j <= cycle; ++j)
					{
						if (j < cycle)
						{
							res += s[i + n * j];
							res += s[i + n * j + n - 2 * i];
						}
						else
						{
							if (i + n * j < l) res += s[i + n * j];
							if (i + n * j + n - 2 * i < s.length()) res += s[i + n * j + n - 2 * i];
						}
					}
				}
			}
		}
		return res;
	}
};

