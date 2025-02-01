/*
Time : O(N log N)
Space : O(N)

https://github.com/kazukiii/leetcode/pull/16/files#diff-f5b3276a9df261ed1c1e70d5b6de00ca4544e1a1ae1de6a466add8df5cd3d1b0
を参考にした解法。
ソートで文字種ごとに隣接させ、二度以上出現したものを除外し、min比較で最小インデックスを求める。
*/
class Solution {
public:
  int firstUniqChar(string s) {
    vector<CharacterIndex> character_indices;
    for (int i = 0; i < s.size(); i++) {
      character_indices.push_back({s[i], i});
    }
    sort(character_indices.begin(), character_indices.end());
    int count = 1;
    int first_unique_character_index = numeric_limits<int>::max();
    for (int i = 0; i < s.size(); i++) {
      if (i < s.size() - 1 && character_indices[i].character == character_indices[i + 1].character) {
        count++;
        continue;
      }
      if (count == 1) {
        first_unique_character_index = min(first_unique_character_index, character_indices[i].index);
      }
      count = 1;
    }
    if (first_unique_character_index == numeric_limits<int>::max()) {
      return -1;
    }
    return first_unique_character_index;
  }

  struct CharacterIndex {
    char character;
    int index;

    bool operator<(const CharacterIndex& other) {
      return character < other.character;
    }
  };
};
