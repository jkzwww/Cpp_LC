#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void basicQ(){
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "is q empty? " << q.empty();
    cout << "queue size: " << q.size() << '\n';
    cout << "front elem: " << q.front() << '\n';
    cout << "back elem: " << q.back() << '\n';
    
    q.pop(); // Remove the front element
    
}

void processTasks(queue<string>& tasks) {
    while (!tasks.empty()) {
        string task = tasks.front();
        tasks.pop();
        cout << "Processing task: " << task << endl;
    }
}

void priorityQ(){
    // Default priority_queue (max heap)
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(30);
    maxHeap.push(20);

    while (!maxHeap.empty()) {
        cout << "Max Element: " << maxHeap.top() << endl; // Output the maximum element
        maxHeap.pop(); // Remove the maximum element
    }

     // Min heap using greater<int> as the comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(30);
    minHeap.push(20);

    while (!minHeap.empty()) {
        cout << "Min Element: " << minHeap.top() << endl; // Output the minimum element
        minHeap.pop(); // Remove the minimum element
    }
}

int main() {
    return 0;
}

