#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int INF=1e8+10;
int vis[maxn];
int dis[maxn];
int mp[maxn][maxn];
int n,m;
void dijkstra() {
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++) {
		dis[i]=INF;
	}
	dis[1]=0;
	vis[1]=1;
	int k;
	for(int i=1; i<=n; i++) {
		int minn=INF;
		for(int j=1; j<=n; j++) {
			if(!vis[j]&&minn>dis[j]) {
				k=j;
				minn=dis[j];
			}
		}
		vis[k]=1;
		for(int j=1; j<=n; j++) {
			if(!vis[j]&&dis[j]>dis[k]+mp[k][j]) {
				dis[j]=dis[k]+mp[k][j];
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j)mp[i][j]=1;
			else mp[i][j]=INF;
		}
	}
	for(int i=0; i<m; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		mp[a][b]=c;
	}
	dijkstra();
	cout<<dis[n]<<endl;
}
