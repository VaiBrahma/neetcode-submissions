class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(int k = 0; k<nums.size() - 2; k++){
            if(k!=0 && nums[k] == nums[k-1]) continue;
            int i = k + 1;
            int j = nums.size() - 1;
            
            int target = -nums[k];
            while(i < j){
                int sum = nums[i] + nums[j];
                if(sum == target){
                    v.push_back({nums[k], nums[i], nums[j]});
                    int temp = nums[j];
                    while(i < j && nums[j] == temp) j--;
                }
                else if(sum > target) j--;
                else i++;
            }
        }
        return v;
    }
};
