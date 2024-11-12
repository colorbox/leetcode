class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>>queue;
  int capacity;
public:
    KthLargest(int k, vector<int>& nums): capacity(k) {
        for (int num: nums) {
          queue.push(num);
        }
    }
    
    int add(int val) {
      queue.push(val);
      while (queue.size() > capacity) {
        queue.pop();
      }
      return queue.top();
    }
};
