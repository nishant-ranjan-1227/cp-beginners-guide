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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}


const int inf = 10e7;


void solve()
{
    int n,x;
    cin >> n >> x;

    vec coins(n+1);
    rep(i,1,n+1) cin >> coins[i];
  
    // here dp[sum] store the minimum number of coins req to get this sum with just the coins till now

    int prev[x+1]; //store the minimum for each sum without the current coin
    int cur[x+1];  // store the minimum coins when we include the current coin

    //when i = 0 set all the prev value to inf;
    rep(i,0,x+1) {
        prev[i] = inf;
    }

    rep(item,1,n+1) {
        cur[0] = 0;
        rep(sum, 1, x+1) {
            //include item with condition
            if(coins[item] <= sum) {
                cur[sum]= min(prev[sum], 1+cur[sum - coins[item]]);
            }
            //do not include -> just copy with prev
            else cur[sum] = prev[sum];
        }

        // write(prev, x+1); nl;
        // write(cur, x+1); nl;

        rep(i,0,x+1) prev[i] = cur[i];
    }


    int ans = cur[x];
    if(ans == inf) {
        cout << -1;
    }

    else cout << ans;

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
