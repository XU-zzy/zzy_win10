/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

//最小根堆
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // 对前k个元素建成小根堆
        for (int i = 0; i < k; i++) {
            swim(nums, i);
        }
        // 剩下的元素与堆顶比较，若大于堆顶则去掉堆顶，再将其插入
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                swap(nums[0], nums[i]);
                sink(nums, 0, k - 1);
            }
        }
        // 结束后第k个大的数就是小根堆的堆顶
        return nums[0];
    }

   private:
    // 若v1比v2优先度高，返回true
    bool priorityThan(int v1, int v2) { return v1 < v2; }

    // 上浮 从下到上调整堆
    void swim(vector<int>& heap, int i) {
        while (i > 0 && priorityThan(heap[i], heap[(i - 1) / 2])) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // 下沉 从上到下调整堆
    void sink(vector<int>& heap, int i, int N) {
        while (2 * i + 1 <= N) {    //保证比较的数值是在堆内 i是父节点
            // j 现在是子女节点（左）
            int j = 2 * i + 1;
            //找出子女节点中偏小的一个
            if (j + 1 <= N && priorityThan(heap[j + 1], heap[j])) {
                ++j;
            }
            //如果父节点小于偏小的子女节点
            //则正确，退出
            if (priorityThan(heap[i], heap[j])) {
                break;
            }
            //否则交换父子节点的值，
            swap(heap[i], heap[j]);
            //父节点变为j
            i = j;
        }
    }
};



// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         return sort(nums.begin(), nums.end(), greater<int>()), nums[k - 1];
//     }
// };


//class Solution{
//     public:
//     int findKthLargest(vector<int>& nums, int k){
//         //先创建一个小根堆
//         for(int i = 0;i < k;++i){
//             swimToHigh(nums,i);
//         }

//         for(int i = k;i < nums.size();++i){
//             if(nums[i] < nums[0]){
//                 swap(nums[i],nums[0]);
//                 swinToLow(nums,0,k-1);
//             }
//         }
        
//         return nums[0];
//     }
//     private:
//     void swinToLow(vector<int>& nums,int father,int N){
//         while(father*2 + 1 <= N){
//             int left = father*2 + 1;
//             int right = left + 1;
//             if(nums[left] > nums[right]){   //保证左子女最小
//                 // swap(nums[left],nums[right]);
//                 ++left;
//             }
//             if(nums[father] < nums[left]){
//                 break;
//             }
//             swap(nums[father],nums[left]);
//             father = left;
            
//         }
//     }

//     void swimToHigh(vector<int>& nums,int i){
//         while(i > 0 && (nums[i] < nums[(i-1)/2])){
//             swap(nums[i],nums[(i-1)/2]);
//             i = (i-1)/2;
//         }
//     }
// };
// @lc code=end

