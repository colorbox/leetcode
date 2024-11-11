/*
4:25
Space O: O(N)
Time O: O(N)

ransomに使用する文字が十分存在するかどうかをカウントすればよいと考える。
magazineにある文字を高速にチェックできないといけないので、ハッシュ(map)にして高速化を考える。
magazineに存在しない文字や、消費し尽くした文字を指定されたらransomは成立しなくなるのでその時点でfalseを返せる。
falseを返さずに最後までチェックし終えたら
*/
/*
mapで`[]`を使用することで不要な初期化処理やnullチェックを削除
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> character_count;
        for (char c: magazine) {
            character_count[c]++;
        }

        for (char c: ransomNote) {
            if (character_count[c] <= 0) {
                return false;
            }
            character_count[c]--;
        }

        return true;
    }
};
