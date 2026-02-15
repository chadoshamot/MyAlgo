#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n, 0);
    for(int i=0; i<n; i++)std::cin >> a[i];
    vector<int> post(n, 0);
    post[0] = a[0];
    for(int i=1; i<n; i++)post[i] = a[i] - a[i - 1];
    for(int i=0; i<m; i++){
        int l, r, c;
        std::cin >> l >> r >> c;
        post[l - 1] += c;
        if(r < n)post[r] -= c;
    }
    a[0] = post[0];
    for(int i=1; i<n; i++){
        a[i] = a[i - 1] + post[i];
    }
    for(int i=0; i<n; i++)std::cout << a[i] << " ";

    return 0;
}