/*
Time Order : O(n)
Space Order : O(n)

ステートマシン的な開放
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
    string canonicalized_email = "";
    auto at_pos = email.rfind('@');
    string local_part = email.substr(0, at_pos);
    for (auto c : local_part) {
      if (c == '.') {
        continue;
      }
      if (c == '+') {
        break;
      }
      canonicalized_email += c;
    }
    return email.replace(0, at_pos, canonicalized_email);
  }
};
