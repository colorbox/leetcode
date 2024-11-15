/*
Solve Time: 25:00

Time Order: O(n)
Space Order: O(n)

方針は早くに定まっていたものの、C++の文字列操作が思うようにいかずに時間がかかってしまった。

*/
class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> unique_emails;
    for(const string& email : emails) {
      auto at_pos = email.find_first_of("@");
      string local_part = email.substr(0, at_pos);
      auto plus_pos = local_part.find_first_of("+");
      if (plus_pos == std::string::npos) {
        plus_pos = local_part.size();
      }
      string local_part_without_plus = local_part.substr(0, plus_pos);
      std::erase(local_part_without_plus, '.');
      email.replace(0, at_pos, local_part_without_plus);
      unique_emails.insert(email);
    }
    return unique_emails.size();
  }
};
