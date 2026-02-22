#include<iostream>
#include<vector>

using namespace std;

int main(){
    string a;
    int b;
    std::cin >> a >> b;
    vector<int> ans;
    int num = 0;
    for(int i=0; i<a.size(); i++){
        int cur = a[i] - '0';
        num = num * 10 + cur;
        ans.push_back(num / b);
        num = num % b;
    }
    int zero = -1;
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == 0)zero = i;
        else break;
    }
    if(zero == ans.size() - 1)printf("0");
    else{
        for(int i=zero + 1; i<ans.size(); i++){
            std::cout << ans[i];
        }
    }
    std::cout << std::endl;
    std::cout << num << std::endl;
    return 0;
}