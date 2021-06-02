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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode* slow = head;
//         ListNode * fast = head;
//         while (fast->next != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         // slow 指针现在指向链表中点

//         // ListNode *fast = head;
//         // ListNode *slow = head;
//         // while(fast && fast->next){
//         //     slow = slow->next;
//         //     fast = fast->next->next;
//         // }
//         //当是奇数个时，slow还需要再向后一格
//         // if(fast) slow = slow->next;

//         //从slow之后的链表全部反转
//         ListNode* left = head;
//         ListNode* right = reverse(slow);

//         // ListNode* q = right;

//         while(right != nullptr){
//             if(right->val != left->val){
//                 return false;
//             }
//             right = right->next;
//             left = left->next;
//         }

//         // ListNode* p = head;
//         // while(p->next){
//         //     p = p->next;
//         // }
//         // p->next = reverse(q);

//         return true;
//     }


//     //正常
//     ListNode* reverse(ListNode* head){
//         if(head == nullptr) return head;
//         ListNode* cur = head;
//         ListNode* nxt = head;
//         ListNode* pre = nullptr;
//         while(cur != nullptr){
//             nxt = nxt->next;
//             cur->next = pre;
//             pre = cur;
//             cur = nxt;
//         }
        
//         return pre;
//     }

//     //递归
//     // ListNode* reverse(ListNode* head){
//     //     if(head == nullptr) return head;

//     //     ListNode* last = reverse(head->next);

//     //     head->next->next = last;
//     //     head->next = nullptr;

//     //     return last;
//     // }



// };
// 1.找到前半部分链表的尾节点。
// 2.反转后半部分链表。
// 3.判断是否回文。
// 4.恢复链表。
// 5.返回结果。
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }        

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

// @lc code=end

