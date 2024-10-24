/*
sortを利用せずに時間計算量を改善
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> sorted_to_str;
        for (auto& str: strs) {
          vector<int> keys(26);
          for (char c : str) {
            keys[c - 'a']++;
          }
          sorted_to_str[keys].push_back(str);
        }
        vector<vector<string>>grouped_anagrams;
        for (auto& [key, group]: sorted_to_str) {
          grouped_anagrams.push_back(move(group));
        }
        return grouped_anagrams;
    }
};
