/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

    ListNode* reverse(ListNode* head,ListNode* tail){
        //如果不注释，当有两个元素时，tail == nullptr，将不会反转
        // if(head == nullptr || tail == nullptr)  return head;

        ListNode* cur = head; 
        ListNode* pre = nullptr;
        ListNode* nxt = head;
        while(cur != tail){
            //下一个继续向后
            nxt = nxt->next;
            //现有的先指向前一个
            cur->next = pre;
            //前一个变成现有的
            pre = cur;
            //现有的指向下一个
            cur = nxt;
        }
        
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;

        //记录原始head
        ListNode* old_head = head;

        //便利查看剩下的是否够一组,并查找下一组末尾的节点
        ListNode* test = head;
        for(int i = 0;i < k;i++){
            if(test == nullptr)   return head;
            test = test->next;
        }

        ListNode* ans = reverse(head,test);

        //开始下一组
        //将test，即本次反转之后的尾的下一个，作为下一组的起点
        //注意这里要把链表前后连接起来
        old_head->next = reverseKGroup(test,k);

        return ans;
    }
};
// @lc code=end

