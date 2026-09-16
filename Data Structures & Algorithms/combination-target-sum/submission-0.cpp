class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        dfs(nums,target,0,curr);
        return ans;
    }

    void dfs(vector<int>&nums,int target,int i,vector<int> &curr) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }

        if(i==nums.size()||target<0) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums,target-nums[i],i,curr);

        curr.pop_back();
        dfs(nums,target,i+1,curr);
    }
};
