/*
https://github.com/colorbox/leetcode/pull/29#discussion_r1861430039
を見てそれを参考に自分で書いた解法、比較用
*/
class Solution {
 public:
  int firstUniqChar(string s) {
    queue<CharacterAndCount> queue;
    map<char, int> character_to_count;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      character_to_count[c]++;
      queue.push({c, i});
      while (true) {
        char front_character = queue.front().character;
        if (character_to_count[front_character] > 1) {
          queue.pop();
        } else {
          break;
        }
      }
    }
    if (queue.empty()) {
      return -1;
    }
    return queue.front().index;
  }

 private:
  struct CharacterAndCount {
    char character;
    int index;
  };
};
