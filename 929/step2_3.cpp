/*
Time Order : O(n)
Space Order : O(n)

正規表現を使用したパターン
local-partから`.`と`+`以降を削除する正規表現を使用している。
*/
class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> unique_emails;
    for (auto email : emails) {
      unique_emails.insert(canonicalize_email(email));
    }
    return unique_emails.size();
  }

 private:
  string canonicalize_email(string& email) {
    auto at_pos = email.rfind('@');
    string local_part = email.substr(0, at_pos);
    std::regex dot_and_plus_suffix("\\.|\\+.*");
    local_part = std::regex_replace(local_part, dot_and_plus_suffix, "");
    
    email.replace(0, at_pos, local_part);
    return email;
  }
};
