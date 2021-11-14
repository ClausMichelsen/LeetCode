#include <gtest\gtest.h>

#include "Functions.h"
#include "Node.h"


TEST(DataStructures_Graph, CloneGraph_Recursive)
{
    Node node0_1{ 1 };
    Node node0_2{ 2 };
    Node node0_3{ 3 };
    Node node0_4{ 4 };
    node0_1.neighbors.push_back(&node0_2);
    node0_1.neighbors.push_back(&node0_4);
    node0_2.neighbors.push_back(&node0_1);
    node0_2.neighbors.push_back(&node0_3);
    node0_3.neighbors.push_back(&node0_2);
    node0_3.neighbors.push_back(&node0_4);
    node0_4.neighbors.push_back(&node0_1);
    node0_4.neighbors.push_back(&node0_3);
    Node* clone0 = CloneGraph_Recursive(&node0_1);
    EXPECT_EQ(1, clone0->val);
    EXPECT_EQ(2, clone0->neighbors.size());
    EXPECT_NE(&node0_1, clone0);
};

TEST(DataStructures_Graph, CloneGraph_Iterative)
{
    Node node0_1{ 1 };
    Node node0_2{ 2 };
    Node node0_3{ 3 };
    Node node0_4{ 4 };
    node0_1.neighbors.push_back(&node0_2);
    node0_1.neighbors.push_back(&node0_4);
    node0_2.neighbors.push_back(&node0_1);
    node0_2.neighbors.push_back(&node0_3);
    node0_3.neighbors.push_back(&node0_2);
    node0_3.neighbors.push_back(&node0_4);
    node0_4.neighbors.push_back(&node0_1);
    node0_4.neighbors.push_back(&node0_3);
    Node* clone0 = CloneGraph_Iterative(&node0_1);
    EXPECT_EQ(1, clone0->val);
    EXPECT_EQ(2, clone0->neighbors.size());
    EXPECT_NE(&node0_1, clone0);
};

TEST(DataStructures_Graph, CourseSchedule_Khans)
{
    bool can0 = CourseSchedule_Khans(2, { {1, 0} });
    EXPECT_EQ(true, can0);

    bool can1 = CourseSchedule_Khans(2, { {1, 0}, {0, 1} });
    EXPECT_EQ(false, can1);

    bool can2 = CourseSchedule_Khans(1, { });
    EXPECT_EQ(true, can2);

    bool can3 = CourseSchedule_Khans(20, { {0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4} });
    EXPECT_EQ(false, can3);

    bool can4 = CourseSchedule_Khans(3, { {0,2},{1,2},{2,0} });
    EXPECT_EQ(false, can4);

    bool can5 = CourseSchedule_Khans(3, { {1,0},{1,2},{0,1} });
    EXPECT_EQ(false, can5);

    bool can6 = CourseSchedule_Khans(5, { {1,4},{2,4},{3,1},{3,2} });
    EXPECT_EQ(true, can6);
};

TEST(DataStructures_Graph, CourseSchedule_DFS)
{
    bool can0 = CourseSchedule_DFS(2, { {1, 0} });
    EXPECT_EQ(true, can0);

    bool can1 = CourseSchedule_DFS(2, { {1, 0}, {0, 1} });
    EXPECT_EQ(false, can1);

    bool can2 = CourseSchedule_DFS(1, { });
    EXPECT_EQ(true, can2);

    bool can3 = CourseSchedule_DFS(20, { {0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4} });
    EXPECT_EQ(false, can3);

    bool can4 = CourseSchedule_DFS(3, { {0,2},{1,2},{2,0} });
    EXPECT_EQ(false, can4);

    bool can5 = CourseSchedule_DFS(3, { {1,0},{1,2},{0,1} });
    EXPECT_EQ(false, can5);

    bool can6 = CourseSchedule_DFS(5, { {1,4},{2,4},{3,1},{3,2} });
    EXPECT_EQ(true, can6);
};

TEST(DataStructures_Graph, NumberOfIslands)
{
    int count0 = NumberOfIslands({
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
        });
    EXPECT_EQ(1, count0);

    int count1 = NumberOfIslands({
        {'1','1','0','0','0'} ,
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
        });
    EXPECT_EQ(3, count1);
};

TEST(DataStructures_Graph, PacificAtlanticWaterFlow)
{
    vector<vector<int>> cords0 = PacificAtlanticWaterFlow({ {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} });
    EXPECT_EQ(7, cords0.size()); // [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

    vector<vector<int>> cords1 = PacificAtlanticWaterFlow({ {2,1},{1,2} });
    EXPECT_EQ(4, cords1.size()); // [[0,0],[0,1],[1,0],[1,1]]
};
