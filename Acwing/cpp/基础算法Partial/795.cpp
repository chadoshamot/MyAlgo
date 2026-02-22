#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    std::cin >> n >> m;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)scanf("%d", &v[i]);
    vector<int> prefix(n, 0);
    prefix[0] = v[0];
    for(int i=1; i<n; i++)prefix[i] = prefix[i - 1] + v[i];
    for(int i=0; i<m; i++){
        int l, r;
        std::cin >> l >> r;
        if(l == 1)std::cout << prefix[r - 1] << std::endl;
        else std::cout << prefix[r - 1] - prefix[l - 2] << std::endl; 
    }
    return 0;
}