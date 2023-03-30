#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& array, vector<int>& Larray, vector<int>& Rarray){
    int as = array.size();
    int ls = Larray.size();
    int rs = Rarray.size();
    int i,j,k;
    i=j=k=0;
    while(j<ls && k<rs){
        if(Larray[j] < Rarray[k]){
            array[i] = Larray[j];
            j++;
        } else {
            array[i] = Rarray[k];
            k++;
        }
        i++;
    }
    while(j<ls){
        array[i] = Larray[j];
        j++;
        i++;
    }
    while(k<rs){
        array[i] = Rarray[k];
        k++;
        i++;
    }
}

void mergeSort(vector<int>& array){
    if(array.size()<2){
        return;
    }
    int size = array.size();
    int mid = size/2;
    vector<int> le(mid);
    vector<int> ri(size-mid);
    for(int i=0; i<mid; i++){
        le[i] = array[i];
    }
    for(int i=mid; i<size; i++){
        ri[i-mid] = array[i];
    }
    mergeSort(le);
    mergeSort(ri);
    merge(array, le, ri);
}

int main(){
    vector<int> a = {1, 5, 3, 2, 6};
    mergeSort(a);
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
