/*

Time : O(L * N^2)
Space : O(N^2)

- 全てのノード間の距離が同じなのでpriority_queueは不要で、queueで十分
- 隣接リストを作る際に、i < jの条件を追加して計算量を減らす
- BFSにて、queueが空になったときは到達不能と判断して良いのでif分を削除
*/
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    bool no_begin = std::none_of(wordList.begin(), wordList.end(), [beginWord](string s) {
      return s == beginWord;
    });
    if (no_begin) {
      wordList.push_back(beginWord);
    }
    bool no_end = std::none_of(wordList.begin(), wordList.end(), [endWord](string s) {
      return s == endWord;
    });
    if (no_end) {
      return 0;
    }
    vector<set<int>> adjacent_indexes = vector<set<int>>(wordList.size(), set<int>{});
    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = i + 1; j < wordList.size(); ++j) {
        string left = wordList[i];
        string right = wordList[j];
        if (!IsNextWord(left, right)) {
          continue;
        }
        adjacent_indexes[i].insert(j);
        adjacent_indexes[j].insert(i);
      }
    }
    int begin_index;
    int end_index;
    for (int i = 0; i < wordList.size(); ++i) {
      if (wordList[i] == beginWord) {
        begin_index = i;
      }
      if (wordList[i] == endWord) {
        end_index = i;
      }
    }
    return CountDistance(begin_index, end_index, adjacent_indexes);
  }

 private:
  bool IsNextWord(const string left, const string right) {
    int count = 0;
    for (int i = 0; i < left.size(); ++i) {
      if (left[i] != right[i]) {
        ++count;
      }
      if (count > 1) {
        return false;
      }
    }
    if (count == 0) {
      return false;
    }
    return true;
  }

  int CountDistance(int begin_index, int end_index, vector<set<int>>& adjacent_indexes) {
    queue<pair<int, int>> next_indexes;
    next_indexes.emplace(1, begin_index);
    vector<int> distances(adjacent_indexes.size(), std::numeric_limits<int>::max());
    distances[begin_index] = 1;
    while (!next_indexes.empty()) {
      auto [distance, index] = next_indexes.front();
      next_indexes.pop();
      if (distances[index] < distance) {
        continue;
      }
      if (index == end_index) {
        return distance;
      }
      distances[index] = distance;
      for (auto next_index : adjacent_indexes[index]) {
        if (distances[next_index] < distance + 1) {
          continue;
        }
        next_indexes.emplace(distance + 1, next_index);
      }
    }
    return 0;
  }
};
