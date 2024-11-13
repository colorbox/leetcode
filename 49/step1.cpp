/*
Time: 7:07

Time: O(N * M log M)
Space: O(N * M)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sorted_to_str;
        for (auto str: strs) {
          string key = str;
          sort(key.begin(), key.end());
          sorted_to_str[key].push_back(str);
        }
        vector<vector<string>>grouped_anagrams;
        for (auto [key, group]: sorted_to_str) {
          grouped_anagrams.push_back(group);
        }
        return grouped_anagrams;
    }
};
