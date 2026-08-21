class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty())
            return 0;
        
        sort(nums.begin(),nums.end());
        int current=1;
        int longest=1;

        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i+1]==nums[i]+1) {
                current++;
            }
            else if(nums[i+1]==nums[i]){
                continue;
            }
            else{
                current=1;
            }

            longest= max(current,longest);
        }
        return longest;
    }
};
