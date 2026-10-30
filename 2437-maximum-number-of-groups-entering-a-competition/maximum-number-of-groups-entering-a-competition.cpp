class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        return (sqrt(1 + 8LL * n) - 1) / 2;
    }
};