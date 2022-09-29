#include "menu.h"
#include "hanoi.h"



using namespace std;
int ask(const char* msgs[], int n)
{
  int choice = -1;
  string err = "";
  while (choice < 0 || choice >= n) {
    cout << err << endl;
    err = "Wrong input";
    for (int i = 0; i < n; i++) cout << msgs[i] << endl;
    cout << "Enter option: ";
    cin >> choice;
  }
  if(!choice) choice -= 20;
  return choice;
}

void clean(Stack<int>* stack1, Stack<double>* stack2, Stack<Complex>* stack3, Stack<string>* stack4, Stack<char>* stack5, Stack<Student>* stack6)
{
  if(stack1) { delete stack1; }
  if(stack2) { delete stack2; }
  if(stack3) { delete stack3; }
  if(stack4) { delete stack4; }
  if(stack5) { delete stack5; }
  if(stack6) { delete stack6; }

}

void menu()
{
  const char* MAIN[] = {
    "0. Quit",
    "1. Create stack",
    "2. Stack operations",
    "3. Run tests",
    "4. Hanoi tower"
  };
  int main_size = 5;

  const char* CREATE[] = {
    "0. Quit",
    "1. Integers",
    "2. Floats",
    "3. Complex numbers",
    "4. Strings",
    "5. Symbols",
    "6. Students",
  };

  int create_size = 7;

  const char* OPERATIONS[] = {
    "0. Quit",
    "1. Push",
    "2. Pop",
    "3. Get subsequence",
    "4. Concatenate",
    "5. Find subsequence",
  };
  int operations_size = 6;
  


  Stack<int>* stack1      = 0;
  Stack<double>* stack2   = 0;
  Stack<Complex>* stack3  = 0;
  Stack<string>* stack4   = 0;
  Stack<char>* stack5     = 0;
  Stack<Student>* stack6  = 0;

  auto get_len = []()
  {
    int len;
    cout << "Enter number of elements: \n";
    cin >> len;
    while(len <= 0) {
      cout << "Inappropriate number of elements.\n";
      cout << "Enter number of elements: \n";
      cin >> len;
    }
    return len;
  };
  auto get_int_array = [](int len)
  {
    cout << "Enter ints: \n";
    int* a = new int[len];
    for(int i = 0 ; i < len; i++) cin >> a[i];
    return a;
  };
  auto get_double_array = [](int len)
  {
    cout << "Enter elements: \n";
    double* ar = new double[len];
    for(int i = 0 ; i < len; i++) cin >> ar[i];
    return ar;
  };
  auto get_Complex_array = [](int len)
  {
    cout << "Enter elements: \n";
    Complex* arr = new Complex[len];
    double Re;
    double Im;
    for(int i = 0 ; i < len; i++) {
      cout << "Enter Re: ";
      cin >> Re;
      cout << "Enter Im: ";
      cin >> Im;
      arr[i] = Complex(Re, Im);
    }
    return arr;
  };
  auto get_string_array = [](int len)
  {
    cout << "Enter strings: \n";
    string* array = new string[len];
    for(int i = 0 ; i < len; i++) cin >> array[i];
    return array;
  };
  auto get_char_array = [](int len)
  {
    cout << "Enter chars: \n";
    char* array = new char[len];
    for(int i = 0 ; i < len; i++) cin >> array[i];
    return array;
  };
  auto get_Student_array = [](int len)
  {
    cout << "Enter Students: \n";
    Student* array = new Student[len];
    int id;
    string firstName;
    string middleName;
    string lastName;
    for(int i = 0 ; i < len; i++) {
      cout << "ID: ";
      cin >> id;
      cout << "First name: ";
      cin >> firstName;
      cout << "Middle name: ";
      cin >> middleName;
      cout << "Last name: ";
      cin >> lastName;
      array[i] = Student(id, firstName, middleName, lastName);
    }
    return array;
  };

  

  int option = 0;
  while(option >= 0) {
    switch(option) {
      case 0:
        option = ask(MAIN, 5);
        break;

      case 1:
        clean(stack1, stack2, stack3, stack4, stack5, stack6);
        stack1 = 0;
        stack2 = 0;
        stack3 = 0;
        stack4 = 0;
        stack5 = 0;
        stack6 = 0;

        option = ask(CREATE, create_size) + main_size - 1;
        break;

      case 2:
        option = ask(OPERATIONS, 6) + main_size + create_size - 2;
        break;
      case 3: //Run tests
        unit_tests_ArraySequence::Run();
        unit_tests_DynamicArray::Run();
        unit_tests_LinkedList::Run();
        unit_tests_ListSequence::Run();
        unit_tests_Stack::Run();
        option = 0;
        break;
      case 4: //Hanoi tower
      {
        int len = get_len();
        int* a = new int[len];
        for(int i = 0; i < len; i++) a[i] = i+1;

        Stack<int>** stackArray= new Stack<int>*[3];
        stackArray[0] = new Stack<int>(a, len);
        stackArray[1] = new Stack<int>();
        stackArray[2] = new Stack<int>();
        hanoi(len, 0, 1, stackArray);
        for(int i = 0; i < 3; i++) delete stackArray[i];
        delete [] stackArray;
        delete [] a;
        option = 0;
      }
        break;
      case 5: //Create int stack
      {
        int len = get_len();
        int* a = get_int_array(len);
        stack1 = new Stack<int>(a, len);
        delete [] a;
        option = 0;
      }
        break;
      case 6: //Create double stack
      {
        int len = get_len();
        double* ar = get_double_array(len);
        stack2 = new Stack<double>(ar, len);
        delete [] ar;
        option = 0;
      }
        break;
      case 7: //Create Complex stack
      {
        int len = get_len();
        Complex* arr = get_Complex_array(len);
        stack3 = new Stack<Complex>(arr, len);
        delete [] arr;
        option = 0;
      }
        break;

      case 8: //Create string stack
      {
        int len = get_len();
        string* array = get_string_array(len);
        stack4 = new Stack<string>(array, len);
        delete [] array;
        option = 0;
      }
        break;
      case 9: //Create char stack
      {
        int len = get_len();
        char* array = get_char_array(len);
        stack5 = new Stack<char>(array, len);
        delete [] array;
        option = 0;
      }
        break;
      case 10: //Create Student stack
      {
        int len = get_len();
        Student* array = get_Student_array(len);
        stack6 = new Stack<Student>(array, len);
        delete [] array;
        option = 0;
      }
        break;
      case 11: //Push
      {
        if(stack1) {

          int n;
          cout << "Enter int: \n";
          cin >> n;
          stack1->Push(n);

        } else if(stack2) {

          double f;
          cout << "Enter flaot: \n";
          cin >> f;
          stack2->Push(f);

        } else if(stack3) {

          double Re;
          double Im;
          cout << "Enter Re: ";
          cin >> Re;
          cout << "Enter Im: ";
          cin >> Im;
          stack3->Push(Complex(Re, Im));
          
        } else if(stack4) {

            string str;
            cout << "Enter string: \n";
            cin >> str;
            stack4->Push(str);
          
        } else if(stack5) {

          char c;
          cout << "Enter char: \n";
          cin >> c;
          stack5->Push(c);
          
        } else if(stack6) {

          int id;
          string firstName;
          string middleName;
          string lastName;

          cout << "ID: ";
          cin >> id;
          cout << "First name: ";
          cin >> firstName;
          cout << "Middle name: ";
          cin >> middleName;
          cout << "Last name: ";
          cin >> lastName;

          stack6->Push(Student(id, firstName, middleName, lastName));
          
        } else {
          std::cout << "No stack created\n";
        }
        option = 0;
      }
        break;
      case 12: //Pop
      {
        if(stack1) {
          if(!stack1->GetLength()) { cout << "Stack is empty\n"; } else { cout << stack1->Pop(); }

        } else if(stack2) {

          if(!stack2->GetLength()) { cout << "Stack is empty\n"; } else { cout << stack2->Pop(); }

        } else if(stack3) {

          if(!stack3->GetLength()) { cout << "Stack is empty\n"; } else { stack3->Pop().Print(); }
          
        } else if(stack4) {

          if(!stack4->GetLength()) { cout << "Stack is empty\n"; } else { cout << stack4->Pop(); }
          
        } else if(stack5) {

          if(!stack5->GetLength()) { cout << "Stack is empty\n"; } else { cout << stack5->Pop(); }
          
        } else if(stack6) {

          if(!stack6->GetLength()) { cout << "Stack is empty\n"; } else { stack6->Pop().Print(); }

        } else {
          std::cout << "No stack created\n";
        }
        option = 0;
      }
        break;
      case 13: //Get subsequence
      {
        int startIndex;
        int endIndex;
        auto get_indexes = [&](int len)
        {
          cout << "Enter start index: ";
          cin >> startIndex;
          cout << "Enter end index: ";
          cin >> endIndex;
          while(startIndex < 0 || startIndex >= len || endIndex < 0 || endIndex > len || startIndex >= endIndex) {
            cout << "Inappropriate indexes.\n";
            cout << "Enter start index: ";
            cin >> startIndex;
            cout << "Enter end index: ";
            cin >> endIndex;
          }
        };
        if(stack1) {
          get_indexes(stack1->GetLength());
          Stack<int>* temp = stack1->GetSubsequence(startIndex, endIndex);
          delete stack1;
          stack1 = temp;
        } else if(stack2) {

          get_indexes(stack2->GetLength());
          Stack<double>* temp = stack2->GetSubsequence(startIndex, endIndex);
          delete stack2;
          stack2 = temp;
          
        } else if(stack3) {

          get_indexes(stack3->GetLength());
          Stack<Complex>* temp = stack3->GetSubsequence(startIndex, endIndex);
          delete stack3;
          stack3 = temp;
          
        } else if(stack4) {

          get_indexes(stack4->GetLength());
          Stack<string>* temp = stack4->GetSubsequence(startIndex, endIndex);
          delete stack4;
          stack4 = temp;
          
        } else if(stack5) {

          get_indexes(stack5->GetLength());
          Stack<char>* temp = stack5->GetSubsequence(startIndex, endIndex);
          delete stack5;
          stack5 = temp;
          
        } else if(stack6) {

          get_indexes(stack6->GetLength());
          Stack<Student>* temp = stack6->GetSubsequence(startIndex, endIndex);
          delete stack6;
          stack6 = temp;
          
        } 
        option = 0;
      }
        break;
      case 14: //Concatenate
      {
        if(stack1) {

          int len = get_len();
          int* a = get_int_array(len);
          Stack<int>* tmp = new Stack<int>(a, len);
          Stack<int>* concat = stack1->Concat(tmp);
          delete tmp;
          delete stack1;
          delete [] a;
          stack1 = concat;

        } else if(stack2) {

          int len = get_len();
          double* array = get_double_array(len);
          Stack<double>* tmp = new Stack<double>(array, len);
          Stack<double>* concat = stack2->Concat(tmp);
          delete tmp;
          delete stack2;
          delete [] array;
          stack2 = concat;
          
        } else if(stack3) {

          int len = get_len();
          Complex* arr = get_Complex_array(len);
          Stack<Complex>* tmp = new Stack<Complex>(arr, len);
          Stack<Complex>* concat = stack3->Concat(tmp);
          delete tmp;
          delete stack3;
          delete [] arr;
          stack3 = concat;
          
        } else if(stack4) {

          int len = get_len();
          string* arr = get_string_array(len);
          Stack<string>* tmp = new Stack<string>(arr, len);
          Stack<string>* concat = stack4->Concat(tmp);
          delete tmp;
          delete stack4;
          delete [] arr;
          stack4 = concat;
                 
        } else if(stack5) {

          int len = get_len();
          char* a = get_char_array(len);
          Stack<char>* tmp = new Stack<char>(a, len);
          Stack<char>* concat = stack5->Concat(tmp);
          delete tmp;
          delete stack5;
          delete [] a;
          stack5 = concat;
          
        } else if(stack6) {

          int len = get_len();
          Student* array = get_Student_array(len);
          Stack<Student>* tmp = new Stack<Student>(array, len);
          Stack<Student>* concat = stack6->Concat(tmp);
          delete tmp;
          delete stack6;
          delete [] array;
          stack6 = concat;
          
        } 
        option = 0;
      }
        break;  
      case 15: //Find subsequence
      {
        auto check_len = [](int stackLen)
        {
          cout << "Enter subsequence length: ";
          int len;
          cin >> len;
          while(len > stackLen || len <= 0) {
            cout << "Inappropriate length. Enter again: \n";
            cin >> len;
          }
          return len;
        };
        if(stack1) {

          int len = check_len(stack1->GetLength());
          int* array = get_int_array(len);
          cout << "Result: " << stack1->FindSubsequence(array, len) << endl;
          delete [] array;

        } else if(stack2) {
          
          int len = check_len(stack2->GetLength());
          double* array = get_double_array(len);
          cout << "Result: " << stack2->FindSubsequence(array, len) << endl;
          delete [] array;

        } else if(stack3) {
          
          int len = check_len(stack3->GetLength());
          Complex* array = get_Complex_array(len);
          cout << "Result: " << stack3->FindSubsequence(array, len) << endl;
          delete [] array;

        } else if(stack4) {
          
          int len = check_len(stack4->GetLength());
          string* array = get_string_array(len);
          cout << "Result: " << stack4->FindSubsequence(array, len) << endl;
          delete [] array;

        } else if(stack5) {
          
          int len = check_len(stack5->GetLength());
          char* array = get_char_array(len);
          cout << "Result: " << stack5->FindSubsequence(array, len) << endl;
          delete [] array;

        } else if(stack6) {
          
          int len = check_len(stack6->GetLength());
          Student* array = get_Student_array(len);
          cout << "Result: " << stack6->FindSubsequence(array, len) << endl;
          delete [] array;

        }
        option = 0;
      }
        break; 
      default:
        option = 0;
    }
  }
  clean(stack1, stack2, stack3, stack4, stack5, stack6);
}
