/*
文字列構築にstd::ostringstreamを使う
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sorted_to_str;
        for (auto& str: strs) {
          vector<int> counter(26);
          for (char c : str) {
            counter[c - 'a']++;
          }
          std::ostringstream key;
          for (auto& count : counter) {
            key << "#" << to_string(count);
          }

          sorted_to_str[key.str()].push_back(str);
        }
        vector<vector<string>>grouped_anagrams;
        for (auto& [key, group]: sorted_to_str) {
          grouped_anagrams.push_back(move(group));
        }
        return grouped_anagrams;
    }
};
