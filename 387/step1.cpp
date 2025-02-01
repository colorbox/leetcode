/*
Solve Time: 4:20

Time: O(n)
Space: O(1)

一回の走査で解けないかを軽く模索したが思いつかなかったので愚直にmapで記録し、二回ループする手法で解いた。
一回の走査で解くことに固執しかけて時間を無駄に思想になっていたため、そこに気づけた点が個人的によかった
*/
class Solution {
 public:
  int firstUniqChar(string s) {
    map<char, int> character_to_count;
    for (const auto& c : s) {
      character_to_count[c]++;
    }
    for (int i = 0; i < s.size() ; i++) {
      if (character_to_count[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
