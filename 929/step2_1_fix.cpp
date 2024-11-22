/*

*/
class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    for (auto& email : emails) {
      canonicalize_email(email);
    }
    set<string> unique_emails(emails.begin(), emails.end());
    return unique_emails.size();
  }

 private:
  void canonicalize_email(string& email) {
    auto at_pos = email.rfind('@');
    string local_part = email.substr(0, at_pos);
    auto plus_pos = local_part.find('+');
    string canonicalized_local_part = local_part.substr(0, plus_pos);
    std::erase(canonicalized_local_part, '.');
    string domain_part = email.substr(at_pos, email.size() - at_pos);
    email = canonicalized_local_part + domain_part;
  }
};
