/*

Time : O(N * L * log N)
Space : O(N^2)

他の人の解法を参考に改良したもの
隣接リストの形成を改善、単語のリストを二重ループで探索するのではなく、各単語を１文字ずつa - zに変化させて、wordList内に一致する単語の有無を確認。

*/
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    bool no_end = std::none_of(wordList.begin(), wordList.end(), [endWord](string s) {
      return s == endWord;
    });
    if (no_end) {
      return 0;
    }
    bool no_begin = std::none_of(wordList.begin(), wordList.end(), [beginWord](string s) {
      return s == beginWord;
    });
    if (no_begin) {
      wordList.push_back(beginWord);
    }
    vector<set<int>> adjacent_indexes = vector<set<int>>(wordList.size(), set<int>{});
    ComposeAdjacentIndexes(adjacent_indexes, wordList);
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
  void ComposeAdjacentIndexes(vector<set<int>>& adjacent_indexes, const vector<string>& wordList) {
    map<string, int> word_to_index;
    for (int i = 0; i < wordList.size(); ++i) {
      word_to_index[wordList[i]] = i;
    }
    for (int i = 0; i < wordList.size(); ++i) {
      for (int char_index = 0; char_index < wordList[i].size(); ++char_index) {
        string adjacent_word = wordList[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          adjacent_word[char_index] = c;
          if (adjacent_word == wordList[i]) {
            continue;
          }
          if (!word_to_index.contains(adjacent_word)) {
            continue;
          }
          const int left = i;
          const int right = word_to_index[adjacent_word];
          adjacent_indexes[left].insert(right);
          adjacent_indexes[right].insert(left);
        }
      }
    }
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
