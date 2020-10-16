#include <iostream> 
using namespace std; 

template<class T>   
class Stack { 
	int size;     // Maximum size of Stack 
    int top;      // Shows the index of top item 
    T * data;   // Points to a dynamic array holding stack items
public: 
    Stack();
    Stack(int);
 
    void push(T x);   // Push an item on top of stack
    void pop();           // Pop an item from stack
    T  peek();         // Return the top item in the stack
    bool isEmpty();     // Check if stack is empty or not
}; 

template<class T>
Stack<T>::Stack(): top(-1){} 
 
template<class T>
Stack<T>::Stack(int s): size(s),top(-1)
{
    data = new T[size];
} 

template<class T>
void Stack<T>::push(T x) 
{ 
    if (top >= (size - 1)) { 
        cout << "Stack Overflow"; 
    } 
    else { 
        data[++top] = x; 
        cout << x << " pushed into stack\n"; 
    } 
} 

template<class T>
void Stack<T>::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
    } 
    else 
        top--; 
} 

template<class T>
T Stack<T>::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is empty"; 
        return 0; 
    } 
    else { 
        cout << "Popped from stack" << endl; 
        return data[top];
    } 
} 

template<class T>
bool Stack<T>::isEmpty() 
{ 
    return (top < 0); 
} 

int main() 
{ 
    Stack<string> s(20); 
     s.push("John");
     s.push("Sue"); 
     s.push("Ted"); 
     s.pop();
    
    cout << s.peek() << " is top of stack" << endl; 
    
    return 0;
}