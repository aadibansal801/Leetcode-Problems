class Solution {
public:
    int nextGreaterElement(int num) {
        int n = (int)log10(num) + 1;
        vector<int>arr(n);
        int ptr = n-1;
        int temp = num;
        while(temp > 0){
            arr[ptr--] = temp%10;
            temp/=10;
        }
        int i = n-2;
        while(i >= 0 && arr[i] >= arr[i+1]){
            i--;
        }
        if(i < 0) return -1;
        int j = n-1;
        while(j > i && arr[j] <= arr[i]){
            j--;
        }
        swap(arr[i], arr[j]);
        int start = i+1;
        int end = n-1;
        while(start < end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        long long res = 0;
        for(int i = 0; i<n; i++){
            res = res*10 + arr[i];
        }
        if(res > INT_MAX){
            return -1;
        }
        return (int)res;
    }
};