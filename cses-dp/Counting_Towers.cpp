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

const int N = 1e6+5;
const int mod = 1e9+7;

int dp[2][N];

void solve()
{
    int n;
    cin >> n;
    int ans = (dp[0][n] + dp[1][n])%mod;

    cout << ans % mod << endl;
}

//Check for test cases
signed main(){

dp[0][1] = 1;
dp[1][1] = 1;
dp[0][2] = 5;
dp[1][2] = 3;

rep(i,3,N) {
    dp[0][i] = (dp[0][i-1]*4 + dp[1][i-1]*1)%mod;

    dp[1][i] = (dp[0][i-1]*1 + dp[1][i-1]*2)%mod;
}


int test=1;
cin>>test;

while(test--)
{
    solve();
}

return 0;
}
