[toc]


## 链表
206.反转链表
92.反转链表-ii

反转整个链表->反转前N个链表->反转n~m个链表

递归法
### 反转整个链表
```c
//反转整个链表
ListNode *reverse(Listnode* head){
    if(head->next == null || head == nullptr)    return head;    //不要忘了递归中的base case
    
    //理解的时候这里不要进入递归，而是将后面的看作时一个整体
    ListNode* last = reverse(head->next);
    
    head->next->next = head;
    head->next = nullptr;

    return last;
}
```
### 反转前n个链表
```c
//反转前n个链表
ListNode *t;
ListNode *reverseN(Lisnode* head,int n){
    
    if(n == 1){
        //存储指向第n+1个节点,用于最后连接链表
        t = head->next;
        return head;
    }

    ListNode* last = reverseN(head->next,n-1);

    head->next->next = head;
    
    //这里是与反转所有链表的区别
    head->next = t;

    return last;
}
```
### 反转n~m的链表
```c
//反转n~m的链表
ListNode *reverseBetween(ListNode* head,int left,int right){
    //相当于反转前right个节点
    if(left == 1){
        return reverseN(head,right);
    }

    //前进到left的位置
    head->next = reverseBetween(head->next,left-1,right-1);

    return head;
}
```
### k个一组反转链表
```c
//k个一组反转链表

ListNode* reverseHT(ListNode*head,ListNode tail){
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

ListNode* reverseKGroup(ListNode* head, int k){
    if(head == nullptr || head->next == nullptr) return head;

    //判断剩下的链表节点个数够不够一组
    ListNode* right = head;
    ListNode* left = head;
    for(int i = 0;i < k;i++){
        if(right = nullptr){
            return head;
        }
        right = right->next;
    }

    //反转这一组链表
    ListNode* ans = reverseHT(left,right);

    //开始下一组
    //从right开始,即本次反转的链表的尾的下一个，是下一组的起点
    //注意这里需要将反转后的链表和原链表连接起来
    //此时的head其实是反转后的尾元素，将他和剩下的部分连接
    head->next = reverseKGroup(right,k);
    
    return ans;
}

```

### 判断回文链表
left前序遍历，right后序遍历

```c
//递归判断
ListNode* left;
bool isPalindrome(ListNode* head){
    left = head;
    return traverse(head);
}
bool traverse(ListNode* right){
    if(right == nullptr){
        return true;
    }

    bool res = traverse(right->next);

    res = res && (left->val == right->val));
    left = left->next;
    
    return res;
}
```

//优化空间复杂度
//快慢指针
```c
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
```