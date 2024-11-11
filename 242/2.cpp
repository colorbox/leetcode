class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { return false; }

        map<char, int> char_counter;
        for (char c: s) {
            char_counter[c]++;
        }

        for (char c: t) {
            char_counter[c]--;
        }

        for (const auto& pair : char_counter) {
            if (pair.second) { return false; }
        }

        return true;
    }
};
