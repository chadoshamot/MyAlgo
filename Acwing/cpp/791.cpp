#include<iostream>
#include<vector>
#include<cstring>
#include<string>


using namespace std;

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}
void reverse(string& a){
    int l = 0, r = a.size() - 1;
    while(l < r){
        swap(a[l], a[r]);
        l++;r--;
    }
}
int main(){
    string a, b;
    std::cin >> a >> b;
    reverse(a);
    reverse(b);
    int carry = 0;
    if(a.size() < b.size()){
        string t = a;
        a = b;
        b = t;
    }
    string ans;
    for(int i=0; i<a.size(); i++){
        int numa = a[i] - '0';
        int numb = i < b.size() ? b[i] - '0' : 0;
        int sum = numa + numb + carry;
        ans += (sum % 10) + '0';
        carry = sum / 10;
    }
    if(carry)ans.push_back(carry + '0');
    reverse(ans);
    std::cout << ans << std::endl;
    return 0;
}