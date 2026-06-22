class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        vector<string> ans;
        backtrack(mapping, digits, temp, ans, 0);
        return ans;
    }
    void backtrack(vector<string> &mapping, string &digits, string temp, vector<string> &ans, int start)
    {
        // populates ans and stops from goinf further than needed.
        if (temp.size() == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        // this gives us correct button to go to  in maoooing
        int index = digits[start] - '0';
        string s = mapping[index];
        // this loop gets all possible combinations and recalls
        for (int i = 0; i < s.size(); i++)
        {
            temp.push_back(s[i]);
            backtrack(mapping, digits, temp, ans, start + 1);
            temp.pop_back();
        }
    }
};