#pragma once
#include <cstring>
class Teacher
{
  private:
    size_t id;
    char* firstName;
    char* middleName;
    char* lastName;
    size_t department; //кафедра

  public:
    Teacher(size_t id, char* firstName, char* middleName, char* lastName) : id(id), department(department)
    {
      if (firstName == NULL || middleName == NULL || lastName == NULL) throw "Teacher(int, char*, char*) wrong full name.";
      this->firstName   = firstName;
      this->middleName  = middleName;
      this->lastName    = lastName;
    }
    Teacher() : id(0), firstName(NULL), middleName(NULL), lastName(NULL), department(0) {}
  
  public:
    size_t GetId()          { return this->id; }
    char* GetFirstName()    { return this->firstName; }
    char* GetMiddleName()   { return this->middleName; }
    char* GetLastName()     { return this->lastName; }
    size_t GetDepartment()  { return this->department; }
    bool operator == (const Teacher* teacher) { return (this->firstName == teacher->firstName && this->middleName == teacher->middleName && this->lastName == teacher->lastName) ? true : false; }
};