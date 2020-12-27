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
const int N = 1e5+5;
const ll mod = 1e9+7;

/*

For all the forward edge orient from parent to node
For all the back edge orient from child to parent


always check for which is the child in the backedge

*/

ll n,m;
vec G[N];
vec vis(N);
vec in(N);
vec low(N);
ll timer = 0;
bool possible = true;
set<pair<ll,ll>> res;

void dfs(ll node, ll parent) {
	vis[node] = 1;
	in[node] = timer;
	low[node] = timer;
	timer++;

	for(auto child : G[node]) 
	{
		if(child == parent) continue;

		else if(vis[child] == 1) {
			// backedge
			low[node] = min(low[node], in[child]);
			//res.insert({child,node});

			//orient all the backedge from child to ancestor
			if(in[child] > in[node]) {
				//child came later
				res.insert({child,node});
			} else {
				res.insert({node,child});
			}

		}

		else if(vis[child] == 0) {
			//forward edge - can be a bridge
			dfs(child,node);

			//check for bridge
			if(low[child] > in[node]) 
			{
				//it is a bridge
				possible = false;

				//cout << "bridge " << node << " - " << child << endl;
				break;
			}

			low[node] = min(low[node],low[child]);
			res.insert({node,child});
		}

	}



}


void solve() {
	cin >> n >> m;
	rep(i,0,m) {
		ll a,b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1, -1);

	if(!possible) cout << 0;
	else
	{
		for(auto it : res)
		{
			cout << it.fi << " " << it.se << endl;
		}
	}


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
