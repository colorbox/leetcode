/*
Time Order : O(n)
Space Order : O(n)

step1の改良版
コメント使用ででローカルパートに`@`が含むものを対応するために`rfind`を利用。
メールアドレス正規化処理をメソッド抽出。
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
  string canonicalize_email(string email) {
    const auto at_pos = email.rfind("@");
    const string local_part = email.substr(0, at_pos);
    const auto plus_pos = local_part.find("+");
    string canonical_local_part = local_part.substr(0, plus_pos);
    std::erase(canonical_local_part, '.');
    email.replace(0, at_pos, canonical_local_part);
    return email;
  }
};
