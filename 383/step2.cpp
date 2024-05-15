/*
解説や他の人のコードを読んで改良。
おおまかな方針は変えていないが、mapをintの配列にして、charをintとして扱う手法で高速化
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int char_count[26];
        for (char c: magazine) {
            char_count[c - 97]++;
        }

        for (char c: ransomNote) {
            if (char_count[c - 97] == 0) {
                return false;
            }
            char_count[c - 97]--;
        }

        return true;
    }
};
