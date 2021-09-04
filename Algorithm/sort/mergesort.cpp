#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> left,vector<int> right);
vector<int> sort(vector<int> v);
int main(void) {
    vector<int>test;
    test.push_back(30);
    test.push_back(5);
    test.push_back(3);
    test.push_back(7);
    test.push_back(4);
    test.push_back(8);
    test.push_back(10);
    test.push_back(20);
    test.push_back(11);
    test.push_back(25);
    test.push_back(13);
    test=sort(test);
    for(int i=0;i<11;i++) {
        std::cout << test[i] << " ";
    }
    return 0;
}
vector<int> sort(vector<int> v) {
    int m=v.size();
    if(m<=1) return v;
    vector<int> left,right;
    for(int i=0;i<m/2;i++) {
        left.push_back(v[i]);
    }
    for(int i=m/2;i<m;i++) {
        right.push_back(v[i]);
    }
    left=sort(left);
    right=sort(right);
    return merge(left,right);
}

vector<int> merge(vector<int> left ,vector<int> right) {
    vector<int> temp;
    int amount=left.size()+right.size(),i=0,j=0;
    while(amount>0) {
        if(i<left.size()&&j<right.size()) {
            if(left[i]<right[j]) {
                temp.push_back(left[i]);
                i++;
            }
            else if(left[i]>right[j]) {
                temp.push_back(right[j]);
                j++;
                }
                else {
                    temp.push_back(right[j]);
                    temp.push_back(left[i]);
                    i++;
                    j++;
                    }
        }
        else {
            if(i<left.size()) {
                while(i<left.size()) {
                    temp.push_back(left[i]);
                    i++;
                }
                amount=0;
            }
            else {
                 while(j<right.size()) {
                    temp.push_back(right[j]);
                    j++;
                }
                amount=0;

            }
        }
        amount--;
    }
    return temp;
}