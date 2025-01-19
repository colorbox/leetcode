class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> sorted_to_strings;
    for (auto& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      sorted_to_strings[key].push_back(str);
    }
    vector<vector<string>> grouped_anagrams;
    for (auto& [key, strings] : sorted_to_strings) {
      grouped_anagrams.push_back(move(strings));
    }
    return grouped_anagrams;
  }
};
