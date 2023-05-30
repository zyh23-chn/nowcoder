#include <bits/stdc++.h>
using namespace std;

int t,n;
long long h,r;
const int N=1e3;
long long x[N],y[N],z[N];
bool g[N][N];
bool top[N],down[N]; 

bool vis[N];

bool dfs(int i){
	if(top[i]){
		return true;
	}
	if(vis[i]){
		return false;
	}
	vis[i]=true;
	for(int j=0;j<n;++j){
		if(g[i][j]&&dfs(j)){
			return true;
		}
	}
	return false;
}

bool f(){
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;++i){
		if(down[i]&&dfs(i)){
			return true;
		}
	}
	return false;
}

int main()
{
	cin>>t;
	while(t--){
		memset(g,0,sizeof g);
		memset(top,0,sizeof top);
		memset(down,0,sizeof down);
		cin>>n>>h>>r;
		for(int i=0;i<n;++i){
			cin>>x[i]>>y[i]>>z[i];
			top[i]=z[i]+r>=h;
			down[i]=z[i]<=r;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(i==j){
					continue;
				}
				g[i][j]=g[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])<=4*r*r; 
			}
		}
		cout<<(f()?"Yes":"No")<<'\n';
	}
    return 0;
}
