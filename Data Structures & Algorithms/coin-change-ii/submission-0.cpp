class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+2, INT_MAX);
        vector<int> total_ways(amount + 2, 0);
        dp[0] = 0;
        total_ways[0] =1;
        for(int coin: coins){
            for(int i = 0; i<dp.size(); i++){
                if(dp[i] != INT_MAX){
                    if(i + coin < amount + 2) {
                        dp[i + coin] = min(dp[i + coin], 1 + dp[i]);
                        total_ways[i + coin] += total_ways[i];
                    }
                }
            }
        }

        return total_ways[amount];
    }
};
