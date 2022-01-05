// 44ms - 58.77%
// 18.4MB - 5.85%

// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//         // 一看这种题目类型的，就知道是动态规划...
//         // 但是题解没有，估计并不能用动态规划做
//         set<long long int> s;
//         int ss = nums.size();
//         for(int i = 0; i < ss; i++) {
//             set<long long int>::iterator it = s.lower_bound((long long int)nums[i] - (long long int)t);
//             if(it != s.end() && *it <= (long long int)nums[i] + t) return true;
//             s.insert(nums[i]);
//             if(i >= k) s.erase(nums[i-k]);
//         }
//         return false;
//     }
// };