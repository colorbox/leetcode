// 第2段階のコード、3回連続でパスしたもの
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) abort();

        string checker;
        for (char c: s) {
            if (isalnum(c)) {
                checker += tolower(c);
            }
        }

        string reversedChecker = checker;
        reverse(reversedChecker.begin(), reversedChecker.end());

        return reversedChecker == checker;
    }
};
