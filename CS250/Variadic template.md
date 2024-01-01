>Variadic templates are class or function [templates](https://www.geeksforgeeks.org/templates-cpp/), that can take any variable(zero or more) number of arguments. In C++, templates can have a fixed number of parameters only that have to be specified at the time of declaration. However, variadic templates help to overcome this issue. Douglas Gregor and Jaakko Järvi came up with this feature for C++.
>Variadic arguments are very similar to [arrays](https://www.geeksforgeeks.org/arrays-in-c-cpp/) in C++. We can easily iterate through the arguments, find the size(length) of the template, can access the values by an index, and can slice the templates too. So basically, Variadic function templates are functions that can take multiple numbers of arguments.

[[Fold Expression]]

**Syntax:**
_template<typename arg, typename... args>_
_return_type function_name(arg var1, args... var2)_

```c++
template<typename First,typename...THE_LAST>
void print_message(T value, THE_LAST...the_rest)
{
  cout<<value<<'\n';
  print_message(the_rest...);
}

```
