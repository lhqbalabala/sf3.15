#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int INF=1e8+10;
map<int,int>mp[maxn];
int main() {
	int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		if(i==j)mp[i][j]==0;
    		else mp[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		mp[a][b]=c;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<"V"<<i<<"->"<<"V"<<j<<"  dis:"<<mp[i][j]<<endl;
		}
	}
}
/*4 8
1 4 4
4 1 5
1 3 6
3 1 7
1 2 2
2 3 3
4 3 12
3 4 1
*/
