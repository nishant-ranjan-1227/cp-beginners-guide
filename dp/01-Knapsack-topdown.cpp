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
01 Knapsack.

Input : weight[] = {...}
		profit[] = {...}
		W = max capacity of the bag.

Output : MaxProfit we can get.

In bottum up approach or the recursive approach we call the function for the highest value and
it makes recursive calls for the smaller values.

The top-down approach is just the opposite.

We inisialize the dp for the base cases and then use the previous calculated values to calculate the next values 
till the highest value. Here is the imp to calculate all the smaller values.




*/
vec weight;
vec profit;
ll W; //max-capacity
ll dp[100][100];


int solve()
{
	ll n;
	cin>>n;
	cin>>W;

	
	rep(i,0,n){
		ll x;
		cin>>x;
		weight.push_back(x);
	}

	rep(i,0,n){
		ll x;
		cin>>x;
		profit.push_back(x);
	}

	//mem(dp,-1);

	/*  i-> items j->remaining weight
		when i=0 profit will be zero.
		when j=0 profit will be zero.
			
	*/

	rep(i,0,n+1){
		rep(j,0,W+1){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
		}
	}

	rep(i,1,n+1){
		rep(j,1,W+1){
			if(j >= weight[i-1]){
				dp[i][j] = max(dp[i-1][j], profit[i-1]+dp[i-1][j-weight[i-1]]);
			}

			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}


	rep(i,0,n+1){
		rep(j,0,W+1){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	ll ans = dp[n][W];
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