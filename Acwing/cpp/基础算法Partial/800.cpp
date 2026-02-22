#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m, x;
    std::cin >> n >> m >> x;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for(int i=0; i<n; i++)std::cin >> a[i];
    for(int i=0; i<m; i++)std::cin >> b[i];
    int a_index = n - 1, b_index = 0;
    while(a_index < n && b_index >= 0){
        if(a[a_index] + b[b_index] == x){
            std::cout << a_index << " " << b_index << std::endl;
            return 0;
        }
        else if(a[a_index] + b[b_index] < x){
            b_index++;
            //a_index++;
        }
        else {
            //b_index--;
            a_index--;
        }
    }
    std::cout << -1;
    return 0;
}