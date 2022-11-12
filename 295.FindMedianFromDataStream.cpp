// https://leetcode.com/problems/find-median-from-data-stream/description/


/*
	Intuition:-
		
		- Here we are using 2 proirity queue maxheap and minheap
		- In max heap we will store approximately half of minimum elements and in the minheap we will store the half of the maximum elements
		- In min heap we will sotre the maximum elements of the stream
		- Also we will try to balance both the heaps 
			- If the size of one heap is 2 more than size of another we will pop the item from that and push into another 
		- For finding the median if the size of both are same than there would be even elements and the median will be the mean of both the tops of the heaps.
		- If the size is not equal then the top of the one whose size is greater will be the median.


----> Basically both the heaps are forming from the middle going to start and to the end.
*/


class MedianFinder {
public:
    // vector<int>arr;
    priority_queue<int>mxh;
    priority_queue<int, vector<int>, greater<int>>mnh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxh.empty()||num<mxh.top())mxh.push(num);
        else mnh.push(num);

        if(mxh.size()>mnh.size()&& mxh.size()-mnh.size()>1){
            mnh.push(mxh.top());
            mxh.pop();
        }else if(mxh.size()<mnh.size()&& mnh.size()-mxh.size()>1){
            mxh.push(mnh.top());
            mnh.pop();
        }
    }
    
    double findMedian() {
        double median;
        if(mxh.size()==mnh.size()){
            median = (double)(mxh.top()+mnh.top())/2;
        }else if(mxh.size()>mnh.size())
            median = (double)mxh.top();
        else if(mxh.size()<mnh.size())
            median = (double)mnh.top();
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */