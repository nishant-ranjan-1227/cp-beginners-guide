#include <bits/stdc++.h>
using namespace std;
#define int          int
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

// template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
// template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
// template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
// template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}


/*
BFS on 2D grid

*/

const int N = 15;
string s1;
string s2;
int x1,yy1,x2,y2;
int ans;
bool gexit;
int vis[N][N];

bool isvalid(int x,int y) {
	if(x < 1 || x > 8) return false;
	if(y < 1 || y > 8) return false;
	if(vis[x][y]) return false;
	return true;
}

int dx[] = {-2,-1,+1,+2,+2,+1,-1,-2};
int dy[] = {+1,+2,+2,+1,-1,-2,-2,-1};

void bfs(int x,int y) {

	queue<pairs> q;
	q.push({x,y});
	int level = -1;
	while(!q.empty() and !gexit) {

		int sz = q.size();
		level += 1;

		for(int i=0;i<sz;i++) {
			pair<int,int> p = q.front();
		    q.pop();
		    int curx = p.fi;
		    int cury = p.se;
		    vis[curx][cury] = 1;

		    if(curx == x2 and cury == y2) {
		    	ans = level;
		    	gexit = true;
		    	break;
		    }

		    for(int j=0;j<8;j++) {
		    	int newx = curx+dx[j];
		    	int newy = cury+dy[j];
		    	if(isvalid(newx,newy)) {
		    		q.push({newx,newy});
		    		//cout << " l" << level << " " << newx << " " << newy << endl;
		    	}
		    }
		}
		


	}
}


void solve() {

	
	string s1,s2;
	cin >> s1 >> s2;
	 x1 =  s1[0] - 'a' +1;
	 yy1 = s1[1] - '0';
	 x2 = s2[0]  - 'a' + 1;
	 y2 = s2[1] - '0';

	// debug(x1,yy1);
	// debug(x2,y2);

	gexit = false;

	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			vis[i][j] = 0;
		}
	}

	bfs(x1,yy1);

	if(vis[x2][y2] == 0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}





}

//Check for test cases
signed main(){

IOS

int test=1;
cin>>test;

while(test--)
{
	solve();
}

return 0;
}
