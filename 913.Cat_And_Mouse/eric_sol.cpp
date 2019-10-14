/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 *
 * https://leetcode.com/problems/cat-and-mouse/description/
 *
 * algorithms
 * Hard (29.55%)
 * Likes:    217
 * Dislikes: 49
 * Total Accepted:    5.5K
 * Total Submissions: 18.5K
 * Testcase Example:  '[[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]'
 *
 * A game on an undirected graph is played by two players, Mouse and Cat, who
 * alternate turns.
 * 
 * The graph is given as follows: graph[a] is a list of all nodes b such that
 * ab is an edge of the graph.
 * 
 * Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second,
 * and there is a Hole at node 0.
 * 
 * During each player's turn, they must travel along one edge of the graph that
 * meets where they are.  For example, if the Mouse is at node 1, it must
 * travel to any node in graph[1].
 * 
 * Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
 * 
 * Then, the game can end in 3 ways:
 * 
 * 
 * If ever the Cat occupies the same node as the Mouse, the Cat wins.
 * If ever the Mouse reaches the Hole, the Mouse wins.
 * If ever a position is repeated (ie. the players are in the same position as
 * a previous turn, and it is the same player's turn to move), the game is a
 * draw.
 * 
 * 
 * Given a graph, and assuming both players play optimally, return 1 if the
 * game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a
 * draw.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
 * Output: 0
 * Explanation:
 * 4---3---1
 * |   |
 * 2---5
 * \ /
 * 0
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= graph.length <= 50
 * It is guaranteed that graph[1] is non-empty.
 * It is guaranteed that graph[2] contains a non-zero element. 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    // c, m , turn
    int memo[101][51][51];
    // mouse win : 1 , cat win 2, draw : 0
    int catMouseGame(vector<vector<int>> &graph)
    {
        memset(memo, -1, sizeof(memo));
        // previously visited
        return dfs(graph, 0, 1, 2);
    }

    // cat position , mouse position , mouse turn
    int dfs(vector<vector<int>> &graph, int t, int m, int c)
    {
        if (t == graph.size() * 2)
            return 0;
        if (m == c)
        {
            return memo[t][m][c] = 2;
        }
        if (m == 0)
        {
            return memo[t][m][c] = 1;
        }
        if (memo[t][m][c] != -1)
            return memo[t][m][c];
        // mouse move
        if (t % 2 == 0)
        {
            bool catWin = true;
            for (int next : graph[m])
            {
                int tmp = dfs(graph, t + 1, next, c);
                if (tmp == 1)
                {
                    return memo[t][m][c] = 1;
                }
                else if (tmp == 0)
                {
                    // mouse can draw
                    catWin = false;
                }
            }
            return memo[t][m][c] = catWin ? 2 : 0;
        }
        // cat move
        else
        {
            bool mouseWin = true;
            for (int next : graph[c])
            {
                // mouse cant go to hole
                if (next == 0)
                    continue;
                int tmp = dfs(graph, t + 1, m, next);
                if (tmp == 2)
                {
                    return memo[t][m][c] = 2;
                }
                else if (tmp == 0)
                {
                    mouseWin = false;
                }
            }
            return memo[t][m][c] = mouseWin ? 1 : 0;
        }
    }
};
// @lc code=end
