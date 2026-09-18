/*
Time: 20:30

Time Complexity: O(n * m *l) (n: sの長さ, m: wordDictの長さ, l: wordDictの単語平均長)
Space Complexity: O(1)

全探索的な解法はすぐに思いついたが、細かいミスで時間をロスした
C++の文字列操作関連でいい感じのメソッドを知っていればそれを使用したが、一旦手慣れたループで対応
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> matched_index(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && matched_index[i - 1] == false) {
                continue;
            }
            for (string word : wordDict) {
                if (word[0] != s[i]) {
                    continue;
                }
                for (int j = 0; j < word.size(); ++j) {
                    if (i + j >= s.size()) {
                        break;
                    }
                    if (s[i + j] != word[j]) {
                        break;
                    }
                    if (j == word.size() - 1) {
                        matched_index[i + j] = true;
                    }
                }
            }
        }
        return matched_index.back();
    }
};
