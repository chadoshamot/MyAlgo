#include<iostream>
#include<vector>

using namespace std;

int head = -1, idx = 0, tail = -1;
vector<int> val(100002, 0);
vector<int> nextLeft(100002, 0);
vector<int> nextRight(100002, 0);
void init(){
    head = 0;
    tail = 1;
    idx = 2;
    nextLeft[tail] = head;
    nextRight[tail] = -1;
    nextLeft[head] = -1;
    nextRight[head] = tail;
}

void insert(int x, bool isRight){
    val[idx] = x;
    if(!isRight){
        int cur = nextRight[head];
        nextLeft[idx] = head;
        nextRight[idx] = cur;
        nextRight[head] = idx;
        nextLeft[cur] = idx;
    }
    else{
        int cur = nextLeft[tail];
        nextLeft[idx] = cur;
        nextRight[idx] = tail;
        nextLeft[tail] = idx;
        nextRight[cur] = idx;
    }
    idx++;
}

void deleteAfterK(int k){
    k++;
    int left = nextLeft[k];
    int right = nextRight[k];
    nextLeft[right] = left;
    nextRight[left] = right;
}

void insertAfterK(int k, int x, bool isRight){
    val[idx] = x;
    k++;
    if(!isRight){
        int left = nextLeft[k];
        nextLeft[idx] = left;
        nextLeft[k] = idx;
        nextRight[left] = idx;
        nextRight[idx] = k;
    }
    else{
        int right = nextRight[k];
        nextRight[idx] = right;
        nextRight[k] = idx;
        nextLeft[right] = idx;
        nextLeft[idx] = k;
    }
    idx++;
}

int main(){
    int m;
    std::cin >> m;
    init();
    //std::cout << "m == " << m << std::endl;
    for(int i=0; i<m; i++){
        string op;
        std::cin >> op;
        int k, x;
        if(op == "L"){
            std::cin >> x;
            insert(x, false);
        }
        if(op == "R"){
            std::cin >> x;
            insert(x, true);
        }
        if(op == "D"){
            std::cin >> k;
            deleteAfterK(k);
        }
        if(op == "IL"){
            std::cin >> k >> x;
            insertAfterK(k, x, false);
        }
        if(op == "IR"){
            std::cin >> k >> x;
            insertAfterK(k, x, true);
        }
    }
    for(int i = nextRight[head]; i != 1; i = nextRight[i]){
        std::cout << val[i] << " ";
    }
    return 0;
}