// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums.at(nums.size()-k);
//     }
// };

// quicksort
// 68ms - 16.70%
// 9.7MB - 88.08%
// class Solution {
// public:

//     int quicksort(vector<int>& nums, int left, int right, int k) {
//         int pivot = nums[left];
//         int lp = left;
//         int rp = right;
//         while(lp < rp) {
//             while(lp < rp && nums.at(rp) >= pivot) rp--;
//             if(lp < rp) nums[lp++] = nums[rp];
//             while(lp < rp && nums.at(lp) <= pivot) lp++;
//             if(lp < rp) nums[rp--] = nums[lp];
//         }
//         nums[lp] = pivot;
//         // for(int i = left; i <= right; i++) 
//         //     printf("%d ", nums[i]);
//         // printf("\n");
//         // printf("k: %d\n", k);
//         if(lp-left+1 == k) return nums[lp];
//         if(lp-left+1 < k) return quicksort(nums, lp+1, right, k-lp+left-1);
//         if(lp-left+1 > k) return quicksort(nums, left, lp, k);
//         return 0;
//     }

//     // 快速排序方法
//     int findKthLargest(vector<int>& nums, int k) {
//         return quicksort(nums, 0, nums.size()-1, nums.size()+1-k);
//     }
// };


// 12ms - 40.21%
// 9.7MB - 68.98%
// class Solution {
// public:
//     // 从下到上调整堆
//     void build(vector<int>& nums, int k) {
//         for(int i = (k-1)/2; i >= 0; --i) {
//             int parent = i;
//             int child = (parent<<1)+1;
//             for(;; parent=child) {
//                 child = (parent<<1) + 1;
//                 if(child >=k) break;
//                 if(child+1< k && nums[child+1]<nums[child]) child++;
//                 if(nums[child] < nums[parent]) swap(nums[parent], nums[child]);
//             }
//         }
//         for(int i = 0; i < k; i++)
//             printf("%d ", nums[i]);
//         printf("\n");
//     }

//     void insert(vector<int>& nums, int k) {
//         int ss = nums.size();
//         for(int i = k; i < ss; i++) {
//             if(nums[i] < nums[0]) continue;
//             nums[0] = nums[i];
//             int ele = nums[0];
//             int child, parent;
//             for(parent = 0; parent * 2 + 1 <= k-1; parent = child) {
//                 child = (parent<<1)+1;
//                 if(child+1 <= k-1 && nums[child+1]<nums[child]) child++;
//                 if(ele <= nums[child]) break;
//                 nums[parent] = nums[child];
//             }
//             nums[parent] = ele;
//         }
//     }

//     // 快速排序方法
//     int findKthLargest(vector<int>& nums, int k) {
//         build(nums, k);
//         insert(nums, k);
//         return nums.at(0);
//     }
// };