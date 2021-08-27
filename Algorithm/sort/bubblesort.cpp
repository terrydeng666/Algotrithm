#include <bits/stdc++.h>

int main(void) {
    int a[]={30,5,3,7,4,8,10,20,11,25,13};
    for(int i=0;i<11;i++){
        for(int j=0;j<10-i;j++) {
            if(a[j+1]<a[j]) {
                int swap=0;
                swap=a[j+1];
                a[j+1]=a[j];
                a[j]=swap;
            }
        }
    }    
    for(int i=0;i<11;i++) {
        std::cout << a[i] << " ";
    }
    //test
    return 0;
}