#include<iostream>
#include<vector>

using namespace std;

void mergeSort(vector<int>& q, int l, int r){
    if(l >= r)return;
    int mid = l + (r - l) / 2;//下取整，否则报错
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    vector<int> tmp;
    int i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] < q[j]){
            tmp.push_back(q[i]);
            i++;
        }
        else if(q[j] < q[i]){
            tmp.push_back(q[j]);
            j++;
        }
        else if(q[i] == q[j]){
            tmp.push_back(q[i]);
            tmp.push_back(q[i]);
            i++;j++;
        }
    }
    while(i <= mid){
        tmp.push_back(q[i]);
        i++;
    }
    while(j <= r){
        tmp.push_back(q[j]);
        j++;
    }
    for(int k=l; k<=r; k++){
        q[k] = tmp[k - l];
    }
    return;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> q(n, 0);
    for(int i=0; i<n; i++)scanf("%d", &q[i]);
    mergeSort(q, 0, n - 1);
    for(int i=0; i<n; i++)printf("%d ", q[i]);
    return 0;
}