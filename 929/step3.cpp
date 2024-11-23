class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> canonicalized_emails;
    for (string email : emails) {
      canonicalized_emails.insert(canonicalize_email(email));
    }
    return canonicalized_emails.size();
  }

 private:
  string canonicalize_email(string email) {
    size_t at_pos = email.rfind('@');
    string local_part = email.substr(0, at_pos);
    size_t plus_pos = local_part.find('+');
    local_part = local_part.substr(0, plus_pos);
    erase(local_part, '.');
    email.replace(0, at_pos, local_part);
    return email;
  }
};
