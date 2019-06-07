/*
Method:
  算法思路：创建一个节点，在l1和l2都为真的情况下，把val小的节点补充到这个节点的后面；
  补充完了之后，谁有剩下的节点，谁就直接补充在后面；

Note:
  1)p -> next是指向下一个节点的地址，p本身就代表这一个节点的地址；
  2)数组中能够用到的高级语句也可以尝试用到链表中来；
  3)返回一个链表，是返回了这个链表的首地址；
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *mid = new ListNode(0), *res = mid;
        
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                res -> next = l1;
                l1 = l1 -> next;
            }
            else {
                res -> next = l2;
                l2 = l2 -> next;
            }
            res = res -> next;
        }
        res -> next = l1? l1 : l2;
        return mid -> next;
    }
};


