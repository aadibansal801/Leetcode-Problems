class Solution {
public:

    int n;

    pair<int,int> getPos(int pos){
        int row = (pos-1)/n;
        int col = (pos-1)%n;
        if(row % 2 == 1){
            col = n - 1 - col;
        }
        row = n - 1 - row;
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int>q;
        vector<bool>visited(n*n+1, false);
        q.push(1);
        visited[1] = true;
        int moves = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int pos = q.front();
                q.pop();
                if(pos == n*n) return moves;
                for(int next = pos+1; next <= min(pos+6, n*n); next++){
                    auto [row, col] = getPos(next);
                    int dest = board[row][col];
                    int finalPos = (dest == -1 ? next : dest);
                    if(!visited[finalPos]){
                        visited[finalPos] = true;
                        q.push(finalPos);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};