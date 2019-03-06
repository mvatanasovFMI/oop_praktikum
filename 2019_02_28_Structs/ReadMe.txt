PROBLEM1 : 
MAKE THE DISPLAY FUNCTION MEMBER METHOD IN THE STRUCT ‘PERSON’ AND USE IT IN THE MAIN FUNCTION
struct Person
{
char name[50];
int age;
float salary;
};
void display(const Person & p)
{
cout << "\Person:" << endl << "Name: " << p.name << endl;
cout << "Age: " << p.age << endl << "Salary: " << p.salary;
}





PROBLEM2 :
A) RENAME THE MEMBER FIELD ‘WIDTH’ AND REFACTOR THE ‘PRINT’ METHOD NOT TO BE INLINE

B) CRAETE METHODS ‘PERIMETER’ AND ‘AREA’ FOR THE STRUCT ‘RECT’

C) CREATE POINTER TO THE VARIABLE OF TYPE ‘RECT’ IN THE MAIN FUNCTION AND PRINT THE RESULT OF THE ‘PERIMETER’ AND THE ‘AREA’ METHODS USING THIS POINTER
struct Rect {
float width;
float m_height;
void Print()
{
      cout << "Width = " << width << endl << "Height = " << this->m_height << endl;
}
void Init(float width, float height);
};
void Rect::Init(float width, float height)
{
   this->width = width;
    m_height = height; 
}













PROBLEM3 :
SUBMIT THE CODE OF PROBLEM1 AND PROBLEM2 THROUGH GIT COMMANDS IN THE GITHUB REPOSITORY - HTTPS://GITHUB.COM/MVATANASOVFMI/OOP_PRAKTIKUM
	
(Create Branch and Folder with your Name/Date, where you submit your code (.cpp and .h files))

