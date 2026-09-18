/*
string_viewを使用する方法もあったが、変数を増やすよりもcompareで直接比較したほうがシンプル
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<uint8_t> segmented_indexes(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && segmented_indexes[i - 1] == false) {
                continue;
            }
            for (const string& word: wordDict) {
                if (!s.compare(i, word.size(), word)) {
                    segmented_indexes[i + word.size() - 1] = true;
                }
            }
        }
        return segmented_indexes.back();
    }
};
