// This program shows how you can catch and handle an exception occurring inside another function

#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

class f_exception
{};

class g_exception
{};

void f(int) throw (f_exception,g_exception); // prototype
void g(int) throw (g_exception); // prototype


int main( )
{
    try
    {
        f(2);
    }
    catch(f_exception)
    {
        cout << "f exception!" << endl;
    }
    catch(g_exception)
    {
        cout << "g exception!" << endl;
    }

    return 0;
}

void f(int n) throw (f_exception,g_exception)
{
    if (n == 1)
        throw f_exception();
    else
        g(2);

}
void g(int n) throw (g_exception)
{
    if (n == 2)
        throw g_exception();
}
