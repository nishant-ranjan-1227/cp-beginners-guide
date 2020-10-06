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

/*  Min Cost in maze traversal.
	This is a simple dp problem but there is a very important thing to learn here.
	the different ways we can declare a 2-D array. 
	
	To declare a 2D array n x m size;
	int **mat;
	mat = new int*[n];
	for(int i=0;i<10;i++){
		mat[i] = new int[m];
	}

	To declare a 2D vector of n x m size
	vector<vector<int> mat(n, vector<int>(m, -1));

	Later in the function we need to pass this by reference using & operator.

*/

int** mat;
int** dp;
int n,m;
int fun(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];

	if(j==0) return dp[i][j] = mat[i][j];

	if(i==0) return dp[i][j] = mat[i][j] + max(fun(i,j-1), fun(i+1,j-1));

	if(i==n-1) return dp[i][j] = mat[i][j] + max(fun(i-1,j-1), fun(i, j-1));

	return dp[i][j] = mat[i][j] + max({fun(i-1,j-1), fun(i,j-1), fun(i+1,j-1)});
}
int solve()
{
	//int n,m;
	cin>>n>>m;

	mat = new int*[n];
	for(int i=0;i<n;i++){
		mat[i] = new int[m];
	}

	dp = new int*[n];
	for(int i=0;i<n;i++){
		dp[i] = new int[m];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j] = -1;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}

	int ans =0;
	for(int j=m-1,i=0;i<n;i++){
		int tm = fun(i,j);
		ans = max(ans, tm);
	}

	cout<<ans;

	

	return 0;
}



int main()
{

int test;
test = 1;
//cin>>test;

while(test--)
{
	solve();
}

    
return 0;
}
