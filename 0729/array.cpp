//1. Given an array consisting of only 0s, 1s, and 2s. 
//Write a program to in-place sort the array without using inbuilt sort functions.
#include<iostream>
using namespace std;
void display(int arr[],int size);
int search_by_value(int arr[],int size,int value);
int insert (int arr[],int& size,int capacity,int value,int pos);
int delete_value (int arr[],int& size,int pos);
int main(){
    int capacity = 10;
    int size = 5;
    int* ptr_size = &size;
    int arr[capacity] = {5,2,7,8,3,6};
    display(arr,size);
    int value;//or key
    //SEARCH
    cout<<"Enter a element to search :";
    cin>>value;
    int index = search_by_value(arr,size,value);
    if(index<0){
        cout<<"Value "<<value<<" is not found in array "<<endl;
    }else{
        cout<<"Value "<<value<<" is at index "<<index<<endl;
    }
    int pos;
    //INSERT
    cout<<"Enter the position of insertion :"<<endl;
    cin>>pos;
    cout<<"Enter the value to insert :"<<endl;
    cin>>value;
    insert (arr,size,capacity,value,pos);
    //DELETE
    cout<<"Enter the position to delete :"<<endl;
    cin>>pos;
    delete_value (arr,size,pos);
}
void display(int arr[],int size){
    cout<<"The array elements are:";
    for(int i;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int search_by_value (int arr[],int size,int value){
    for(int i=0;i<size;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}
int insert (int arr[],int& size,int capacity,int value,int pos){
    if(size>=capacity){
        cout<<"Array overflow";
        return -1;
    }
    if(pos<0||pos>size){
        cout<<"Invalid postion specified"<<endl;
        return -1;
    }
    size++;
    for(int i=size;i>=pos;i--){
        arr[i+1] = arr[i];
    }
    arr[pos]=value;
    display(arr,size);
    return 0;
}
int delete_value (int arr[],int& size,int pos){
    if(pos<0||pos>size){
        cout<<"Invalid postion specified"<<endl;
        return -1;
    }
    for(int i=pos;i<size;i++){
        arr[i] = arr[i+1];
    }
    size--;
    display(arr,size);
    return 0;
}