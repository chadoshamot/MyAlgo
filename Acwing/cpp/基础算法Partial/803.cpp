#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first)return a.second < b.second;
    else return a.first < b.first;
}
int main(){
    int n;
    std::cin >> n;
    vector<pair<int, int>>a(n);
    for(int i=0; i<n; i++){
        int l, r;
        std::cin >> l >> r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end(), cmp);
    int num = 1, cur_l = a[0].first, cur_r = a[0].second;
    for(int i=1; i<n; i++){
        int l = a[i].first, r = a[i].second;
        if(l <= cur_r){
            cur_r = cur_r > r ? cur_r : r;
        }
        else{
            cur_l = l; cur_r = r;
            num++;
        }
    }
    std::cout << num << std::endl;
    
    return 0;
}