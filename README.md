# Smart Pointers

Smart Pointers for C++ Programming Language.

## Usage

The Smart Pointer object can be used to store pointer to any class.

```cpp
Pointer<int> p1(new int(0));
```

Function call operator can be used to retrieve value of the pointer.

```cpp
cout << p1() << endl;
```

The Smart Pointer object can also be used to retrieve object from the pointer.

```cpp
Pointer<int> p1(new int(0));
cout << *p1 << endl;
```

The assignment operator can be used to reassign another pointer to the Smart Pointer. However, the previously pointed object will be deleted.

```cpp
int *a = new int(5), *b = new int(10);
Pointer<int> p2(a);
cout << *p2 << endl;
p2 = b;
cout << *p2 << endl;
cout << *a << endl;
```

The printed value of pointed variable `a` will be garbage.

The Smart Pointer can also be used to access class members of pointed object.

```cpp
class Test
{
    public:
        int val;
        Test(int v) : val(v) {;}
};

Pointer<Test> p3(new Test(15));
cout << p3->val << endl;
```

The Smart Pointer can also be used to retrieve array elements from the pointer. Notice the extra argument given to the constructor of the Smart Pointer. This extra argument is used when deleting the pointer.

```cpp
int* arr = new int[5]();
Pointer<int> p4(arr, true);
arr[1] = 5;
cout << p4[1] << endl;
```

Arithmetic operations like Addition and Substraction are also supported. But, rather than changing the base pointer value, it will only retrieve the value of the pointer after the operation.

```cpp
Pointer<int> p5(new int[5], true);
for(int i=0; i<5; i++) p5[i] = i+1;
cout << *p5 << endl;
cout << *(p5 + 2) << endl;
cout << *(p5- (-2)) << endl;
```

Logical operations are also supported.

```cpp
Pointer<int> p6(nullptr);
cout << (p6 == nullptr) << endl;
```

Deleteing the pointer.

```cpp
p6.free();
```

## Note

Only one Smart Pointer object should be used to represent a pointer. If the Smart Pointer object is reassigned with another pointer, then the previous pointed object will be deleted. Reassigning same pointer to the Smart Pointer doesn't do anything.

**Enjoy!**