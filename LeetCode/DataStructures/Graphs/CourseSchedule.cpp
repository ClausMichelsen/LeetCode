#include <queue>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/course-schedule/
bool CourseSchedule_Khans(int numCourses, vector<vector<int>> prerequisites)
{
    // Khan's algorithm
    using Adjacency = vector<vector<int>>;
    using Degree = vector<int>;

    Adjacency adj(numCourses);
    Degree deg(numCourses);
    for (const auto& c : prerequisites)
    {
        const int course{ c[0] };
        const int prerequisite{ c[1] };
        adj[prerequisite].push_back(course);
        deg[course]++;
    }

    queue<int> courses;
    for (int i{ 0 }; i < numCourses; ++i)
        if (!deg[i])
            courses.push(i);

    while (!courses.empty())
    {
        int cur{ courses.front() };
        courses.pop();

        --numCourses;
        for (const auto& a : adj[cur])
            if (--deg[a] == 0)
                courses.push(a);
    }

    return 0 == numCourses;
}



using Graph = vector<vector<int>>;
Graph CreateGraph(int numCourses, vector<vector<int>> prerequisites);
bool IsAcyclic(const Graph& g, vector<bool>& doing, vector<bool>& done, int course);

bool CourseSchedule_DFS(int numCourses, vector<vector<int>> prerequisites)
{
    Graph g{ CreateGraph(numCourses, prerequisites) };

    vector<bool> doing(numCourses), done(numCourses);
    for (int course{ 0 }; course < numCourses; ++course)
    {
        if (!done[course])
            if (!IsAcyclic(g, doing, done, course))
                return false;
    }

    return true;
}

Graph CreateGraph(int numCourses, vector<vector<int>> prerequisites)
{
    Graph g{ static_cast<size_t>(numCourses) };
    for (const auto& c : prerequisites)
    {
        const int course{ c[0] };
        const int prerequisite{ c[1] };
        g[course].push_back(prerequisite);
    }

    return g;
}

bool IsAcyclic(const Graph& g, vector<bool>& doing, vector<bool>& done, int course)
{
    if (doing[course])
        return false; // Cyclic.
    if (done[course])
        return true; // Already checked.

    doing[course] = done[course] = true;
    for (int p : g[course])
    {
        if (!IsAcyclic(g, doing, done, p))
            return false;
    }

    doing[course] = false;

    return true;
}
