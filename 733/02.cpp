class Solution {
    public:

    vector<int> direction_row = {0, -1, 0, 1};
    vector<int> direction_col = {1, 0, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        RecursiveFill(image, sr, sc, image[sr][sc], color);

        return image;
    }

    void RecursiveFill(vector<vector<int>>& image, int row, int col, int from_color, int to_color){
        if ( row < 0 || row >= image.size() || col < 0 || col >= image[0].size()){
            return;
        }

        if (image[row][col] != from_color) {
            return;
        }

        if (image[row][col] == to_color) {
            return;
        }

        image[row][col] = to_color;

        for (int i = 0; i < 4; i++) {
            RecursiveFill(image, row + direction_row[i], col + direction_col[i], from_color, to_color);
        }
    }
};
