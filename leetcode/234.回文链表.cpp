/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//模拟双指针类似前序和后序遍历一起，然后比较
// class Solution {
// public:
//     ListNode* left;
//     bool isPalindrome(ListNode* head) {
//         left = head;
//         return traverse(head);
//     }

//     bool traverse(ListNode* right){
//         if(right == nullptr)    return true;

//         bool res = traverse(right->next);

//         res = res && (right->val == left->val);
//         left = left->next;

//         return res;
//     }
// };


//优化空间复杂度
//快慢指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode * fast = head;
        while (fast->next != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow 指针现在指向链表中点

        // ListNode *fast = head;
        // ListNode *slow = head;
        // while(fast && fast->next){
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        //当是奇数个时，slow还需要再向后一格
        // if(fast) slow = slow->next;

        //从slow之后的链表全部反转
        ListNode* left = head;
        ListNode* right = reverse(slow);

        // ListNode* q = right;

        while(right != nullptr){
            if(right->val != left->val){
                return false;
            }
            right = right->next;
            left = left->next;
        }

        // ListNode* p = head;
        // while(p->next){
        //     p = p->next;
        // }
        // p->next = reverse(q);

        return true;
    }


    //正常
    ListNode* reverse(ListNode* head){
        if(head == nullptr) return head;
        ListNode* cur = head;
        ListNode* nxt = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            nxt = nxt->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        
        return pre;
    }

    //递归
    // ListNode* reverse(ListNode* head){
    //     if(head == nullptr) return head;

    //     ListNode* last = reverse(head->next);

    //     head->next->next = last;
    //     head->next = nullptr;

    //     return last;
    // }



};
// @lc code=end

