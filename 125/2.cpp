// 第2段階のコード、第1段階のコードを読みやすくした
class Solution {
public:
    bool isPalindrome(string s) {
        string checker;

        for (char c: s) {
            if (isalnum(c)) {
                checker += tolower(c);
            }
        }

        string checkerReverse = checker;

        reverse(checkerReverse.begin(), checkerReverse.end());

        return (checker == checkerReverse);
    }
};
