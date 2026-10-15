class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        vector<string> matching = products;
        string prefix = "";
        for(char c: searchWord){
            prefix+=c;
            vector<string> next;
            for(string& product: matching){
                if(product.substr(0, prefix.size()) == prefix){
                    next.push_back(product);
                }
            }
            matching = next;
            vector<string>suggestions;
            for(int i = 0; i<min(3, (int)matching.size()); i++){
                suggestions.push_back(matching[i]);
            }
            ans.push_back(suggestions);
        }
        return ans;
    }
};