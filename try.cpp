#include <string>
#include <iostream>

using namespace std;

int main()
{
    string* s1 = new string("sde");

    cout << s1 << '\n';

    s1->append("abd");

    cout << s1 << '\n';
    cout << *s1 << '\n';
    cout << s1->capacity() << '\n';



    return 0;
}