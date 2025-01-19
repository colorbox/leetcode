/*
quick selectを利用する手法。
*/
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> frequent_counter;
    for (int num : nums) {
      if (!frequent_counter.contains(num)) {
        frequent_counter[num] = 0;
      }
      frequent_counter[num]++;
    }

    vector<int> counts;
    for (auto pair : frequent_counter) {
      counts.push_back(pair.second);
    }

    int kth_frequency_count = quick_select(counts, 0, counts.size() - 1, k);
    vector<int> top_k_frequency_nums;
    for (auto pair : frequent_counter) {
      if (pair.second < kth_frequency_count) {
        continue;
      }
      top_k_frequency_nums.push_back(pair.first);
    }

    return top_k_frequency_nums;
  }

private:
  int partition(vector<int>& arr, int left, int right) {
    int pivot = right;
    int store_index = left;
    for (int i = left; i < right; i++) {
      if (arr[i] > arr[pivot]) {
        swap(arr[i], arr[store_index]);
        store_index++;
      }
    }
    swap(arr[store_index], arr[pivot]);
    return store_index;
  }

  int quick_select(vector<int>& arr, int left, int right, int k) {
    int pivot = partition(arr, left, right);
    if (pivot == k - 1) {
      return arr[pivot];
    }
    if (pivot < k - 1) {
      return quick_select(arr, pivot + 1, right, k);
    }
    return quick_select(arr, left, pivot - 1, k);
  }
};
