#include <stdio.h>
#include <stdlib.h>


void Merge(int *a, int *w, int len){
    int i,j,k = 0;

}

void MergeSort(int *a, int *w, int n){
    /*take care of the stopping condition?*/
    if(n < 2){
        return;
    }


    int mid = n/2;
    MergeSort(a,mid);
    MergeSort(a + mid, n - mid);
    
    /*merge the two halves of array a into array w*/
    Merge(a,);
    /*copy array w back into array a*/
    

}
