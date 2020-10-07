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
     Target sum.
     Here also we have two choices for every item.
     Case1 -> do not include the item and check that if the target sum can be achieved without the item.
     Case2 -> include the item "i" and check that if "target - arr[i]" can be achevied with "i-1".

     Here the idx shows the number of the item we are looking at.

     Base conditions ->
        1. If the target sum becomes zero that we can surely achieve it.
        2. If we do not have any item in the list we cannot get any sum.
*/


vec a;
int** dp;
int fun(int idx, int target){
    if(idx <= 0){
        return 0;
    }

    if(target == 0){
        return 1;
    }

    if(dp[idx-1][target] != -1 ){
        return dp[idx-1][target];
    }

    //Case1 -> do not include
    int case1 = fun(idx-1, target);

    //Case2 -> we inlcude the item.
    int case2 = 0;
    if(target >= a[idx-1]){
        case2 = fun(idx-1, target - a[idx-1]);
    }

    if(case1 == 1 or case2 == 1) return dp[idx-1][target] = 1;
    return dp[idx-1][target] = 0;
}

int solve()
{
    ll n;
    cin>>n;

    rep(i,0,n){
        ll x;
        cin>>x;
        a.pb(x);
    }
    
     ll target;
    cin>>target;

    dp = new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i] = new int[target+1];
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            dp[i][j] = -1;
        }
    }

    
  

    int ans = fun(n, target);

    if(ans) cout<<"true";
    else cout<<"false";



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
