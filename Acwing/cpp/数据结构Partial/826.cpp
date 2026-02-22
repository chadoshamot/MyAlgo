#include<iostream>
#include<vector>

using namespace std;

int head = -1, idx = 0;
vector<int> val(100002, 0);
vector<int> ne(100002, 0);

void init(){
    head = -1;
    idx = 0;
}

void insertHead(int x){
    val[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void deleteAfterK(int k){
    if(k == 0){
        head = ne[head];
        return;
    }
    k--;
    int cur = ne[k];
    if(cur == -1)return;
    ne[k] = ne[cur];
}

void insertAfterK(int k, int x){
    k--;
    val[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
int main(){
    int m;
    std::cin >> m;
    init();
    for(int i=0; i<m; i++){
        char x;
        std::cin >> x;
        if(x == 'H'){
            int num;
            std::cin >> num;
            insertHead(num);
        }
        if(x == 'D'){
            int k;
            std::cin >> k;
            deleteAfterK(k);
        }
        if(x == 'I'){
            int k, num;
            std::cin >> k >> num;
            insertAfterK(k, num);
        }
    }
    for(int i = head; i != -1; i = ne[i]){
        std::cout << val[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}