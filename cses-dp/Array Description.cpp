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

const int N = 1e5+5;
const int mod = 1e9+7;

/*

It is very important to correctly define the array. We assume that for the prev idx
all the arrays include are good and end with a perticular value.
    
 dp[idx][num] --> number of ways to make aaray such that a[idx] = num and 1...idx is a valid array
 if a[idx] is fixed = k;
        dp[idx][all except k] = 0;
        dp[idx][k] = a[idx-1][k-1] + a[idx][k] + a[idx]]k+1];

if a[idx] = 0 -> not fixed
    for j 1...m find dp[idx][j]


*/




void solve()
{
    int n,m;
    cin >> n >> m;
    
    vec a(n+1);
    rep(i,1,n+1) cin >> a[i];

    int dp[n+5][m+5];
    mem(dp, 0);


    //initialise for idx 1
    if(a[1] == 0) {
        rep(j,1,m+1) {
            dp[1][j] = 1;
        }
    }

    else {
        dp[1][a[1]] = 1;
    }

    rep(i,2,n+1) {
        if(a[i] != 0) {
            dp[i][a[i]] += dp[i-1][a[i]-1]%mod;
            dp[i][a[i]] += dp[i-1][a[i]]%mod;
            dp[i][a[i]] += dp[i-1][a[i]+1]%mod;

        }

        else {
            rep(j,1,m+1) {
                dp[i][j] += dp[i-1][j-1]%mod;
                dp[i][j] += dp[i-1][j]%mod;
                dp[i][j] += dp[i-1][j+1]%mod;
            }
        }
    }

    int ans = 0;
    rep(j,1,m+1) {
        ans += dp[n][j]%mod;
    }

    cout << ans%mod;




}

//Check for test cases
signed main(){


int test=1;
//cin>>test;

while(test--)
{
    solve();
}

return 0;
}
