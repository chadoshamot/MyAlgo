#include<iostream>
#include<vector>

using namespace std;

void swap(auto& a, auto& b){
    auto& t = a;
    a = b;
    b = t;
}

void reverse(vector<int>& a){
    int l = 0, r = a.size() - 1;
    while(l < r){
        swap(a[l], a[r]);
        l++;r--;
    }
}

void reverseStr(string& a){
    int l = 0, r = a.size() - 1;
    while(l < r){
        swap(a[l], a[r]);
        l++;r--;
    }
}
int main(){
    string a, b;
    std::cin >> a >> b;
    vector<int> cnt(a.size() + b.size(), 0);
    reverseStr(a);
    reverseStr(b);
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            int numa = a[i] - '0';
            int numb = b[j] - '0';
            cnt[i + j] += numa * numb;
        }
    }
    int carry = 0;
    vector<int> ans;
    for(int i=0; i<cnt.size(); i++){
        int sum = cnt[i] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    reverse(ans);
    // for(int i=0; i<ans.size(); i++){
    //     printf("%d", ans[i]);
    // }
    // cout << endl;
    int zeroId = -1;
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == 0)zeroId = i;
        else break;
    }
    //cout << "zeroid == " << zeroId << endl;
    if(zeroId == ans.size() - 1)printf("0\n");
    else{
        for(int i=zeroId + 1; i<ans.size(); i++){
            printf("%d", ans[i]);
        }
    }
    return 0;
}