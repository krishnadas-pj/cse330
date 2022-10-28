#include <cstdio>
#include <utility>
#include <map>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> ppp;

char board[55][55];
int N, M, K;
priority_queue<pair<int,ppp> > pq;
map<ppp,bool> seen;

bool inbound(int i, int j)
{
    return 0<=i && i<N && 0<=j && j<M;
}

int dijkstra()
{
    pq.push(make_pair(0, make_pair(pii(0,0),0)));
    while(!pq.empty()) {
        int dnow = -pq.top().first;
        pii pos = pq.top().second.first;
        int know = pq.top().second.second;
        pq.pop();
        if (board[pos.first][pos.second]=='*') return dnow;
        if (seen[make_pair(pos,know)]) continue;
        seen[make_pair(pos,know)]=true;
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};
        char dir[]="URDL";
        for(int z=0; z<4; ++z) {
            int i, j;
            i = pos.first+dx[z];
            j = pos.second+dy[z];
            if (!inbound(i,j)) continue;
            int extra;
            if (board[pos.first][pos.second]==dir[z]) extra=0;
            else extra=1;
            if (know<K) {
                pq.push(make_pair(-(dnow+extra), make_pair(pii(i,j),know+1)));
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d%d ", &N, &M, &K);
    for(int i=0; i<N; ++i) scanf("%s", board[i]);

    int ans = dijkstra();
    printf("%d\n", ans);
}



