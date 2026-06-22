class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        combination(ans, temp, candidates, target, 0);
        return ans;
    }

    void combination(vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidates, int target, int start)
    {

        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
        {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            combination(ans, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
};