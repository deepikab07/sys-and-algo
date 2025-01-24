#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include <bits/stdc++.h>

void generateRandomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void printArray(int x[], int size){
  for(int k=0; k<size; k++) {
    cout << x[k] << endl;
  }
}

void Merge(int x[], int p, int q, int r){
    vector<int> left_v;
    vector<int> right_v;

    int n1 = q-p+1;
    int n2 = r-q;
    for(int i=p; i<=q; i++){
      left_v.push_back(x[i]);
    }
    for(int i=q+1; i<=r; i++){
      right_v.push_back(x[i]);
    }
    // int left[q-p];
    // copy(left_v.begin(), left_v.end(), left);

    // int right[r-q-1];
    // copy(right_v.begin(), right_v.end(), right);

    int i = 0;
    int j = 0;

    int index = p;
    // for(int k = p; k <= r; k++){
    //   if ((left[i] < right [j]) && j<n2){
    //     x[index] = left[i];
    //     i+=1;
    //   }
    //   else{
    //     x[index] = right[j];
    //     j+=1;
    //   }
    //   index = index +1;
      
    // }
    while (i<n1 && j<n2){
      if (left_v[i] < right_v [j]){
        x[index] = left_v[i];
        i+=1;
      }
      else{
        x[index] = right_v[j];
        j+=1;
      }
      index = index +1;
      
    }
    while (i < n1) {
      x[index] = left_v[i];
      i+=1;
      index++;
    }
    while (j < n2) {
      x[index] = right_v[j];
      j+=1;
      index+=1;
    }


}


void MergeSort(int x[], int p, int q){
  if (p<q) {
    int r = (p+q)/2;
    MergeSort(x, p, r);
    MergeSort(x, r+1, q);
    Merge(x,p,r,q);
  }
}

int main() {
  //time_t start, end;
  //time(&start); 
  auto start = high_resolution_clock::now();
  int size = 50000;
  int x[size];
  generateRandomArray(x,size,0,10000);

  //int x[] = {4, 5, 1, 9, 10, 2, 11, 12};
  //int size = sizeof(x) / sizeof(x[0]);
  MergeSort(x, 0, size-1);
  //printArray(x,size);
  //time(&end); 
 
    // Calculating total time taken by the program. 
  //double time_taken = double(end - start);
  //cout << "Time taken by program is : " << fixed << time_taken << setprecision(10);
   auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
    // Calculating total time taken by the program. 
  //double time_taken = double(end - start);
  //cout << "Time taken by program is : " << fixed << time_taken << setprecision(10); 
   std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
  return 0;
  
}

