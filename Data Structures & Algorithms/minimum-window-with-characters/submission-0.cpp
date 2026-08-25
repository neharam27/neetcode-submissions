class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;

        for(char c: t) {
            need[c]++;
        }

        int left=0;
        int have=0;
        int min=INT_MAX;

        int require= t.length();
        int start=0;
        
        for(int right=0;right<s.length();right++) {
            char c= s[right];
            window[c]++;

            if(need.count(c) && window[c]<=need[c]) {
                have++;
            }

            while(have==require){
                if (right-left+1 < min) {
                    min = right-left+1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        if (min == INT_MAX)
            return "";

        return s.substr(start, min);
        

    }
};
