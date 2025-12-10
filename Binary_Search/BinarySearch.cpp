#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int target){

    int left=0;
    int right=arr.size()-1;

    while(left<=right){
        int mid = left+(right-left)/2;

        if(arr[mid]== target){
            return mid;// Target found
        }
        else if(arr[mid]>target){
            right= mid-1;
        }
        else if(arr[mid]<target){
            left= mid+1;
        }
        
    }
    return -1; // Target not found
}

int ReverseArrayBinarySearch(vector<int>& arr, int target){

    int left=0;
    int right=arr.size()-1;

    while(left<=right){
        int mid = left+(right-left)/2;

        if(arr[mid]== target){
            return mid;// Target found
        }
        else if(arr[mid]>target){
            left = mid+1;
            
        }
        else if(arr[mid]<target){
            right = mid-1;
        }
        
    }
    return -1; // Target not found
}

// if order is not known    

int ReverseArrayBinarySearchUnknownOrder(vector<int>& arr, int target){

    int left=0;
    int right=arr.size()-1;

    bool isAscending = arr[left] < arr[right];

    while(left<=right){
        int mid = left+(right-left)/2;

        if(arr[mid]== target){
            return mid;// Target found
        }

        if(isAscending){
            if(arr[mid]>target){
                right= mid-1;
            }
            else{
                left= mid+1;
            }
        }
        else{
            if(arr[mid]>target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
    }
    return -1; // Target not found
}



// 1st and last occurrence of an element in sorted array    

int firstAndLastOccurrence(vector<int>& arr, int target)
{

    int first,last=-1;

    // First Occurrence
    int left=0;
    int right= arr.size()-1;

    while(left<=right){
        int mid= left+(right-left)/2;

        if(arr[mid]==target){
            first=mid;
            right=mid-1; // continue searching in left half
        }
        else if(arr[mid]>target){
            right= mid-1;
        }
        else {
            left= mid+1;
        }
    }
    // Last Occurrence
    left=0;
    right= arr.size()-1;    

    while(left<=right){
        int mid = left+(right-left)/2;

        while(left<=right){
            int mid= left+(right-left)/2;
            if(arr[mid]==target){
                last=mid;
                left=mid+1; // continue searching in right half
            }
            else if(arr[mid]>target){
                right= mid-1;
            }
            else {
                left= mid+1;
            }
    }

}
    return {first,last};
} 


// count no of occurrences of an element in sorted array

int countOccurrences(vector<int>& arr,int target){
    
    pair<int,int> p = firstAndLastOccurrence(arr,target);

    if(p.first == -1 && p.second == -1){
        return 0; // element not found
    }
    else{
        return (p.second - p.first + 1);
    }
}



int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 2;

    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    vector<int> revArr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int revTarget = 7;  
    int revResult = ReverseArrayBinarySearch(revArr, revTarget);
    if (revResult != -1) {
        cout << "Element found at index: " << revResult << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    vector<int> unknownOrderArr = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    int unknownOrderTarget = 4;  
    int unknownOrderResult = ReverseArrayBinarySearchUnknownOrder(unknownOrderArr, unknownOrderTarget);
    if (unknownOrderResult != -1) {
        cout << "Element found at index: " << unknownOrderResult << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }   

    vector <int> firstLastArr = {1, 2, 2, 2, 3, 4, 5};
    int firstLastTarget = 2;  
    firstAndLastOccurrence(firstLastArr, firstLastTarget);  

    return 0;
}