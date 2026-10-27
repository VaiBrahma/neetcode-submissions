class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int leftMax = 0;
        int rightMax = 0;

        int i = 0; 
        int j = height.size() - 1;
        int ans = 0;
        while(j - i > 0){
            if(height[i] > leftMax) leftMax = height[i];
            if(height[j] > rightMax) rightMax = height[j];

            if(height[i] < height[j]) {
                 ans += max(0, min(leftMax, rightMax) - height[i]);
                 i++;
            }
            else {
                ans += max(0, min(leftMax, rightMax) - height[j]);
                j--;
            }
        }
        return ans;
    }
};
