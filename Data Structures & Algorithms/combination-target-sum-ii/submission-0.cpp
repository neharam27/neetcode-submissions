class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<int> curr;
        dfs(candidates,target,0,curr);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int i, vector<int> &curr) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        if(target<0) {
            return;
        }

        for(int j=i;j<candidates.size();j++) {
            if(j>i && candidates[j]==candidates[j-1]) {
                continue;
            }

            if(candidates[j]>target) {
                break;
            }
            curr.push_back(candidates[j]);
            dfs(candidates,target-candidates[j],j+1,curr);
            curr.pop_back();
        }
    }
};
