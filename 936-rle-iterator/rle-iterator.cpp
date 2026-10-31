class RLEIterator {
public:

    vector<int>values;
    int idx = 0;

    RLEIterator(vector<int>& encoding) {
        values = encoding;
    }
    
    int next(int n) {
        while(idx < values.size()){
            if(values[idx] >= n){
                values[idx] -= n;
                return values[idx+1];
            }
            n -= values[idx];
            idx += 2;
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */