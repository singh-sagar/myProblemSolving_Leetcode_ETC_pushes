class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // take a node, color is red , color all the adjacent as blues.?
        //  if something colored is encountered n is suppose to be given a different color this time
        // means its not bipartite.
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == 0)
            {
                color[i] = 1;
                if (!check(graph, color, i))
                    return false;
            }
        }
        return true;
    }

    bool check(vector<vector<int>> &graph, vector<int> &color, int start)
    {

        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            for (int j = 0; j < graph[i].size(); j++)
            {
                int v = graph[i][j];
                if (color[v] == 0)
                {
                    if (color[i] == 1)
                        color[v] = 2;
                    else
                        color[v] = 1;
                    q.push(v);
                }

                else if (color[v] == color[i])
                    return false;
            }
        }
        return true;
    }
};