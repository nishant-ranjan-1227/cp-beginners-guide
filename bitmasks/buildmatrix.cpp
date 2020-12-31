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
const ll N = 500000+5;
const ll zero = 0;
const ll mod = 1e9+7;

vector<vector<bool>> binaryMatrix1;
vec totalSetBitSum(63,0);
vec powersOfTwo(63,0);

void fill_matrix(vec v,ll n) 
{

    rep(i,0,n) {
        ll x = v[i];
        vector<bool> temp(63,0);
        ll j = 0;
        while(x>0) {
            temp[j] = x&1;
            x = x>>1;
            j++;
        }

        binaryMatrix1.pb(temp);


    }
}

// total_number_of_elements_with_this_bit_set - totalSetBitSum
    

void calculateTotalBitSum(ll n) 
{
    rep(bit,0,63) {
        int cnt = 0;
        rep(ele,0,n) {
            if(binaryMatrix1[ele][bit]) cnt++;
        }
        totalSetBitSum[bit] = cnt;
    }
}

void calculatePowersOfTwo(ll n = 63) 
{
       powersOfTwo[0] = 1;
       rep(i,1,n) {
       powersOfTwo[i] = powersOfTwo[i-1]*2;
   } 
}

void emptyall()
{
    binaryMatrix1.clear();
    rep(i,0,63) {
        totalSetBitSum[i] = 0;
    }
}
    




void solve()
{
    ll n; cin >> n;
    read(a);

    emptyall();

    fill_matrix(a,n);
    calculateTotalBitSum(n);
    calculatePowersOfTwo();

    // for(auto it : binaryMatrix1) {
    //     for(auto u : it) {
    //         cout << u;
    //     }
    //     nl;
    //     nl;
    // }

    ll ans = 0;
    

    rep(i,0,n) {
        ll andsum = 0;
        ll orsum = 0;
        rep(j,0,61) {
           
            if(binaryMatrix1[i][j]) {
                andsum += totalSetBitSum[j]*(powersOfTwo[j]%mod)%mod;
                andsum %= mod;

                orsum += n*(powersOfTwo[j]%mod)%mod;
                orsum %= mod;

            }

            else
            {
                orsum += totalSetBitSum[j]*(powersOfTwo[j]%mod)%mod;
                orsum %= mod;
            }

            
        }

       

        ans += (andsum*orsum)%mod;
        ans %= mod;


    }


    cout << ans%mod << endl;

    
}



//Check for test cases
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int test=1;
cin>>test;



while(test--)
{
    solve();
}
 return 0;
}
