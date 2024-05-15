/*
97という定数が気持ち悪かったので、'a'に変更、それ以外はstep2と変わらず。
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int char_count[26];

        for (char c: magazine) {
            char_count[c - 'a']++;
        }

        for(char c: ransomNote) {
            if (char_count[c - 'a'] == 0) {
                return false;
            }

            char_count[c - 'a']--;
        }

        return true;
    }
};
