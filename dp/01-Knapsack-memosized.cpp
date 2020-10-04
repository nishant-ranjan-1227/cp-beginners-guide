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

For every item we have two choices
	1 -> We can include it in the bag if its weight is less than maximum capaciy of the bag.
	2 -> We do not include it.

We will write a recursive code for this.
		



*/
vec weight;
vec profit;
ll W; //max-capacity
int dp[100][100];

ll maxProfitKnapsack(ll i, ll remaining_weight){
	if(i < 0 || remaining_weight == 0) return 0;

	if(dp[i][remaining_weight] != -1){
		return dp[i][remaining_weight];
	}

	//case1 -> if we do not include this item.
	ll res1 = 0;
	res1 = maxProfitKnapsack(i-1, remaining_weight);


	//case2 -> if we include
	//check if its wight is less than remaining weight.
	ll res2 = 0;
	if(weight[i] <= remaining_weight){
		
		res2  = profit[i] + maxProfitKnapsack(i-1, remaining_weight - weight[i]);
	}

	ll max_profit = max(res1, res2);
	dp[i][remaining_weight] = max_profit;
	return max_profit; 
}

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

	mem(dp,-1);

	ll res = maxProfitKnapsack(n-1, W);
	cout<<res<<endl;

	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}



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