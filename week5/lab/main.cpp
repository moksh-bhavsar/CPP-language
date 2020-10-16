#include <iostream>
#include <cstring>
using namespace std;

struct Student{
  char name[100];
  int grade;
};

int studentNo = 0;
void add2list(Student [], char const *, int);
void printList(Student []);
void sortByname(Student [], int (*p)(Student [], int , int));
void sortBygrade(Student [], int (*p)(Student [], int , int));

int compareName(Student [], int , int );
int compareGrade(Student [], int , int);
void sort(Student l[], int (*)(Student [], int, int));

int main(){

  Student studentlist[100];

  add2list(studentlist, "David", 70);
  add2list(studentlist,"Alex", 80);
  add2list(studentlist,"Jessica", 25);

  cout << "\nBefore sort by Name!" << endl;
  cout << "============" << endl;

  printList(studentlist);

  //TODO: change the following line to sort(studentlist, compareName);
  sortByname(studentlist, compareName);
  cout << "\nAfter sort by Name!" << endl;
  cout << "===========" << endl;
  printList(studentlist);

  // TODO: change the following line to sort(studentlist, compareGrade);
  sortBygrade(studentlist, compareGrade);
  cout << "\nAfter sort by Grade!" << endl;
  cout << "===========" << endl;
  printList(studentlist);
  cout << endl;
  return 0;
 }

void add2list(Student l[], char const * n, int g)
{
  strcpy(l[studentNo].name,n);
  l[studentNo].grade = g;
  studentNo++;
}

void printList(Student l[])
{
  for (int i = 0; i < studentNo; ++i)
  {
    cout << l[i].name << "\t" << l[i].grade << endl;
  }
}

void sortByname(Student l[], int (*p)(Student [], int , int))
{
  for (int i = 0; i < studentNo; ++i){
    int key = i;
    for(int j = i+1; j <studentNo ; ++j){
      if(strcmp(l[j].name,l[key].name) < 0)
        key = j;
    }
    Student tmp = l[i];
    l[i] = l[key];
    l[key] = tmp;
  }
}

void sortBygrade(Student l[], int (*p)(Student [], int , int))
{
  for(int i = 0; i < studentNo; ++i){
     int key = i;
     for(int j = i+1; j <studentNo ; ++j){
       if((l[j].grade-l[key].grade) < 0)
          key = j;
     }
     Student tmp = l[i];
     l[i] = l[key];
     l[key] = tmp;
  }
}

int compareName(Student l[], int i, int j)
{
  // TODO: insert you code here
    if (strcmp(l[i].name,l[j].name)<0)    // using strcmp to compare string and it gives negative number if the first
                                          // string comes before the second alphabetically
    {
		return strcmp(l[i].name,l[j].name);
    }

    else if(strcmp(l[i].name,l[j].name)>0)
    {
		return strcmp(l[i].name,l[j].name);
    }

    else
    {
		return strcmp(l[i].name,l[j].name);
    }
}

int compareGrade(Student l[], int i, int j)
{
  // TODO: insert your code here
    if (l[i].grade < l[j].grade){
      return -1;
    }
    else if (l[i].grade == l[j].grade)
      return 0;
    else
      return 1;
  }

void sort(Student l[], int (*cmp)(Student [], int, int)){
  // TODO: insert your code here
  for (int i = 0; i < studentNo; ++i){
    int key = i;
    for(int j = i+1; j <studentNo ; ++j){
      if(cmp < 0)
        key = j;
    }
    Student tmp = l[i];
    l[i] = l[key];
    l[key] = tmp;
  }
}
