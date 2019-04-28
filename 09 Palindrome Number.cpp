/*
Method:
  解法1：取对称数字，将对称位置的两个数字进行比较；
  解法2：将数字整个进行反转，然后比较两个数字；
  解法3：将数字转换成字符串，就只需要比较对称的两个元素，省去了取数字的计算过程；

Note:
  1）数字有时候变成字符串来进行处理效率更高；
  2）to_string是C++内置的函数可以直接使用；
  3）就时间复杂度来说，每一次比较对称位置和反转完之后比较一样；
  4）return只要保证该有的地方有就行，只要程序收到了return它就停了；
*/

class Solution {
public:
	bool isPalindrome(int x) {
		long num = 0;
		if (x == 0) return true;
		else if (x < 0) return false;
		else
		{
			int r = x;

			while (x)
			{
				num = 10 * num + x % 10;
				x /= 10;
			}

			if (num == r) return true;
			else return false;
		}
	}
};

