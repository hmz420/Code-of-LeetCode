/*
Method:
  暴力解法；

Note:
  if貌似比switch快一点；
*/

class Solution {
public:
	int romanToInt(string s) {
		int sum = 0;
		int l = s.length();
		if (l == 1) sum += trans(s[0]);
		else
		{
			for (int i = 0; i < l - 1; i++)
			{
				if (s[i] == 'I')
				{
					if (s[i + 1] == 'V' || s[i + 1] == 'X')
					{
						if (s[i + 1] == 'V') sum += 4;
						else sum += 9;
						i += 1;
					}
					else sum += 1;
				}
				else if (s[i] == 'X')
				{
					if (s[i + 1] == 'L')
					{
						sum += 40;
						i += 1;
					}
					else if (s[i + 1] == 'C')
					{
						sum += 90;
						i += 1;
					}
					else sum += 10;
				}
				else if (s[i] == 'C')
				{
					if (s[i + 1] == 'D')
					{
						sum += 400;
						i += 1;
					}
					else if (s[i + 1] == 'M')
					{
						sum += 900;
						i += 1;
					}
					else sum += 100;
				}
				else sum += trans(s[i]);
				if (i == l - 1);
				else if (i == l - 2) sum += trans(s[l - 1]);
			}
		}
		return sum;
	}

	int trans(char x)
	{
		int a = 0;
		if (x == 'I') a = 1;
		else if (x == 'V') a = 5;
		else if (x == 'X') a = 10;
		else if (x == 'L') a = 50;
		else if (x == 'C') a = 100;
		else if (x == 'D') a = 500;
		else a = 1000;
		return a;
	}
};

