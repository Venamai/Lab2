#include <iostream>
#include <cstring>
#include "Stack.hpp"
#include "unit_tests_ArraySequence.hpp"
#include "unit_tests_DynamicArray.hpp"
#include "unit_tests_LinkedList.hpp"
#include "unit_tests_ListSequence.hpp"
#include "unit_tests_Stack.hpp"
#include "Complex.hpp"
#include "Student.hpp"

int ask(const char*, int);
void clean(Stack<int>*, Stack<double>*, Stack<Complex>*, Stack<std::string>*, Stack<char>*, Stack<Student>*);
void menu();
