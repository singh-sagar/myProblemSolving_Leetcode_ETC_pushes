class Solution
{
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> v(numCourses);
        stack<int> numbers;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> check(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            {
                if (check[i] == 0)
                    if (!checkCourses(v, check, i, numbers))
                        return {};
            }
        }
        while (!numbers.empty())
        {
            ans.push_back(numbers.top());
            numbers.pop();
        }
        return ans;
    }

    bool checkCourses(vector<vector<int>> &v, vector<int> &check, int sr, stack<int> &numbers)
    {
        if (check[sr] == 1)
            return false;
        if (check[sr] == 2)
            return true;
        check[sr] = 1;
        for (int i = 0; i < v[sr].size(); i++)
        {
            int next = v[sr][i];
            if (!checkCourses(v, check, next, numbers))
                return false;
        }
        check[sr] = 2;
        numbers.push(sr);
        return true;
    }
};