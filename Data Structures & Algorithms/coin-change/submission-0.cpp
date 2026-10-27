class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+2, INT_MAX);
        dp[0] = 0;
        for(int coin: coins){
            for(int i = 0; i<dp.size(); i++){
                if(dp[i] != INT_MAX){
                    if(i + coin < amount + 2) dp[i+coin] = min(dp[i + coin], 1 + dp[i]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
