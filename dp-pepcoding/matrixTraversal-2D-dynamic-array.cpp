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
int** dp;
int** mat;
int fun(int row, int col){

	if(row == 0 and col ==0){
		return dp[row][col] = mat[row][col];
	}

	if(row==0){
		return dp[row][col] = mat[row][col] + fun(row,col-1);
	}

	if(col == 0){
		return dp[row][col] = mat[row][col] + fun(row-1,col);
	}

	if(dp[row][col] != -1){
		return dp[row][col];
	}


	return dp[row][col] = mat[row][col] + min(fun(row-1,col) , fun(row,col-1));
}

int solve()
{

	int n,m;
	cin>>n>>m;

	//int **mat;
	mat = new int*[n];
	for(int i=0;i<n;i++){
		mat[i] = new int[m];
	}

	//int **dp;
	dp = new int*[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = new int[m+1];
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}

	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			dp[i][j] = -1;
		}
	}


	int ans = fun(n-1, m-1);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<ans<<endl;

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
