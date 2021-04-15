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

//=============================================================

//   1. max and min fubctions
int max(int a, int b) { return a>b ? a:b; }
int min(int a, int b) { return a<b ? a:b; }

// 2. gcd
int gcd(int a,int b) {return (b==0) ? a : gcd(b,a%b); }

// 3. lcm
int lcm(int a, int b) { return a/gcd(a,b)*b; }

// 4. Extended Euclid
int gcd(int a,int b,int &x,int &y) {
    if (b == 0) {
    x = 1; y = 0; return a; }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b); return d;
}

// 5. If prime
bool prime(int n) {
    if (n<2) return false;
    if (n<=3) return true;
    if (!(n%2) || !(n%3)) return false;
    for (int i=5;i*i<=n;i+=6)
    if (!(n%i) || !(n%(i+2))) return false;
    return true;
}

// 6. a pow b
int pw(int b, int p) {
    int r = 1;
    while(p) {
    if (p & 1) r *= b;
    p >>= 1; b *= b;
    }
    return r;
}

// 7. a pow b mod p
int powmod(int a,int b,int p){
    int r=1; a %= p;
    while(b) {
        if(b&1) r = (r*a)%p;
        b>>=1; a = (a*a)%p;
    }
    return r;
}


//8. Inverse modulo
// Require Extended Euclidean
int modInv(int a,int m){
int x, y, g = gcd(a, m, x, y);
if (g != 1) return -1;
else return (x%m + m) % m;
}

//9. SIEVE (IMP) 
// Just call sieve() in the main func
// primes contains all Prime numbers
// isprime[i] represents smallest prime number which
//divides the number i
const int mx = 1<<20;
int isprime[mx];
vector<int> primes;

void sieve() {
for(int i=2 ; i < mx ; ++i) {
if(isprime[i]>0) continue;
isprime[i] = 1; int j=i*i;
while(j< mx) {
if(isprime[j]==0) isprime[j]=i;
j+=i;
}
primes.push_back(i);
}
}

//10. Number of Divisors
//Require Sieve
int numDiv(int n){
int pf_idx = 0, pf = primes[pf_idx], ans = 1;
while(pf * pf <= n){
int power = 0;
while(n % pf == 0) { n /= pf; power++; }
ans *= (power+1);
pf = primes[++pf_idx];
}
if(n != 1) ans*=2;
return ans;
}


//11. Sum of divisors
// Require Sieve and pw
int sumDiv(int n){
int pf_idx = 0, pf = primes[pf_idx], ans = 1;
while(pf * pf <= n){
int power = 0;
while(n % pf == 0) { n /= pf; power++; }
ans *= (pw(pf, power + 1) - 1)/(pf-1);
pf = primes[++pf_idx];
}
if(n != 1) ans *= (pw(n, 2) - 1)/(n-1);
return ans;
}

//12. FACTORS : Return a set of all the factors
set<int> factor(int n) {
    set<int> fact;
    for(int i = 1 ; i*i <= n ; ++i)
    if(n%i == 0)
    fact.insert(i) , fact.insert(n/i);
    return fact;
}

//13. FACTORIAL pre calculation
//Just call the functo=ion in main
// Require Inverse Modulo
const int mx1 = 1<<20;
int fact[mx1] , ifact[mx1];
void preCalcFac(int m){
    fact[0] = 1;
    for(int i = 1; i < mx1; ++i)
    fact[i] = (fact[i - 1] * i) % m;
    ifact[mx1 - 1] = modInv(fact[mx1 - 1], m);
    for(int i = mx1-2; i >= 0 ; --i)
    ifact[i] = (ifact[i + 1] * (i + 1)) % m;
}


//14. nCr
int nCr(int n,int r){
int res = n;
for(int i = 2 ; i<=r ; ++i){
res*=(n-i+1); res/=i;
}
return res;
}


//15. nCr mod
//call preCalcFac before in main;
// Require Pre-Calculation of Factorial
int nCr(int n,int r,int m) {
if (r==0) return 1;
int ans = (fact[n]*ifact[r])%m;
ans = (ans*ifact[n-r])%m;
return ans;
}


//16. Euler’s Totient Function
// the positive integers less than or equal to n that
//are relatively prime to n.
int phi (int n){
int result = n;
for (int i=2; i*i<=n; ++i)
if(n%i==0){
while(n%i==0) n /= i;
result -= result / i;
}
if (n > 1) result -= result / n;
return result;
}



//==============================================================
// MODULUS

int modAdd(int a, int b, int p) {
    int res;
    if(a >= p) a -= p;
    if(b >= p) b -= p;

    res = (a + b);
    if(res < 0) res += p;
    if(res >= p) res -= p;

    return res;
}


int modMul(int a, int b, int p) {
    int res;
    if(a >= p) a -= p;
    if(b >= p) b -= p;

    res = a*b;
    if(res < 0) res += p;
    if(res >= p) res -= p;

    return res;
}


//a - b % mod
int modSub(int a,int b,int p) {
    int res;
    if(a >= p) a -= p;
    if(b >= p) b -= p;

    res = (a - b + p);
    if(res >= p) res -= p;

    return res;
}


//DIVIDE
// Reqires 4 7 and 8 extended euclid powmod and modInv
int modDiv(int a,int b,int p) {
    if(a >= p) a-= p;

    int inv = modInv(b,p);
    return (a*inv)%p;
}











//===========================================================
  


const int mod = 1e9+7;

void solve()
{
   int n;
   cin >> n;

   int tot = n*(n+1)/2;

   if(tot % 2 ==  1) {
    cout << 0;
    return;
   }

   int target = tot/2;

   //dbug(target);

   int prev[target+1] = {0};
   int cur[target+1] = {0};
   
   prev[0] = 1;


   rep(i,1,n+1) {
    cur[0] = 1;
    rep(j,1,target+1) {
        if(i <= j) {
            cur[j] = (prev[j-i] + prev[j])%mod;
        }

        else {
            cur[j] = prev[j]%mod;
        }
    }

    rep(j,0,target+1) prev[j] = cur[j];
   }

   int ans = cur[target];
   ans = modDiv(ans, 2LL, mod);

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
