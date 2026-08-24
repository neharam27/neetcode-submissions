class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int left=0;
        int maxfreq=0;
        int ans=0;

        for(int right=0;right<s.length();right++) {
            count[s[right]]++;

            maxfreq= max(maxfreq,count[s[right]]);

            if((right-left+1) - maxfreq >k) {
                count[s[left]]--;
                left++;
            }

            ans= max((right-left+1),ans);

        }
        return ans;
    }
};
