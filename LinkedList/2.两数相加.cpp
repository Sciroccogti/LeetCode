/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
        struct ListNode *p1 = l1, *p2 = l2, *head = new ListNode(0), *p = head, *p0 = new ListNode(0);
            
        if(p1){
            p->val += p1->val;
            p1 = p1->next;
        }

        if(p2){
            p->val += p2->val;
            p2 = p2->next;
        }
                    
        p->next = new ListNode(0);

        if (p->val > 9)
        {
            p->next->val = 1;
            p->val -= 10;
        }
        
        while (p1 || p2)
        {         
            p = p->next;
            if(p1){
                p->val += p1->val;
                p1 = p1->next;
            }
            
            if(p2){
                p->val += p2->val;
                p2 = p2->next;
            }
            
            p->next = new ListNode(0);
                       
            if (p->val > 9)
            {
                p->next->val = 1;
                p->val -= 10;
            }
        }
        if(p->next->val == 0){
            delete p->next;
            p->next = NULL;
        }
        return head;
    }
};
// @lc code=end

