class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    recursiveFill(image, sr, sc, image[sr][sc], color);

    return image;
  }

  void recursiveFill(vector<vector<int>>& image, int sr, int sc, int fromColor, int toColor) {
    if (image[sr][sc] == toColor) { return; }
    if (image[sr][sc] != fromColor) { return; }
    
    image[sr][sc] = toColor;
    
    if (sr - 1 >= 0) { recursiveFill(image, sr-1, sc, fromColor, toColor); }
    if (sr + 1 < image.size()) { recursiveFill(image, sr+1, sc, fromColor, toColor); }
    if (sc - 1 >= 0) { recursiveFill(image, sr, sc-1, fromColor, toColor); }
    if (sc + 1 < image[0].size()) { recursiveFill(image, sr,  sc+1, fromColor, toColor); }
  }
};

