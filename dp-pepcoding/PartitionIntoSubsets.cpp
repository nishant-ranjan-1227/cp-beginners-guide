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
/*  
    Partition into subsets.

    ex. =  partion 5 numbers in 3 subsets -> fun(5,3)

    case1 -> If we know how to partition 4 num in 2 sunsets. We can just leave 5 as single element
                in a new subset. So we will have 5 eleemnts and 3 subsets.
            So, n1 = fun(4,2)

    Case2 -> Ways to partion 4 into 3 subsets
                12 3 4 -> 125 3 4 , 12 35 4 , 12 3 45

                1 23 4 -> 15 23 4 , 1 235 4 , 1 23 45

                1 2 34 -> ...

                13 2 4

                14 2 3

                24 1 3

                We have 6 ways to partition 4 into 3 and for every way we can keep 5 in 3 ways.
            So, n2 = fun(4,3)*3





 */


ll n,k;
ll dp[1005][1005];

ll fun(ll n, ll k){

    if(dp[n][k] != -1){
        return dp[n][k];
    }

    if(n==k){
        return dp[n][k] = 1;
    }

    if(n < k){
        return dp[n][k] = 0;
    }

    if(k==1){
        return dp[n][k] = 1;
    }

    ll n1 = fun(n-1,k)*k;
    ll n2 = fun(n-1,k-1);
    return dp[n][k] =  n1+n2;
}

int solve()
{

    cin>>n>>k;
    mem(dp,-1);


    ll ans = fun(n,k);
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
