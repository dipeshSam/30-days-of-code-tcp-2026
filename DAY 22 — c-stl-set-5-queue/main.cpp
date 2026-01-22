#include <iostream>
#include <queue>

using namespace std;

/* inserts an element x at the back of the queue q */
void push(queue<int> &q, int x) {
    q.push(x);
}

/* pops out the front element of the queue q and returns it */
int pop(queue<int> &q) {
    if (q.empty())
        return -1;
    int x = q.front();
    q.pop();
    return x;
}

/* returns the size of the queue q */
int getSize(queue<int> &q) {
    return q.size();
}

/* returns the last element of the queue */
int getBack(queue<int> &q) {
    if (q.empty())
        return -1;
    return q.back();
}

/* returns the first element of the queue */
int getFront(queue<int> &q) {
    if (q.empty())
        return -1;
    return q.front();
}

void print_queue(queue <int> copy){
    while( ! copy.empty()){
        std::cout << copy.front() << std::endl;
        copy.pop();        
    }
    
}


/* -------- MAIN FUNCTION TO TEST -------- */
int main() {
    queue<int> q;

    push(q, 10);
    push(q, 20);
    push(q, 30);
    push(q, 50);
    push(q, 10);
    push(q, 20);
    push(q, 90);


    cout << "Front element: " << getFront(q) << endl;   // 10
    cout << "Back element: " << getBack(q) << endl;     // 30
    cout << "Queue size: " << getSize(q) << endl;       // 3

    cout << "Popped: " << pop(q) << endl;               // 10
    cout << "Front after pop: " << getFront(q) << endl; // 20
    cout << "Queue size: " << getSize(q) << endl;       // 2

    print_queue(q);


    return 0;
}
