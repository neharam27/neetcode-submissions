class Solution {
public:
    bool isPalindrome(string s) {
        
        string t= "";
        for(char c: s) {
            if(isalnum(c)){
                t+=tolower(c);
            }
        }

        int n=t.length();

        for(int i=0;i<n/2;i++) {
            if(t[i]!=t[n-1-i]){
                return false;
            }
        }

        return true;
    }
};
