class Solution {
public:


    void merge(vector<int>&arr, int l, int mid, int h){
        vector<int>arr1;
        vector<int>arr2;
        for(int i = l; i<=mid; i++)arr1.push_back(arr[i]);
        for(int i = mid+1; i<=h; i++)arr2.push_back(arr[i]);
  

        int m = arr1.size(), n = arr2.size();
        int i = 0, j = 0, k = l;
        while(i<m&&j<n){
            if(arr1[i]<arr2[j]){
                arr[k++] = arr1[i++];
            }else {
                arr[k++] = arr2[j++];
            }
        }
        while(i<m){
            arr[k++]=arr1[i++];
        }
        while(j<n){
            arr[k++] = arr2[j++];
        }
     
    }
    void mergeSort(vector<int>&arr, int l, int h){
        if(h>l){
            int m = (h+l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, h);
            merge(arr, l, m, h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};