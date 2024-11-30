/*
step2_2_suggested.cpp
を
https://github.com/colorbox/leetcode/pull/29#discussion_r1861430039
の書き方に沿って修正したコード、参照用
*/
class Solution {
 public:
  int firstUniqChar(string s) {
    queue<CharacterAndCount> characters;
    map<char, int> character_to_count;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      ++character_to_count[c];
      characters.push({c, i});
      while (character_to_count[characters.front().character] >= 2) {
        characters.pop();
      }
    }
    if (characters.empty()) {
      return -1;
    }
    return characters.front().index;
  }

 private:
  struct CharacterAndCount {
    char character;
    int index;
  };
};
