class MedianFinder {
    // If element will be sorted in the order
    priority_queue<int>maxpq;
    priority_queue<int, vector<int>, greater<int>>minpq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //inserting element in pq;
        if(maxpq.empty() && minpq.empty()){
                //cout<<"num inserted in maxpq="<<num<<endl;

            maxpq.push(num);
        }
        else if(!maxpq.empty()){
            if(num>maxpq.top()){
                //cout<<"num inserted in minpq="<<num<<endl;
                minpq.push(num);
            }
            else{
                //cout<<"num inserted in maxpq="<<num<<endl;

                maxpq.push(num);
            }
        }

            //rebalancing
            while(minpq.size()+1<maxpq.size()){
                //cout<<"finally pushed to minpq="<<maxpq.top()<<endl;

                minpq.push(maxpq.top());
                maxpq.pop();
            }

            // rebalancing
            while(minpq.size()>maxpq.size()+1){
                //cout<<"finally pushed to maxpq="<<minpq.top()<<endl;
                maxpq.push(minpq.top());
                minpq.pop();
            }
    }
    
    double findMedian() {
        if(maxpq.size()==minpq.size()){
            return (1.0*(maxpq.top()+minpq.top()))/2;
        }
        else if(maxpq.size()>minpq.size()){
            return maxpq.top();
        }
        else{
            //cout<<"here="<<minpq.top()<<endl;
            return minpq.top();
        }
    }
};
