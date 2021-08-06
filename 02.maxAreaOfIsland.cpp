#include<iostream>
#include<unordered_map>
#include <string>  
/*
695. 岛屿的最大面积
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)


示例 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:
[[0,0,0,0,0,0,0,0]]

对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

思路：
深度优先遍历：
1、从岛屿的某一块陆地出发，向四个方向递归地DFS
2、为保证每一块陆地只访问一次，将已访问的陆地置为0
3、边界判断
4、递归，以此求解
*/

using namespace std;  
class Solution{
  int dfs(vector<vector<int>>& grid, int cur_i, int cur_j){
    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1){
      return 0;
    }
    grid[cur_i][cur_j] = 0;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    int ans = 1;
    for (int index = 0; index != 4; ++index){
      int next_i = cur_i + di[index],next_j = cur_j + dj[index];
      ans += dfs(grid, next_i, next_j);
    }
    return ans;
  }
  
public:
  int maxAreaOfIsland(vector<vector<int>>& grid){
    int ans = 0;
    for (int i = 0; i != grid.size(); ++i){
      for (int j = 0; j != grid[0].size(); ++j){
	ans = max(ans, dfs(grid, i, j));
      }
    }
    return ans;

  }
};

int main(){
  vector < int> grid(8,13)={{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  Solution ss;
  int ret = 0;
  ret = ss.maxAreaOfIsland(grid);
  cout <<"结果："<<ret<< endl;
    
}
