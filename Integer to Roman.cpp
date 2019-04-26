/*
Method:
  解法：暴力解法

Note:
  需要注意4，5，9这三个数字
*/

class Solution {
public:
	string intToRoman(int num) {
		int res = 0, key = 0;
		string str = "";

		res = num / 1000;
		while (key < res)
		{
			str += 'M';
			++key;
		}
		key = 0;
		num = num % 1000;

		res = num / 100;
		if (res < 4)
		{
			while (key < res)
			{
				str += 'C';
				++key;
			}
		}
		else if (res == 4) str += "CD";
		else if (res == 5) str += 'D';
		else if (res == 9) str += "CM";
		else
		{
			str += 'D';
			res -= 5;
			while (key < res)
			{
				str += 'C';
				++key;
			}
		}
		key = 0;
		num = num % 100;

		res = num / 10;
		if (res < 4)
		{
			while (key < res)
			{
				str += 'X';
				++key;
			}
		}
		else if (res == 4) str += "XL";
		else if (res == 5) str += 'L';
		else if (res == 9) str += "XC";
		else
		{
			str += 'L';
			res -= 5;
			while (key < res)
			{
				str += 'X';
				++key;
			}
		}
		key = 0;
		num = num % 10;

		res = num;
		if (res < 4)
		{
			while (key < res)
			{
				str += 'I';
				++key;
			}
		}
		else if (res == 4) str += "IV";
		else if (res == 5) str += 'V';
		else if (res == 9) str += "IX";
		else
		{
			str += 'V';
			res -= 5;
			while (key < res)
			{
				str += 'I';
				key++;
			}
		}
		return str;
	}
};

