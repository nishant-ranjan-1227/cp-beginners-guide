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
 
const int N = 1005;
const int mod = 1e9+7;
 
int n;
vector<string> v(N);
int dp[N][N];
 
void solve()
{
    v.clear();
    cin >> n;
    rep(i,0,n) cin >> v[i];
 
    mem(dp, 0);
 
    if(v[0][0] == '*') {
        cout << 0;
        return;
    }
 
    dp[0][0] = 1;
 
    rep(i,0,n) {
        rep(j,0,n) {
            if(i-1 >= 0) {
 
                if(v[i-1][j] != '*' and v[i][j] != '*')
                dp[i][j] += dp[i-1][j]%mod;
            }
 
            if(j-1 >= 0) {
 
                if(v[i][j-1] != '*' and v[i][j] != '*')
                dp[i][j] += dp[i][j-1]%mod;
            }
        }
    }
 
    int ans = dp[n-1][n-1];
    prinl(ans%mod);
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
