/*
Method:
  解法：先判断什么时候进入到开始累计数据的时候，然后假定后面的都是我需要的，一直到遇到我不需要的东西为止；

Note:
  1）空格的ASCII代号为32；
  2）有的时候我们可以换个角度，如果去思考我们不需要什么过于复杂，那么就可以去思考我们需要什么，不需要的就自动排除了；
*/

class Solution {
public:
	int myAtoi(string str) {
		long long res = 0;
		int key = 1;
		int l = str.length();
		bool flag = false;

		for (int i = 0; i < l; i++)
		{
			if (!flag)
			{
				if (str[i] == '+') flag = true;
				else if (str[i] == '-')
				{
					flag = true;
					key = -1;
				}
				else if (str[i] >= '0' && str[i] <= '9')
				{
					flag = true;
					res = 10 * res + str[i] - 48;
				}
				else if (str[i] == 32);
				else break;
			}
			else
			{
				if (!(str[i] >= '0' && str[i] <= '9')) break;
				else res = 10 * res + str[i] - 48;

				if (key * res <= INT_MIN)
				{
					res = -1 * INT_MIN;
					break;
				}
				else if (key * res >= INT_MAX)
				{
					res = INT_MAX;
					break;
				}
			}
		}

		return key * res;
	}
};

