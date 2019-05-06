/*
Method:
  1)传统做法：先计算链表的长度，然后计算出要删除的元素的位置，然后进行删除；
  2)快慢指针：让快的指针相比于慢的指针快n位，那么当快的指针到达末尾的时候，慢的指针正好是需要删除的位置；

Note:
  1)创建新的节点的方法；
  2)链表的使用方法；
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/***传统做法***/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Node = (ListNode*) head;
        ListNode* CheckNode = (ListNode*) head;
        int len = 0;
        int key = 0;
        
        while(Node) {
            ++len;
            Node = Node -> next;
        }
        
        if(len == 1 || len - n == 0) {
            head = head -> next;
            return head;
        }
        
        while(key < len - n - 1) {
            CheckNode = CheckNode -> next;
            ++key;
        }
        
        CheckNode -> next = CheckNode -> next -> next;
        return head;
    }
};


/***快慢指针***/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *FastNode = head, *SlowNode = head;
        if(FastNode == NULL)
            return head -> next;
        
        while(n--) {
            FastNode = FastNode -> next;
        }
        
        if(FastNode == NULL)
            return head -> next;
        
        while(FastNode -> next) {
            SlowNode = SlowNode -> next;
            FastNode = FastNode -> next;
        }
        
        SlowNode -> next = SlowNode -> next -> next;
        return head;
    }
};


