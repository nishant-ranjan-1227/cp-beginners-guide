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
	const ll N = 10000+5;
	const ll zero = 0;
	const ll mod = 1e9+7;


	ll n,m;
	vec G[N];
	vec vis(N);
	vec in(N);
	vec low(N);
	set<ll> AP;
	ll timer;

	void dfs(ll node,ll parent = -1) {
		vis[node] = 1;
		in[node] = timer;
		low[node] = timer;
		timer++;

		ll child_count = 0;

		for(ll child : G[node] ) {
			if(child == parent) continue;

			else if(vis[child] == 1) {
				low[node] = min(low[node], in[child]);
			}

			else if(vis[child] == 0) {
				child_count++;

				dfs(child, node);

				low[node] = min(low[node],low[child]);
				//remember the Arti. Point is the node and not the child
				if(low[child] >= in[node] and parent != -1) {
					AP.insert(node);
				}

				
			}
		}

		if(parent == -1 and child_count > 1) {
			AP.insert(node);
		}


	}


	void solve()
	{
		cin >> n >> m;

		//clear everything
		rep(i,0,n+5) {
			G[i].clear();
			vis[i] = 0;
			low[i] = -1;
			in[i] = -1;

		}
		AP.clear();
		timer = 1;

		// take input
		rep(i,0,m) {
			ll a,b;
			cin >> a >> b;
			G[a].pb(b);
			G[b].pb(a);
		}

		//if the graph is not connected;
		rep(i,1,n+1) {
			if(vis[i] == 0) {
				dfs(i,-1);
			}
		}

		// for(auto x : AP) {
		// 	cout << x << " ";
		// }
		// cout << endl;

		ll ans = AP.size();
		cout << ans << endl;
		return;
	}

	//Check for test cases
	int main(){

	int test=1;
	//cin>>test;



	while(testt--)
	{
		solve();
	}
	 return 0;
	}
