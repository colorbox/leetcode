/*

Solve Time : 13:59

Time : O(n)
Space : O(n)

UnionFindを用意する方法をまず思いついたが、UnionFind木を用意する手間が惜しいと考え別ルートへ
UnionFindそのものを用意するのではなく、考え方を流用したコードを考える。
初期値を-1で初期化したサイズnのベクタを用意する。
個々の要素に自分のクラスタのリーダーとなるインデックスをもたせる。
edgesの処理に合わせてそれらを更新していくことでリーダー以外のノードがすべて-1以外の数値を持つようになるので、最後に-1を数える。
下記に示すケースで間違えたため、それに合わせて修正を加えてパスしたが、エッジケースの想定が甘かった。
```
n = 3, edges = [[2,0],[2,1]]
n = 5, edges = [[0,1],[1,2],[0,2],[3,4]]
```

修正を加えた結果だいぶUnionFindに近づいた気がする。
*/
class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> nodes = vector<int>(n, -1);
    for (auto edge : edges) {
      int left = edge.front();
      int right = edge.back();
      while (nodes[right] >= 0) {
        right = nodes[right];
      }
      while (nodes[left] >= 0) {
        left = nodes[left];
      }
      if (left == right) {
        continue;
      }
      if (left > right) {
        swap(left, right);
      }
      nodes[right] = left;
    }
    int count = 0;
    for (auto i : nodes) {
      if (i == -1) {
        count++;
      }
    }
    return count;
  }
};
