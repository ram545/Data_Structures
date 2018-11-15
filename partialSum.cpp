/*  Given a sequence of elements and asked about the sum of part of its elements(without any modifying queries)
*   Given range l,r (l!=r) and (1 <= l < r <= N)
*   Algorithm:
*   1. Build an array in such a way that a[i] contains sum of all elements from 0 to i.
*   2. So for a given range(l,r) sum of parts = a[r] - a[l] 
*/

#include<iostream>
#include<cstring>

int main(){
    int N,*Arr,*sumArr,testCase,i,l,r;
    std::cin >> testCase;
    std::cin >> N;
    Arr = new int[N];
    sumArr = new int[N];
    memset(sumArr,0,N);
    for(i=0;i<N;i++){
        std::cin >> Arr[i];
        if(i==0)
            sumArr[i] = Arr[i];
        else
            sumArr[i] = Arr[i] + sumArr[i-1];
        std::cout << sumArr[i] << " " << i << std::endl;
    }
    while(testCase--){
        std::cin >> l >> r;
        if( (l == 1 && r == N) || l==1)
            std::cout << sumArr[r-1] << std::endl;
        else
            std::cout << sumArr[r-1]-sumArr[l-2] << std::endl;
    }
    delete[] Arr;
    delete[] sumArr;
    return 0;
}

