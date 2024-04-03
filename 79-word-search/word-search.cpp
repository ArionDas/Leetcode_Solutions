class Solution {
public:

    bool search_word(vector<vector<char>>& board, string word, int row, int col, int ind, int n, int m) {

        // when the string is matched
        if(word.length() == ind)
            return 1;

        // cases where string won't be found
        if(row<0 || col<0 || row==n || col==m || board[row][col]!=word[ind] || board[row][col]=='!')
            return 0;

        // to ensure we don't revisit the same cell
        char c = board[row][col];
        board[row][col] = '!';

        // going up
        bool top = search_word(board, word, row, col-1, ind+1, n, m);

        // coming down
        bool down = search_word(board, word, row, col+1, ind+1, n, m);

        // going right
        bool right = search_word(board, word, row+1, col, ind+1, n, m);

        // going left
        bool left = search_word(board, word, row-1, col, ind+1, n, m);

        // undoing the change
        board[row][col] = c;

        return top || down || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int ind = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==word[ind])
                    if(search_word(board, word, i, j, ind, n, m))
                        return 1;
            }
        }

        return 0;
    }
};