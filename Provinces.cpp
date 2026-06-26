class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> leader(n);
        for (int i = 1; i < n; i++)
        {
            leader[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    int a = findLeader(i, leader);
                    int b = findLeader(j, leader);
                    leader[a] = b;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (leader[i] == i)
                ans++;
        }

        return ans;
    }

    int findLeader(int i, vector<int> &leader)
    {
        if (leader[i] == i)
            return i;
        return leader[i] = findLeader(leader[i], leader);
    }
};