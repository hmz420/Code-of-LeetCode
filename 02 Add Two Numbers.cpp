/*
Method:
  1）暴力解法：直接把链表变成数字，然后数字变成链表；
  2）链表做法：按照两个链表的长度分成了三种情况:
     L1>l2时，那么不断地将元素之和处理之后放到l1的值中;
	 l1<l2时，那么在l1的下一位是空时，将l2补到l1的后面；
	 当l1=l2或者l2就比l1长一位时，需要考虑末尾进位的情况。

Note:
  1）% 和 / 的应用可以实现进位的思想；
  2）a？b:c 的意思是：a成立的时候取b，否则取c；
  3）new ListNode(0)即可创建链表的下一个next；
  4）两个东西相加，在长度不等的情况下，可以考虑将短的部分用0填充；
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int key = 0;
		ListNode* L = l1;

		while (l1)
		{
			key = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + key;
			l1->val = key % 10;
			key /= 10;
			if (!(l1->next) && l2 && l2->next)
			{
				l1->next = l2->next;
				l2 = NULL;
			}
			else if (!(l1->next) && !(l2 && l2->next) && key)
			{
				l1->next = new ListNode(0);
				l2 = NULL;
			}
			l1 = l1->next;
			if (l2) l2 = l2->next;
		}

		return L;
	}
};

