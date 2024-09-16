class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm
        int currSum = 0, maxSum = INT_MIN;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if(currSum < 0)
            {
                currSum = 0;
            }
        }

        return maxSum;
    }
};
