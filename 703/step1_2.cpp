/*
step1はaddメソッドのinsertによって時間計算量が最適ではなかったのでHeapを使うように再実装。
メソッドを分けずにベタ書き。
*/
class KthLargest {
private:
  std::vector<int> heap;
  int size;
public:
  KthLargest(int k, vector<int>& nums): heap(nums), size(k) {
    // ソートしておけばmin heapとして問題ない状態になるはず
    sort(heap.begin(), heap.end());
    // heapの切り詰め、sizeで切り詰める
    while (heap.size() > k) {
      heap.erase(heap.begin());
    }
  }

  int add(int val) {
    if (heap.empty()) {
      heap.push_back(val);
      return val;
    }
    // 末尾に加える
    heap.push_back(val);
    // heapfy
    // 末尾のインデックスとその親を見て、交換、その繰り返し
    int child_index = heap.size() - 1;
    int parent_index = (child_index - 1) / 2;
    while (heap[child_index] < heap[parent_index]) {
      swap(heap[child_index], heap[parent_index]);
      child_index = parent_index;
      parent_index = (child_index - 1) / 2;
    }
    // サイズ超過してなかったら最小要素を返して終わり
    if (heap.size() <= size) {
      return heap.front();
    }
    // サイズ超過してたら最小要素を削除して再構成
    swap(heap.front(), heap.back());
    heap.pop_back();
    // root要素を適切な位置に配置する
    parent_index = 0;
    int left_child_index = parent_index * 2 + 1;
    int right_child_index = parent_index * 2 + 2;
    while (left_child_index < heap.size() && heap[parent_index] > heap[left_child_index] || right_child_index < heap.size() && heap[parent_index] > heap[right_child_index]) {
      int swap_target_index = left_child_index;
      if (right_child_index < heap.size() && heap[swap_target_index] > heap[right_child_index]) {
        swap_target_index = right_child_index;
      }
      swap(heap[parent_index], heap[swap_target_index]);
      parent_index = swap_target_index;
      left_child_index = parent_index * 2 + 1;
      right_child_index = parent_index * 2 + 2;
    }
    return heap.front();
  }
};

