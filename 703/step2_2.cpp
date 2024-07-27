/*
サイズを制限したpriority_queueでも実装できるのでそれを実装。
*/
class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> q;
  int size;
public:
  KthLargest(int k, vector<int>& nums): size(k) {
    for (int num: nums) {
      q.push(num);
    }
  }

  int add(int val) {
    q.push(val);
    while (q.size() > size) {
      q.pop();
    }
    return q.top();
  }
};

