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

/*   
TWXFUABGBNLTBFNSUVQW
GPNJILFXJUIZPLTVUIB

*/


void solve()
{
    string a,b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    rep(i,0,n+1) {
        rep(j,0,m+1) {

            if(i == 0) dp[i][j] = j; //when s1 is empty, we just have to copy j elements of string s2
            else if(j == 0) dp[i][j] = i; // when s2 is empty, we just have to remove i elements present in s1.

            else {

            if(a[i-1] == b[j-1]) {

                dp[i][j] = dp[i-1][j-1];
            }

            else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                //case1 = dp[i][j-1] = when we insert an element in s1. 
                //After insertion, we calculate the dp[for the rest of s1(i)][for the rest of s2 other than the last element which is inserted in s1(j-1)].

                //case2 = dp[i-1][j] = when we remove element from s1. We calculate dp[rest of s1(i-1)][rest of s2(j)]

                //case3 = dp[i-1][j-1] = when element of s1 is replaced. 

                //calculate min of the three. 1 is added as each case counts to 1 operation
            }

        }
        }
    }

    int ans = dp[n][m];

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
