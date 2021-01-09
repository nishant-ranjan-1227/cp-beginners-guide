#include <bits/stdc++.h>
using namespace std;
#define int          long long
#define rep(i,j,n)   for(int i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           cout << endl
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define pri(a)       printf("%lld",a)
#define prinl(a)     printf("%lld\n",a)
#define tc           int t; scn(t); while(t--)
#define vec          vector<int>
#define pb           push_back
#define pairs        pair<int,int>
#define fi           first
#define se           second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define dbug(a)      cout<<"dbug : "<<a<<endl
#define debug(a,b)   cout<<"debug "<<a<<" "<<b<<endl
#define read(v,w)    vec v(w,0); rep(i,0,w) {cin>>v[i];}
#define write(a,w)   rep(i,0,w) {cout<<a[i]<<" ";}
#define All          rep(i,0,n) 
#define IOS          ios_base::sync_with_stdio(false); cin.tie(NULL);

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}


const int N = 10000+5;
int n,m;
vector<int> G[N];
vector<int> in_degree(N);
vector<int> res;
vector<int> vis(N);

void topological_sort_kahn() {
	priority_queue<int> q;
	for(int i=1;i<=n;i++) {
		if(in_degree[i] == 0) {
			q.push(-i);
		}
	}

	while(!q.empty()) {
		int curr = 0-q.top();
		vis[curr] = 1;
		res.pb(-curr);
		q.pop();

		for(int child : G[curr]) {
			in_degree[child]--;
			if(in_degree[child] == 0) {
				q.push(-child);
			}
		}
	}

}

void solve()
{
	scns(n,m);
	rep(i,0,m) {
		int x,y;
		scns(x,y);
		G[x].pb(y);
		in_degree[y]++;
	}

	topological_sort_kahn();

	rep(i,1,n+1) {
		if(vis[i] == 0) {
			cout << "Sandro fails." << endl;
			return;
		}
	}

	for(int i : res) {
		cout << -i << " ";
	}

	return;



}

//Check for test cases
signed main(){

IOS

int test=1;
//cin>>test;

while(test--)
{
	solve();
}

return 0;
}
