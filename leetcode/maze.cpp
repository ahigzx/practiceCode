#include <iostream>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 100;
typedef pair<int, int> P;
int maze[MAX_N][MAX_M+1];
int dx[4] = {1, 0, -1, 0}; //x y反向位移
int dy[4] = {0, 1, 0 ,-1};
int n, m;
int last_dir[MAX_N][MAX_M]; //访问当前结点所走的方向
int dest[MAX_N][MAX_M];  //到某结点的长度
P father[MAX_N][MAX_M]; //保存当前结点上一次访问的结点


void bfs(int x, int y, int destx, int desty) //保证输入的x y都在范围内,这边不做x y destx desty的边界检查
{
    queue<P> que;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++i)
        {
            dest[i][j] = INF;
        }
    }
    dest[x][y] = 0;
    que.push(P(x,y));

    while(que.size())
    {
        P start = que.top();
        father[x][y] = start;
        que.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = start.first + dx[dir];
            int ny = start.second + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dest[nx][ny] != INF && maze[nx][ny]!= 0)
            {
                que.push(P(nx,ny));
                dest[nx][ny] = dest[start.first][start.second] + 1;
                father[nx][ny] = start;
                last_dir[nx][ny] = dir;
            }
            if(nx == destx && ny == desty)
            {
                break;
            }
        }
        if(i != 4)
        {
            break;
        }

    }

}


void printPath(int x, int y) //打印某结点到出发点的路径
{
    P fatherxy = father[x][y];
    int fx = fatherxy.first;
    int fy = fatherxy.second;
    
    if(fx != x || fy != y)
    {
        printPath(fx, fy);
        cout << dir[x][y] << " "; //表示路径的数字，可以设置char型name数组表示方向
    }
    cout << endl;
}
