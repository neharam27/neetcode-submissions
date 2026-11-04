class Solution {
    void backtrack(string &digits, int index, string &temp, vector<string> &result,vector<string> &letters) {
        if(index==digits.length()){
            result.push_back(temp);
            return;
        }

        int digit= digits[index] - '0';
        string current= letters[digit];

        for(int i=0;i<current.length();i++){
            temp.push_back(current[i]);
            backtrack(digits,index+1,temp,result,letters);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if(digits.empty()){
            return result;
        }
        vector<string> letters = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string temp= "";
        backtrack(digits, 0, temp, result, letters);
        return result;

    }
};
