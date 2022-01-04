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