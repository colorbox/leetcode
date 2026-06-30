/*

Space: O(n)
Time: O(n log n)

step1の改良
もとの配列を同じ大きさを保持する必要はなく、配列長そのもので最大数を保持する。
特定のインデックスの数値を小さくできると、後続でそこを経由して最大長を更新できる場合があるため更新する。

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> num_to_count;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(num_to_count.begin(), num_to_count.end(), nums[i]);
            if (it == num_to_count.end()) {
                num_to_count.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return num_to_count.size();

    }
};
