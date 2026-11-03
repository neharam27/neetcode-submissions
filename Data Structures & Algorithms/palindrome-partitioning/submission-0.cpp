class Solution {
    bool isPalindrom(string s, int start, int end) {
        while(start<end) {
            if(s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string> &temp, vector<vector<string>>&result){
        if(start==s.length()){
            result.push_back(temp);
            return;
        }

        for(int end=start; end<s.length(); end++){
            if (isPalindrom(s, start, end)) {
            string substring= s.substr(start, end-start+1);
            temp.push_back(substring);
            backtrack(s,end+1,temp,result);
            temp.pop_back();
        }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;

        backtrack(s, 0, temp, result);

        return result;
    }
};
