#include <iostream>
using namespace std;
template<class T>

class Pair
{
public:
  Pair();
  Pair(T firstValue, T secondValue);
  T accessFirst();
  T accessSecond();
private:
  T first;
  T second;
};

template<class T>
Pair<T>::Pair(T firstValue, T secondValue)
          :first(firstValue), second(secondValue)
{}
template<class T>
Pair<T>::Pair(): first(0), second(0)
{
}

template<class T>
T Pair<T>::accessFirst(){ return first; }

template<class T>
T Pair<T>::accessSecond(){ return second; }

int main()
{
  Pair<int> x;
  Pair<int> y(2,3);

  cout << x.accessFirst()<< endl;
  cout << x.accessSecond()<< endl;
  cout << y.accessFirst()<< endl;
  cout << y.accessSecond()<< endl;
  return 0;

}
