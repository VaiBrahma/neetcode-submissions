class Solution {
private:    
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int idx){
        if(idx >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        backtrack(ans, nums, temp, idx + 1);
        temp.pop_back();
        backtrack(ans, nums, temp, idx + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, nums, temp, 0);
        return ans;
    }
};
