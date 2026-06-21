class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(ans, candidates, temp, target, 0);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &temp, int target, int start)
    {

        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++)
        {

            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            backtrack(ans, candidates, temp, target - candidates[i], i);
            temp.pop_back();
        }
    }
};