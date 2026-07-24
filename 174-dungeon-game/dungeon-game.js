/**
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
    const n = dungeon.length;
    const m = dungeon[0].length;
    const dp = Array.from({length: n}, () => Array(m).fill(-1));
    function solve(i,j){
        if(i>=n || j>=m) return Infinity;
        if(i === n-1 && j === m-1){
            return Math.max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!== -1) return dp[i][j];

        const down = solve(i+1, j);
        const right = solve(i, j+1);
        const need = Math.min(down, right);
        dp[i][j] = Math.max(1, need - dungeon[i][j]);
        return dp[i][j];
    }
    return solve(0,0);
};