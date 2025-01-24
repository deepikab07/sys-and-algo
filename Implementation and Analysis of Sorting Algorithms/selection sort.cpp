#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

void generateRandomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int getMin(int a[], int i, int j) {
  int min = i;
  for(int k = i + 1; k <= j; k++) {
    if (a[k] < a[min]) {
      min = k;
    }
  }

  return min;
}

void printArray(int x[], int size){
  for(int k=0; k<=size-1; k++) {
    cout << x[k] << endl;
  }
}

void Swap(int x[], int i, int j){
  int val1 = x[i];
  x[i] = x[j];
  x[j] = val1;
}

void Sort(int x[], int size){
  int val = getMin(x, 0, size);
  Swap(x, 0, val);
  for(int i=1; i<size; i++){
      val = getMin(x, i, size-1);
      Swap(x, i, val);
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
  // printArray(x, 7);
  //int size = sizeof(x)/sizeof(x[0]);
  //cout << "Min is at loc " << y << " value " << x[y] << endl;
  Sort(x, size);
 //printArray(x,size-1);
  //time(&end); 
 
    // Calculating total time taken by the program. 
  //double time_taken = double(end - start);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
    // Calculating total time taken by the program. 
  //double time_taken = double(end - start);
  //cout << "Time taken by program is : " << fixed << time_taken << setprecision(10); 
   std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
  return 0;
}
