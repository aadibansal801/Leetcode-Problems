class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>ans, words;
        string word = "";
        int maxLen = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                words.push_back(word);
                maxLen = max(maxLen, (int)word.size());
                word = "";
            }else{
                word += s[i];
            }
        }
        words.push_back(word);
        maxLen = max(maxLen, (int)word.size());
        for(string &w: words){
            w+=string(maxLen - w.size(), ' ');
        }
        
        for(int i = 0; i<maxLen; i++){
            string row = "";
            for(int j = 0; j<words.size(); j++){
                row+=words[j][i];
            }
            while(!row.empty() && row.back() == ' '){
                row.pop_back();
            }
            ans.push_back(row);
        }
        return ans;
    }
};