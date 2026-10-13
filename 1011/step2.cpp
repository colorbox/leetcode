class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_capacity = 0;
        int max_capacity = 0;
        for (int weight : weights) {
            max_capacity += weight;
        }
        while (min_capacity < max_capacity) {
            int mid_capacity = min_capacity + (max_capacity - min_capacity) / 2;
            if (shippable(weights, days, mid_capacity)) {
                max_capacity = mid_capacity;
            } else {
                min_capacity = mid_capacity + 1;
            }
        }
        return min_capacity;
    }

private:
    bool shippable(const vector<int>& weights, int days, int capacity) {
        int weight_sum = 0;
        int need_days = 1;
        for (int weight : weights) {
            if (weight > capacity) {
                return false;
            }
            if (weight_sum + weight > capacity) {
                ++need_days;
                weight_sum = 0;
            }
            weight_sum += weight;
        }
        if (need_days > days) {
            return false;
        } else {
            return true;
        }
    }
};
