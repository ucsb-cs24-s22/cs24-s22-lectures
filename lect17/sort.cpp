#include <iostream>
#include <vector>
#include <queue>
#include<time.h>

using namespace std;

void visualize(vector<int>& nums){
     for(auto item: nums){
        for(int i = 0; i< item;i++){
             cout<<"-";
         }
        cout<<endl;
    }
    cout<<endl;

}
void selectionSort(vector<int>& v){
    int minIndex = 0;
    for (int i = 0; i < v.size(); i++){ // n times
        minIndex = i;
        for (int j = i + 1; j < v.size(); j++){
            // (n-1) + (n-2) + (n-3) + ... 1 = n *( n- 1)/ 2
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            int temp = v[minIndex];
            v[minIndex] =  v[i];
            v[i] = temp;
           
        }
    }
    // T(n) =  c1* n * (n-1)/2 + n*c2 = O(n^2)
    // S(n) =  O(1)

}

void simpleHeapSort(vector<int>& v){
    priority_queue<int, vector<int>, greater<int>> pq; //minHeap
    for(auto item: v){ // n times
        pq.push(item); // worst case: O(log n)
    }
    // O(n log n)
    int i = 0;
    while(!pq.empty()){
        v[i] = pq.top(); //O(1)
        pq.pop(); // O(log n)
        i++; // O(1)
    }
    // O(n log n)
    //T(n) =   O(n log n) +  O(n log n)  =  O(n log n)
    //S(n) = O(n)
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    vector<int> v;
    for(int i = 0; i< 10; i++){
        v.push_back(rand() % 50 + 1);
    }
    cout<<"Before sorting"<<endl;
    visualize(v);
    simpleHeapSort(v);
    cout<<"After sorting"<<endl;
    visualize(v);


    return 0;
}





