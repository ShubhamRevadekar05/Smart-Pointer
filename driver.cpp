#include <iostream>
#include "include/Pointer"

using namespace std;

class Test
{
    public:
        int val;
        Test(int v) : val(v) {;}
};

int main()
{
    Pointer<int> p1(new int(5));
    cout << p1 << endl;
    cout << *p1 << endl;
    
    int *a = new int(5), *b = new int(10);
    Pointer<int> p2(a);
    cout << *p2 << endl;
    p2 = b;
    cout << *p2 << endl;
    cout << *a << endl;
    p2 = b;
    cout << *p2 << endl;
    
    Pointer<Test> p3(new Test(15));
    cout << p3->val << endl;
    
    int* arr = new int[5]();
    Pointer<int> p4(arr, true);
    arr[1] = 5;
    cout << p4[1] << endl;
    
    Pointer<int> p5(new int[5], true);
    for(int i=0; i<5; i++) p5[i] = i+1;
    cout << *p5 << endl;
    cout << *(p5 + 2) << endl;
    cout << *(p5- (-2)) << endl;
    
    Pointer<int> p6(nullptr);
    cout << (p6 == nullptr) << endl;
    p6.free();

    return 0;
}