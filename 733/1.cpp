class Solution {
    public:
    vector<int> direction_rows = {0, 1, 0, -1};
    vector<int> direction_cols = {1, 0, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        RecursiveFill(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void RecursiveFill(vector<vector<int>>& pixels, int row, int col, int from_color, int to_color) {
        if (row < 0 || col < 0 || row >= pixels.size() || col >= pixels[0].size()) {
            return;
        }

        if (pixels[row][col] != from_color) {
            return;
        }

        pixels[row][col] = to_color;

        for (int i = 0; i < 4; i ++) {
            RecursiveFill(pixels, row + direction_rows[i], col + direction_cols[i], from_color, to_color);
        }
    }
};
