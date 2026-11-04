class Solution {
public:

    set<pair<int,int>>visited;

    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false;
        visited.clear();
        return dfs(0,0,x,y,target);
    }

    bool dfs(int a, int b, int x, int y, int target){
        if(a == target || b == target || a + b == target){
            return true;
        }
        if(visited.count({a,b})) return false;
        visited.insert({a,b});
        if(dfs(x,b,x,y,target)) return true;
        if(dfs(a,y,x,y,target)) return true;
        if(dfs(0,b,x,y,target)) return true;
        if(dfs(a,0,x,y,target)) return true;
        int pour = min(a, y-b);
        if(dfs(a-pour, b+pour, x,y, target)) return true;
        pour = min(b,x-a);
        if(dfs(a+pour, b-pour, x,y, target)) return true;
        return false;
    }
};