/*
Time : O(N log N)
Space : O(N)

https://github.com/kazukiii/leetcode/pull/16/files#diff-f400dc0fa41a78f5b2a9ec5c2d5364dd8cf0da8dc9e8c39d15f52f98ea05394b
を参考にした解法。
平衡木(mapのkey)を利用して文字の初出インデックスを管理。
二度目の出現でインデックスを削除することで、平衡木の先頭には一度しか出現していない文字のインデックスが残る。
3度以上の出現で削除した要素が復帰してしまうが、インデックスが大きいため結果に影響しない。
*/
class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> character_to_first_index;
    map<int, char> index_to_character;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (character_to_first_index.contains(c)) {
        int first_index = character_to_first_index[c];
        index_to_character.erase(first_index);
        continue;
      }
      character_to_first_index[c] = i;
      index_to_character[i] = c;
    }
    if (index_to_character.empty()) {
      const int kNotFound = -1;
      return kNotFound;
    }
    return index_to_character.begin()->first;
  }
};
