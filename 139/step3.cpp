class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<uint8_t> segmented_indexes(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && !segmented_indexes[i - 1]) {
                continue;
            }
            for (const string& word : wordDict) {
                if (s.compare(i, word.size(), word) == 0) {
                    segmented_indexes[i + word.size() - 1] = true;
                }
            }
        }
        return segmented_indexes.back();
    }
};
