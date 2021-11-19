#pragma once


#include <vector>

#include "Node.h"

using namespace std;



Node* CloneGraph_Recursive(Node* node);
Node* CloneGraph_Iterative(Node* node);
bool CourseSchedule_DFS(int numCourses, vector<vector<int>> prerequisites);
bool CourseSchedule_Khans(int numCourses, vector<vector<int>> prerequisites);
int NumberOfIslands(vector<vector<char>> grid);
vector<vector<int>> PacificAtlanticWaterFlow(vector<vector<int>> heights);
