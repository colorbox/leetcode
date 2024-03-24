// 第1段階のコード
class Solution {
public:

    template<class ForwardIt, class UnaryPredicate>
    ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p) {
        ForwardIt filteredLast = first;
        while (first != last) {
            if (!p(*first)) {
                *filteredLast = *first;
                filteredLast++;
            }
            first++;
        }

        return filteredLast;
    }
    
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

        cout << checker << endl << checkerReverse << endl;

        return (checker == checkerReverse);
    }
};
