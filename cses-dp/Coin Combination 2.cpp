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


const int inf = 10e7;
const int mod = 1e9+7;

/* 
Here for each coin we keep it only in the last position.


*/


void solve()
{
    int n,x;
    cin >> n >> x;

    vec coins(n+1);
    rep(i,1,n+1) cin >> coins[i];

    int prev[x+1];
    int cur[x+1];

    //when i = 0 there is no way to get any sum so set each value to 0;
    rep(i,0,x+1) {
        prev[i] = 0;
    }

    rep(item,1,n+1) {
        cur[0] = 1;
        rep(sum, 1, x+1) {
            //include item with condition
            if(coins[item] <= sum) {
                cur[sum] = (prev[sum] + cur[sum - coins[item]])%mod;;
            }

            else cur[sum] = prev[sum]%mod;
        }

        // write(prev, x+1); nl;
        // write(cur, x+1); nl;

        //nl;

        rep(i,0,x+1) prev[i] = cur[i];
    }


    int ans = cur[x];
    cout << ans%mod;

    return;


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
