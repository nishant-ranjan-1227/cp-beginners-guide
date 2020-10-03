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




/* 
Ques - to store all the unique subsets of a string in a set.

We use the recursion input output method. The base case is when the input becomes empty. 
Each time we take the decision if we want to add the first character of the input string to the output string or not.
Not
 input - abc
	
	output - 	" "
				a
				ab
				abc
				ac
				b
				bc
				c

*/

set<string> subsets;

void find_all_subsets(string in, string out){
	if(in.length()==0){
		subsets.insert(out);
		return;
	}

	string out1 = out;
	string out2 = out;

	out2.push_back(in[0]);
	in.erase(in.begin()+0);

	find_all_subsets(in, out1);
	find_all_subsets(in, out2);

	return;
}
int solve()
{
	subsets.clear();
	string s;
	cin>>s;
	string out = "";
	find_all_subsets(s, out);

	for(auto subset : subsets){
		cout<<subset<<endl;
	}


   return 0;

}



int main()
{
int test;
test = 1;
//cin>>test;

while(test--)
{
	solve();
}

    
return 0;
}