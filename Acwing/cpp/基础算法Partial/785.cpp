#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;
int getRandom(int min, int max){
    return (rand() % (max - min + 1) + min);
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void quickSort(vector<int>& arr, int l, int r){
    //双路快排
    if(l >= r)return;
    int x = arr[(l + r + 1) / 2], i = l - 1, j = r + 1;
    //i左边的都小于x，j右边的都大于x
    while(i < j){
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        if(i < j)swap(arr[i], arr[j]);
    }
    quickSort(arr, l, i - 1);
    //此时x不能取位置l的数，否则死循环
    //反例：1，2，最后一步递归一直在quickSort(0, 1)
    quickSort(arr, i, r);
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)scanf("%d", &arr[i]);
    quickSort(arr, 0, arr.size() - 1);
    for(int i=0; i<arr.size() - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[arr.size() - 1]);
    return 0;
}