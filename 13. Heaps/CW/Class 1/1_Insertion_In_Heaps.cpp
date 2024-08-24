#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int arr[101];       // TODO: Create a dynamic array
        int size;

    Heap(){
        size=0;
    }

    void insert(int data){
        // First insert the value at the end of the array
        // But before inserting, move size one step forward. As it will be size-1. So, inserting directly it will just replace the exisiting value in the tree
        size += 1;
        int index = size;
        arr[index] = data;  

        //* Now place the inserted data to the correct position which obeys heap condition
        //! We use index > 1 not > = 1. As we are checking for parent node's data. Assume if we use >= 1 when current node will be at 1 and will be checking for 0th index, which is -1 by default. As numbering of the array starts from 1. (Visualizing Tree but implementing using Array. As it makes easy to understand.). So it will replace that value and -1 will be at index 1 and value will be at 0th index which is not correct. When we print, we get Example: 110 -1 50 100 40 45
        while(index > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
        //? Another way to use for loop without breaking and also checking at the for loop
        // while((arr[index] > arr[index/2]) && index > 1){
        //     swap(arr[index], arr[index/2]);
        //     index = index/2;
        // }
    }
};

int main(){
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;
    cout<<"Printing the heap: "<<endl;
    for(int i=0; i<=h.size; i++){
        cout<<h.arr[i]<<" ";
    }

    // Inserting the value
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(110);
    cout<<"\nPrinting the heap after insertion: "<<endl;
    for(int i=0; i<=h.size; i++){
        cout<<h.arr[i]<<" ";
    }
}