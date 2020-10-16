#include <iostream>

using namespace std;

class DynamicArray
{
  public:
    
    // Write your code here
	DynamicArray();
	DynamicArray(int n);
	DynamicArray(const DynamicArray &t);
	~DynamicArray();
	DynamicArray & operator=(const DynamicArray &t);
	friend DynamicArray operator+(DynamicArray &t, DynamicArray &i);
	friend ostream& operator<<(ostream& out, const DynamicArray &t);
	friend istream& operator>>(istream& in, DynamicArray &t);
	
 
  private:
    double * ptr;
    int size;
};

DynamicArray::DynamicArray(){
	ptr = nullptr; // initializing ptr to null pointer
	size = 0;
}

DynamicArray::DynamicArray(int n){
	// Creating a dynamic array of size = size
	
	size = n;
	ptr = new double[size];
	for (int i=0; i<size; i++){
		*(this->ptr + i) = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray &t){
	this->size = t.size;	// Changing the size of the array
	
	this->ptr = new double[this->size];		// Creating a new array
	
	// Copying things from one array to another
	for (int i=0; i<size; i++){
		*(this->ptr + i) = *(t.ptr + i);
	}
}

DynamicArray::~DynamicArray(){
	delete [] ptr;	// deleting array
	size = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &t){
	delete [] this->ptr;
	this->size = t.size;	
	
	ptr = new double[size];
	
	for (int i=0; i<size; i++){
		*(this->ptr + 1) = *(t.ptr + 1);
	}
	
	return *this;
}

DynamicArray operator+(DynamicArray &t, DynamicArray &i){
	DynamicArray temp(t.size); // creating a new array of size t.size
	
	// adding two corresponding elements in the array
	for (int j=0; j<t.size; j++){
		(temp.ptr)[j]  = (t.ptr)[j] + (i.ptr)[j];
	}
	
	return temp;
}

ostream& operator<<(ostream& out, const DynamicArray &t){
	out << " [ ";
	for (int i=0; i<t.size; i++){
		out << t.ptr[i] << " ";
	}
	out << "]" << endl;
	
	return out;
}
  
istream& operator>>(istream& in, DynamicArray &t){
	cout << "Enter the dimension of the array: " << endl;
	if (t.size != 0){
		delete [] t.ptr;
	}
	in >> t.size;
	
	t.ptr = new double[t.size];
	cout << "Enter " << t.size << " numbers to be stored in the array" << endl;
	for (int i=0; i<t.size; i++){
		in >> t.ptr[i];
	}
	
	
	return in;
}
  
int main()
{
    int dim;
    cout << "Enter the dimension of the array: ";
    cin >> dim;
    DynamicArray x(dim);                               // Test for default constructor
    DynamicArray y(dim);                        // Test the second constructor
    cin >> y;                                            // Test operator>>
	DynamicArray z = y;                           // Test for copy constructor
	x = y + z;                                            // Test for operator+ and operator=
	cout << "Sum is: " << x << endl;       // Test operator<<
    return 0;
}