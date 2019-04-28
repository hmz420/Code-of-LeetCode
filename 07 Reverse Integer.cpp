/*
Method:
  解法:将数字的第一位取出来，然后一个个搬到新的变量的后面去；

Note:
  ans = ans * 10 + x % 10; x /= 10;一步步进行反转
*/

class Solution {
public:
	int reverse(int x) {
		long ans = 0;
		
		while (x != 0) {
			ans = ans * 10 + x % 10;
			x /= 10;
		}

		return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
	}
};

