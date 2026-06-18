class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (!checkCycle(graph, visited, i))
                    return false;
            }
        }
        return true;
    }

    bool checkCycle(vector<vector<int>> &graph, vector<int> &visited, int start)
    {

        if (visited[start] == 1)
            return false;
        if (visited[start] == 2)
            return true;

        visited[start] = 1;

        for (int i = 0; i < graph[start].size(); i++)
        {

            int neighbor = graph[start][i];
            if (!checkCycle(graph, visited, neighbor))
            {
                return false;
            }
        }
        visited[start] = 2;
        return true;
    }
};