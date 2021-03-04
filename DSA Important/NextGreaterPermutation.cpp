
// Step 1 - From right to left find the first i such that s[i] < s[i+1]
// Step 2 - Again right to left find the first j such that s[j] > s[i]
// Step 3 - Swap s[i] and s[j] and sort rest of the elements.


int solve(int n) {
    string s = to_string(n);
    int len = s.length();

    for(int i=len-2;i>=0;i--) {
        if(s[i] < s[i+1]) {
            for(int j=len-1;j>i;j--) {
                if(s[j] > s[i]) {
                    swap(s[i], s[j]);
                    sort(s.begin()+i+1, s.end());
                    int ans = stoi(s);
                    return ans;
                }
            }
        }
    }

    sort(s.begin(), s.end());
    int ans = stoi(s);
    return ans;
}
