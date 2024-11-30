class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> character_to_count;
    for (const char& c : s) {
      character_to_count[c]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (character_to_count[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
