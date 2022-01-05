// wearing mask
// 自己没有想出来，看了解答恍然大悟orz

// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         vector<int> mask(words.size(), 0);
//         int ss = words.size();
//         for(int i = 0; i < ss; i++) {
//             for(auto c : words[i]) {
//                 mask[i] |= 1 << (c-'a');
//             }
//         }
//         size_t res = 0;
//         for(int i = 0; i < ss; i++) {
//             for(int j = i + 1; j < ss; j++) {
//                 if((mask[i] & mask[j]) == 0) {
//                     res = max(res, words[i].length() * words[j].length());
//                 }
//             }
//         }
//         return res;
//     }
// };