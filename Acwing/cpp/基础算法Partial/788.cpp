#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

ll ans = 0;
/*
逆序对的个数非常大，输出的时候cout会自动根据数据类型调整输出
但printf就需要根据%lld来正确输出对应的格式
*/
void mergeSort(vector<int>& v, int l, int r){
    if(l >= r)return;
    int mid = l + (r - l) / 2; 
    mergeSort(v, l, mid);
    //cout << "l == " << l << " and r == " << mid << " and reverse num is : " << ans << endl;
    mergeSort(v, mid + 1, r);
    //cout << "l == " << mid + 1 << " and r == " << r << " and reverse num is : " << ans << endl;
    
    int i = l, j = mid + 1;
    vector<int> tmp;
    while(i <= mid && j <= r){
        if(v[i] < v[j]){
            //ans += r - j + 1;
            tmp.push_back(v[i]);
            i++;
        }
        else if(v[i] > v[j]){
            ans += mid - i + 1;
            tmp.push_back(v[j]);
            j++;
        }
        else if(v[i] == v[j]){
            tmp.push_back(v[i]);
            i++;
        }
    }
    while(i <= mid){
        tmp.push_back(v[i]);
        i++;
    }
    while(j <= r){
        tmp.push_back(v[j]);
        j++;
    }
    for(int k=l; k<=r; k++){
        v[k] = tmp[k - l];
    }
    return;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)scanf("%d", &v[i]);
    mergeSort(v, 0, v.size() - 1);
    cout << ans << endl;
    return 0;
}

/*
2 16 71 72 88
50 67 72 94

*/