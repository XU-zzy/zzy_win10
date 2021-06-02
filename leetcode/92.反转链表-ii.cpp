/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    //反转整个链表
    ListNode* reverse(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* last = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;

        return last;
    }
    //反转前n个链表
    ListNode* tmp = nullptr;

    ListNode* reverseN(ListNode *head,int n){
        if(n == 1){
            tmp = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next,n-1);
        head->next->next = head;
        //这里不指向空，而是需要头节点（反转后的前n个的"尾节点"）指向记录的第n+1个节点
        head->next = tmp;

        return last;

    }
    //反转left~right的链表
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //相当于反转前right个节点
        if(left == 1){
            return reverseN(head,right);
        }

        //前进到left的位置
        head->next = reverseBetween(head->next,left-1,right-1);

        return head;
    }
};
// @lc code=end

