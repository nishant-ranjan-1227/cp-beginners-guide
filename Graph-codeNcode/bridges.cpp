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
const int N = 1e6+5;
const ll mod = 1e9+7;

ll n,m;
vec G[N];
vec vis(N);
vec in(N);
vec low(N);
ll timer = 0;

void dfs(ll node,ll parent)
{
	vis[node] = 1;
	in[node] = timer;
	low[node] = timer;
	timer++;

	for(ll child : G[node])
	{
		if(parent == child) continue;

		else if(vis[child] == 1)
		{
			// backedge -> cannot be a bridge
			low[node] = min(low[node],in[child]);
		}
		else if(vis[child] == 0)
		{
			//forward edge -> can be bridge

			//step1. do a dfs call
			dfs(child,node);

			//step2. check for bridge
			if(low[child] > low[node])
			{
				cout << "edge " << node << " - " << child << " is a bridge"<< endl; 
			}

			//step3. uptade the low of node
			low[node] = min(low[node],low[child]);
		}
	}
}

void solve()
{
	cin >> n >> m;
	rep(i,0,m)
	{
		ll a,b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);

	}

	dfs(1,-1);

	rep(i,1,n+1)
	{
		cout << low[i] << " ";
	} nl;
	return;
}

//Check for test cases
int main(){

	#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 

int test=1;
//cin>>test;
while(test--)
{
 	solve();
}
 return 0;
}
