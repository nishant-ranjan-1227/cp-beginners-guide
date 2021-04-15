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


void solve()
{
    int width, height;
    cin >> width >> height;

    int dp[height+1][width+1];

    dp[1][1] = 1;
    for(int i=1;i<=height;i++) {
        dp[i][1] = i;
    }

    for(int j=1;j<= width; j++) {
        dp[1][j] = j;
    }

    for(int i=2;i<=height;i++) {
        for(int j=2;j<=width;j++) {     
            if(i == j) {
                dp[i][j] = 1;
                continue;
            }

            int t = 1e9;
            for(int k=1;k<i;k++) {
                t = min(t, dp[k][j] + dp[i - k][j]);
            }

            for(int k=1;k<j;k++) {
                t = min(t, dp[i][k] + dp[i][j - k]);
            }

            dp[i][j] = t;
        }
    }

    // for(int i=1;i<=height;i++) {
    //     for(int j=1;j<=width;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     nl;
    // }

    int ans = dp[height][width] - 1;
    prinl(ans);
    


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
