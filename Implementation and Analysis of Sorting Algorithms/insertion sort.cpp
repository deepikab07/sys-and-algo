// INSERTION SORT

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;
int key;

void generateRandomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void InsertionSort(int x[], int size){
    for(int i=1; i<size; i++){
        key = x[i];
        int j;
        for(j=i-1; j>=0 && x[j]>key; j--){
            x[j+1] = x[j];
              
        }
        x[j+1] = key;
        
    }

}

void printArray(int x[], int size){
  for(int k=0; k<=size-1; k++) {
    cout << x[k] << endl;
  }
}

int main(){
  // time_t start, end;
  // time(&start); 
  auto start = high_resolution_clock::now();
  int size = 500;
  int x[size];
  generateRandomArray(x,size,0,10000);
  //int x[] = {4, 5, 1, 9, 10, 2, 11, 12};
  // printArray(x, 7);
  // int size = sizeof(x)/sizeof(x[0]);
  //cout << "Min is at loc " << y << " value " << x[y] << endl;
  InsertionSort(x, size);
  //printArray(x,size);
  //time(&end); 
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
    // Calculating total time taken by the program. 
  //double time_taken = double(end - start);
  //cout << "Time taken by program is : " << fixed << time_taken << setprecision(10); 
   std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
  return 0;
}