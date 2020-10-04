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
ll N = 1000;




/* 
Subset sum problem.
To print if subset of given sum is possile of not.



*/
vec input;
ll sum; //max-capacity
int dp[100][100];

ll subsetSum(ll i, ll remaining_sum){
	if(i==0) return 0;

	if(remaining_sum == 0) return 1;
	ll j = remaining_sum;
	if(dp[i][j] != -1) return dp[i][j];

	//Case 1 ->not include
	ll res1 = subsetSum(i-1, j);

	//Case2
	ll res2 =0;
	if(j >= input[i-1]){
		 res2 = subsetSum(i-1, j-input[i-1]);
	}

	if(res1==1 || res2 ==1){
		dp[i][j] = 1;
		return 1;
	}

	else
	{
		dp[i][j]=0;
		return 0;
	}

	return 0;
}

int solve()
{
	ll n;
	cin>>n;
	cin>>sum;

	
	rep(i,0,n){
		ll x;
		cin>>x;
		input.push_back(x);
	}

	mem(dp,-1);

	ll res =subsetSum(n, sum);
	cout<<res<<endl;


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