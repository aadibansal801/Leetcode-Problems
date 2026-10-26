class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int start = image[sr][sc];
        if(start == color){
            return image;
        }
        queue<pair<int,int>>q;
        image[sr][sc] = color;
        q.push({sr, sc});
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == start){
                    q.push({nr,nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};

//   0 1 2    2
// 0 2 2 0
// 1 2 2 2
// 
// [ [0,1], [1,2] ]
// r = 1, c = 2
//
//
//