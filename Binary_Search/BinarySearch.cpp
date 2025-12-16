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

vector<int> firstAndLastOccurrence(vector<int>& arr, int target)
{  
    vector<int>res;
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
   res.push_back(first);
   res.push_back(last);

   return res;
} 


// count no of occurrences of an element in sorted array

// int countOccurrences(vector<int>& arr,int target){
    
//     pair<int,int> p = firstAndLastOccurrence(arr,target);

//     if(p.first == -1 && p.second == -1){
//         return 0; // element not found
//     }
//     else{
//         return (p.second - p.first + 1);
//     }
// }

// Number of Times a Sorted array is Rotated


int RotatedArray(vector<int>& arr){

    int start=0;
    int end=arr.size()-1;
    int n=arr.size();

    while(start<=end){

        int mid=start+(end-start)/2;

        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;

        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
            return mid;
        }
        else if(arr[start]<=arr[mid]){
            start=mid+1;
        }
        else if(arr[mid]<=arr[end]){
            end=mid-1;
        }
    }
    return -1;
}


//Find an Element in a Rotated Sorted Array

int FindElementRotatedArray(vector<int>& nums){
     int low = 0, high = nums.size() - 1;
      while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
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


    vector <int> Arr = {5,6,7,1,2,3,4}; 
    int n=RotatedArray(Arr);
    cout<<"N Rotation"<<n<<endl;

    return 0;
}