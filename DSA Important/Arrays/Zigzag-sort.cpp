#include <bits/stdc++.h>
using namespace std;

/*
We can convert in O(n) time using an Efficient Approach.
The idea is to Maintain a flag for representing which order(i.e. < or >) currently we need. 
If the current two elements are not in that order then swap those elements otherwise not.
*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    bool fg = true;

    for(int i=0;i<n-1;i++) {
        if(fg) {
            if(a[i+1] < a[i]) // next ele greater hona chahiye but galti se smaller hua toh swap.
            {
                swap(a[i], a[i+1]);
            }
        }

        else 
        {
            if(a[i+1] > a[i]) {
                swap(a[i],a[i+1]);
            }
        }

        fg = !fg;
    }

    for(auto i : a) {
        cout << i << " ";
    } 

}
