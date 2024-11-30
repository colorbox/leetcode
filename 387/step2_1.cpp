/*
Time: O(n)
Space: O(1)

step1の改良、マジックナンバーを定数にした
*/
class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> character_to_count;
    for (const auto& c : s) {
      character_to_count[c]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (character_to_count[s[i]] == 1) {
        return i;
      }
    }

    int const kNotFound = -1;
    return kNotFound;
  }
};
