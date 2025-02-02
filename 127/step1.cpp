/*

Solve Time : over 1 hours

Time : O(N^2 * log N)
Space : O(N^2)

単語同士の距離から隣接リストを形成して探索すれば良い、というところまではすぐにたどり着いたが
微妙なミスを連発してしまい、時間がかかってしまった。

priority_queueのデフォルが最大を取り出す仕様を失念していた
最短距離を出す探索方法をしばらく失念しており、間違ったコードを書いていた

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
    vector<set<int>> adjcent_indexes = vector<set<int>>(wordList.size(), set<int>{});
    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = 0; j < wordList.size(); ++j) {
        string left = wordList[i];
        string right = wordList[j];
        if (!IsNextWord(left, right)) {
          continue;
        }
        adjcent_indexes[i].insert(j);
        adjcent_indexes[j].insert(i);
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
    return CountDistance(begin_index, end_index, adjcent_indexes);
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

  int CountDistance(int begin_index, int end_index, vector<set<int>>& adjcent_indexes) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next_indexes;
    next_indexes.emplace(1, begin_index);
    vector<int> distances(adjcent_indexes.size(), std::numeric_limits<int>::max());
    distances[begin_index] = 1;
    while (!next_indexes.empty()) {
      auto [distance, index] = next_indexes.top();
      next_indexes.pop();
      if (distances[index] < distance) {
        continue;
      }
      if (index == end_index) {
        return distance;
      }
      distances[index] = distance;
      for (auto next_index : adjcent_indexes[index]) {
        if (distances[next_index] < distance + 1) {
          continue;
        }
        next_indexes.emplace(distance + 1, next_index);
      }
    }
    if (distances[end_index] == std::numeric_limits<int>::max()) {
      return 0;
    }
    return distances[end_index];
  }
};
