class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for (int weight : weights) {
            right += weight;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (shippable(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool shippable(const vector<int>& weights, int days, int capacity) {
        int load_days = 1;
        int weight_sum = 0;
        for (int weight : weights) {
            if (weight > capacity) {
                return false;
            }
            if (weight_sum + weight > capacity) {
                weight_sum = 0;
                ++load_days;
            }
            weight_sum += weight;
        }
        return load_days <= days;
    }
};
