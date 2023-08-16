//https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class Board {
  public:
    bool checkWon(vector<vector<int> > board) {
        
        int sum = 0;
        int row = board[0].size();

        for (int i = 0; i < row ; i++) {
            sum = 0;
            for (int j = 0; j < row ; j++) {
                if (board[i][j] == 1)
                    sum++;
            }
            if(sum == row) return true;
        }

        for (int i = 0; i < row ; i++) {
            sum = 0;
            for (int j = 0; j < row ; j++) {
                if(board[j][i] == 1)
                    sum++;
            }
            if(sum == row) return true;
        }

        sum = 0;
        for(int i = 0; i < row ; i++)
        {
            if(board[i][i] == 1)
                sum++;
        }
        if(sum == row) return true;

        sum = 0;
        for(int i = row - 1 ;i >=  0;--i)
        {
            if(board[row - i - 1][i] == 1)
                sum++;
        }
        if(sum == row)  return true;

        return false;

    }
};