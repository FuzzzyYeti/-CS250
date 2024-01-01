>Fold expressions in C++17 are a powerful feature that allows you to reduce or “fold” a parameter pack over a binary operator. They were introduced to simplify code that operates on variadic templates and make it more concise and readable.

## **Syntax**

Fold expressions have the following syntax forms:

**(pack op ...)**  Unary Left Fold

```c++
// C++ program to illustrate unary leftfold expression 
#include <iostream> 
using namespace std; 

template <typename... Args> bool all(Args... args) 
{ 
    return (... && args); 
} 

int main() 
{ 
	bool b = all(true, true, true, false); 
	//( {{(true && true) && true} false})
	cout << "Result: " << boolalpha << b << endl; 
	return 0; 
}

```


**(... op pack)**  Unary Right Fold
```c++
template<typename...Args>
int minus_version1(Args...args)
{
	return (... - args);
}
int main()
{
             {(3-2) -1} =0
  std::cout << minus_version1(3, 2, 1) << '\n';
}



```

**(pack op ... op init)** Binary Right Fold
```c++
template <typename... Args>
int multiply_and_add(Args... args)
{
    //1은 시작점이고   나머지는 Unary left fold 
	return (args * ... * 1); // Error: operator with 
	 
}
int main()
{
   multiply_and_add(1,2,3,4,5,6,7);
   // (1*(2*(3*(4*(5*(6*(7*1)))))))
}

```

**(init op ... op pack)** Binary Left Fold
```c++
template <typename... Args>
int multiply_and_add(Args... args)
{
    //1은 시작점이고   나머지는 Unary left fold 
	return (1 * ... *args); // Error: operator with 
	
	 
}

int main()
{
   multiply_and_add(1,2,3,4,5,6,7);
   // ((((((1*1)*2)*3)*4)*5)*6)*7
   

}

```
