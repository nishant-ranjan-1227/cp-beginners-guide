#include <bits/stdc++.h>
using namespace std;
#define ll           long long
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           printf("\n")
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define fi           first
#define se           second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define maxx         5000005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
#define dbug(a)      cout<<"dbug : "<<a<<endl
#define debug(a,b)   cout<<a<<" "<<b<<endl
#define read(v)      vec v(n,0); rep(i,0,n) {cin>>v[i];}
#define write(a,n)   rep(i,0,n) {cout<<a[i]<<" ";}
#define All          rep(i,0,n) 
const int N = 2e5+5;
const ll mod = 1e9+7;


int n;
vector<int> adj[N];
vector<int> vis(N);
int root = 1;
int maxDistance = 0;

void dfs(int node, int l) {
	
	vis[node] = 1;

	if(maxDistance1 < l) {
		root = node;
		maxDistance1 = l;
	}

	for(auto child : adj[node]) {
		if(vis[child] == 0) {
			dfs(child, l+1);
		}
	}
}


void solve() {
	cin >> n;

	rep(i,0,n+1) {
		vis[i] = 0;
		adj[i].clear();
	}

	root = 1;

	rep(i,0,n-1) {
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(root, 0);
	maxDistance1 = 0;
	rep(i,0,n+1) {
		vis[i] = 0;
	}
	dfs(root, 0);

	cout << maxDistance;

	return;



}



//Check for test cases
int main(){

	#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	#endif

 

int test=1;
//cin>>test;
while(test--)
{
 	solve();
}
 return 0;
}
