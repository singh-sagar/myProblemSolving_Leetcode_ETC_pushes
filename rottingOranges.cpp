class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        int count = -1, freshCount = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0)
            return 0;

        while (!q.empty())
        {

            count++;
            int size = q.size();
            for (int j = 0; j < size; j++)
            {

                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for (int i = 0; i < 4; i++)
                {

                    int c = a + dr[i];
                    int d = b + dc[i];
                    if (c >= 0 && c < grid.size() && d >= 0 &&
                        d < grid[0].size())
                    {
                        if (grid[c][d] == 1)
                        {
                            freshCount--;
                            grid[c][d] = 2;
                            q.push({c, d});
                        }
                    }
                }
            }
        }

        if (freshCount == 0)
            return count;
        else
            return -1;
    }
};