#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

void getNext(vector<int>& next, string p){
    int j = 0;
    next[0] = j;
    // aabaaf
    for(int i=1; i<p.size(); i++){
        while(j > 0 && p[i] != p[j]){
            j = next[j - 1];
        }
        if(p[i] == p[j])j++;
        next[i] = j;
    }
}

void kmp(string p, string s){
    vector<int> next(p.size(), 0);
    getNext(next, p);
    int j = 0;
    for(int i=0; i<s.size(); i++){
        while(j > 0 && s[i] != p[j]){
            j = next[j - 1];
        }
        if(s[i] == p[j])j++;
        if(j == p.size()){
            printf("%d ", i - p.size() + 1);
            j = next[j - 1];
        }
    }
}

int main(){
    int n, m;
    string p, s;
    std::cin >> n;
    std::cin >> p;
    std::cin >> m;
    std::cin >> s;
    kmp(p, s);
    return 0;
}