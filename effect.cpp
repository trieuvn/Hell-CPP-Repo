#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int srcx;
	int srcy; 
	int x;  
	int y;
} Node;

const int MAX = 5005;

int n, r;
queue<Node> q;
bool isEffect[MAX][MAX];
char a[MAX][MAX];

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

void BFS(){
	while(!q.empty()){
		Node node = q.front();
		q.pop();
		
		int startX = node.srcx;
		int startY = node.srcy;

		for (int i = 0; i < 4; i++){
			int nx = node.x + dirx[i];
			int ny = node.y + diry[i];
			
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				
				if (!isEffect[nx][ny]) {
					
					int currentDist = abs(nx - startX) + abs(ny - startY);
					
					if (currentDist <= r) {
						isEffect[nx][ny] = true; 
						
						Node next;
						next.srcx = node.srcx;
						next.srcy = node.srcy;
						next.x = nx;
						next.y = ny;
						q.push(next);
					}
				}
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r;
	
	int stormID = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			if (a[i][j] == 'X'){
				isEffect[i][j] = true;
				
				Node startNode;
				startNode.srcx = i;
				startNode.srcy = j;
				startNode.x = i;
				startNode.y = j;
				
				q.push(startNode);
			} 
		}
	}
	
	BFS();
	
	int safeZone = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!isEffect[i][j]) safeZone++;
		}
	}
	
	cout << safeZone;
	return 0;
}
