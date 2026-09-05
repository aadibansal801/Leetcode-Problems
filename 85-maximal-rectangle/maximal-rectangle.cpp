class Solution {
public:

    int solve(vector<int>&height){
        int n = height.size();
        stack<int>st;
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i = 0; i<n; i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            left[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            right[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            int width = right[i] - left[i] -1;
            int area = height[i] * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1') height[j]+=1;
                else height[j] = 0;
            }
            int area = solve(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};