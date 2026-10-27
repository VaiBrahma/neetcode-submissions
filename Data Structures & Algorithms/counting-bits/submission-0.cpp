class Solution {
private:    
    int hamming(int a){
        int cnt = 0;
        while(a > 0){
            cnt += a&1;
            a = a>>1;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++) ans.push_back(hamming(i));
        return ans;
    }
};
