/*
Method:
  解法：由于不知道给定的数有几位，那么用传统的循环嵌套出现困难，在这种情况下用递归的思想可以解决这一问题；
  按照常规的枚举法，能够清晰地认识到结果是以一种树杈的方式进行元素的积累，那么将这一本质与递归进行结合；

Note:
  函数递归的思想：通过一次次的函数递归出现函数的子函数，即树杈主干的扩散过程；递归中的子函数终止条件很关键，
  终止条件使得一个个子函数向回收拢，收拢的过程使得主干产生各个数据分支；这样便对应了上文中的树杈型结构；
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> hash{
			{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
			{'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
		};
		vector<string> res;
		if (digits.empty())
			return res;
		func(res, "", digits, hash, 0);
		return res;
	}

	void func(vector<string>& res, string str, string& digits, unordered_map<char, string>& map, int k) {
		if (str.length() == digits.length()) {
			res.push_back(str);
			return;
		}
		string test = map[digits[k]];
		for (char x : test) {
			str += x;
			func(res, str, digits, map, k + 1);
			str.pop_back();
		}
		return;
	}
};