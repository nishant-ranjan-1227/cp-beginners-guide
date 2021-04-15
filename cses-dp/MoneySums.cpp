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


void solve()
{
    int n;
    cin >> n;

    read(a,n);

    int tot = 0;
    for(int i : a) tot += i;

    int dp[n+1][tot+1];
    mem(dp, 0);

    rep(i,0,n+1) dp[i][0] = 1;

    rep(i,1,n+1) {
        rep(j,1,tot+1) {
            if(a[i-1] <= j) {
                dp[i][j] = dp[i-1][j - a[i-1]] || dp[i-1][j];
            }

            else dp[i][j] = dp[i-1][j];
        }
    }

    // rep(i,0,n+1) {
    //     rep(j,0,tot+1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     nl;
    // }


    vec ans;
    rep(j,1,tot+1) {
        if(dp[n][j]) ans.pb(j);
    }

    int sz = ans.size();
    prinl(sz);
    write(ans, sz);


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
