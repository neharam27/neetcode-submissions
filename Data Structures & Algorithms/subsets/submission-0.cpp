class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dfs(nums,0,curr);
        return ans;
    }

    void dfs(vector<int>& nums, int i, vector<int> &curr) {
        if(i==nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums,i+1,curr);

        curr.pop_back();
        dfs(nums,i+1,curr);
    }
};
