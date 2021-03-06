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


/*
Basic code of dfs in a 2-D n x n grid;
*/

const int N = 1005;
int vis[N][N];
int n;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool isValid(int x,int y) {
	if(x < 1 || x > n) return false;
	if(y < 1 || y > n) return false;
	if(vis[x][y]) return false;
	return true;
}
void dfs(int x,int y)
{
	vis[x][y] = 1;
	cout << x << " " << y << endl;

	for(int i=0;i<4;i++) {
		if(isValid(x+dx[i],y+dy[i])) {
			dfs(x+dx[i],y+dy[i]);
		}
	}

	return;
}

void solve() {

	cin >> n;
	dfs(1,1);
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
