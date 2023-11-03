bool visited[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int rowSize = 0;
int colSize = 0;

class Solution {
public:
    void BFS(int y, int x, vector<vector<char>>& grid)
    {
        visited[y][x] = true;
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= rowSize || nx >= colSize || grid[ny][nx] == '0' || visited[ny][nx] == true)
            {
                continue;
            }
            else
            {
                BFS(ny, nx, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        memset(visited, false, sizeof(bool) * 301 * 301);

        rowSize = grid.size();
        colSize = grid[0].size();

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    res++;
                    BFS(i, j, grid);
                }
            }
        }

        return res;
    }
};