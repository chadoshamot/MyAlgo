#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    std::cin >> n;
    vector<int> a(n, 0);
    vector<int> cnt(100002, 0);
    int j = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        std::cin >> a[i];
        cnt[a[i]]++;
        while(j <= i && cnt[a[i]] > 1){
            if(cnt[a[i]] > 1){
                cnt[a[j]]--;
                j++;
            }
        }
        ans = ans > (i - j + 1) ? ans : (i - j + 1);
    }
    std::cout << ans << std::endl;
    return 0;
}