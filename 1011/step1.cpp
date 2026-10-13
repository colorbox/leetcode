/*
Time: 17:16

Space Complexity: O(1)
Time Complexity: O(nlogm)
n: weights.size(), m: sum(weights)

*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // capacityが定まっていれば、それを元に何日かけて運び出せるか計算可能
        // capacityを最大と最小で二分探索
        int left = 0;
        int right = 0;
        for (auto weight: weights) {
            left = max(left, weight);
            right += weight;
        }
        while (left < right) {
            int capacity = left + (right - left) / 2;
            if (shippable(weights, days, capacity)) {
                right = capacity;
            } else {
                left = capacity + 1;
            }
        }
        return left;
    }

private:
    bool shippable(const vector<int>& weights, int days, int capacity) {
        int count = 1;
        int weight_sum = 0;
        for (auto weight : weights) {
            if (weight_sum + weight > capacity) {
                count++;
                weight_sum = 0;
            }
            weight_sum += weight;
        }
        if (count <= days) {
            return true;
        } else {
            return false;
        }
    }
};
