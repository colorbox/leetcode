class Solution {
public:
    bool isPalindrome(string s) {
        string checker = s;
        checker.erase(
            remove_if(checker.begin(), checker.end(), [](unsigned char c) { return !isalnum(c); } ),
            checker.end()
        );

        for (int i=0; i < checker.size(); i++) {
            checker[i] = tolower(checker[i]);
        }

        string checkerReverse = checker;

        reverse(checkerReverse.begin(), checkerReverse.end());

        return (checker == checkerReverse);
    }
};
