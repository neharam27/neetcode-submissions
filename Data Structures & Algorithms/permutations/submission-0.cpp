class Solution {
    void backtrack(vector<int> nums, vector<int> temp, vector<vector<int>>& result, vector<bool> visited) {
        if(temp.size()== nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if (visited[i]) {
                continue;
            }

            visited[i]=true;
            temp.push_back(nums[i]);

            backtrack(nums,temp,result,visited);

            temp.pop_back();
            visited[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, temp, result, visited);

        return result;
    }
};
