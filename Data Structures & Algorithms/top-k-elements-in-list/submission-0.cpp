class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int num:nums){
            mp[num]++;
        }

        vector<pair<int,int>> arr;

        for(auto it:mp){
            arr.push_back({it.second,it.first});
        }

        sort(arr.begin(),arr.end(),greater<pair<int,int>>());

        vector<int> result;

        for(int i=0;i<k;i++){
            result.push_back(arr[i].second);
        }
        return result;
    }
};
