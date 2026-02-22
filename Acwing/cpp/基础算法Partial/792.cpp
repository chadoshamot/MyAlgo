#include<iostream>
#include<vector>

using namespace std;

void swapStr(string& a, string& b){
    string t = a;
    a = b;
    b = t;
}

void swap(auto& a, auto& b){
    auto t = a;
    a = b;
    b = t;
}
void reverse(string& a){
    int l = 0, r= a.size() - 1;
    while(l < r){
        swap(a[l], a[r]);
        l++;r--;
    }
}
int main(){
    string a, b;
    std::cin >> a >> b;
    if(a.size() < b.size()){
        printf("-");
        swapStr(a, b);
    }
    if(a.size() == b.size()){
        for(int i=0; i<a.size(); i++){
            if(a[i] > b[i])break;
            if(a[i] < b[i]){
                printf("-");
                swapStr(a, b);
                break;
            }
        }
    }
    reverse(a);
    reverse(b);

    int borrow = 0;
    string ans = "";
    for(int i=0; i<a.size(); i++){
        int numa = a[i] - '0';
        int numb = i < b.size() ? b[i] - '0' : 0;
        numa -= borrow;
        if(numa < numb){
            numa += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        int rest = numa - numb;
        ans += rest + '0';
    }
    reverse(ans);
    //cout << "cur ans == " << ans << endl;
    int zeroId = -1;
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == '0')zeroId = i;
        else break;
    }
    if(zeroId == ans.size() - 1)printf("0\n");
    else if(zeroId == -1)std::cout << ans << std::endl;
    else{
        for(int i=zeroId + 1; i<ans.size(); i++){
            printf("%d", ans[i] - '0');
        }
    }
    return 0;
}