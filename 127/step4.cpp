class Solution {
 public:
  int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
    bool no_end = true;
    for (auto word : word_list) {
      if (word == end_word) {
        no_end = false;
        break;
      }
    }
    if (no_end) {
      return 0;
    }
    bool no_begin = true;
    for (auto word : word_list) {
      if (word == begin_word){
        no_begin = false;
        break;
      }
    }
    if (no_begin) {
      word_list.emplace_back(begin_word);
    }
    vector<vector<int>> adjacent_indexes = vector<vector<int>>(word_list.size(), vector<int>{});
    ComposeAdjacentIndex(adjacent_indexes, word_list);
    int begin_index;
    int end_index;
    for (int i = 0; i < word_list.size(); ++i) {
      if (word_list[i] == begin_word) {
        begin_index = i;
      }
      if (word_list[i] == end_word) {
        end_index = i;
      }
    }
    return CountWordLadder(begin_index, end_index, adjacent_indexes);
  }

 private:
  void ComposeAdjacentIndex(vector<vector<int>>& adjacent_indexes, const vector<string>& word_list) {
    for (int i = 0; i < word_list.size(); ++i) {
      for (int j = i + 1; j < word_list.size(); ++j) {
        if (!IsNextWord(word_list[i], word_list[j])) {
          continue;
        }
        adjacent_indexes[i].emplace_back(j);
        adjacent_indexes[j].emplace_back(i);
      }
    }
  }

  bool IsNextWord(const string& left, const string& right) {
    int diff_count = 0;
    for (int i = 0; i < left.size(); ++i) {
      if (left[i] != right[i]) {
        ++diff_count;
      }
    }
    return diff_count == 1;
  }

  int CountWordLadder(const int begin_index, 
                      const int end_index, 
                      vector<vector<int>>& adjacent_indexes) {
    queue<pair<int, int>> indexes_and_distances;
    indexes_and_distances.emplace(begin_index, 1);
    vector<int> distances = vector<int>(adjacent_indexes.size(), numeric_limits<int>::max());
    while(!indexes_and_distances.empty()) {
      auto [index, distance] = indexes_and_distances.front();
      indexes_and_distances.pop();
      if (distances[index] <= distance) {
        continue;
      }
      distances[index] = distance;
      for (int next_index : adjacent_indexes[index]) {
        if (next_index == end_index) {
          return distance + 1;
        }
        indexes_and_distances.emplace(next_index, distance + 1);
      }
    }
    return 0;
  }
};
