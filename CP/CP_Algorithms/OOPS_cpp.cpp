
#include <iostream>
using namespace std;

/*


 > What is Object Oriented Programming?

 - Object Oriented programming (OOP) is a programming paradigm that relies on
 - the concept of classes and objects. It is used to structure a software program
 - into simple, reusable pieces of code blueprints (usually called classes),
 - which are used to create individual instances of objects. There are many
 - object-oriented programming languages including JavaScript, C++, Java, and Python.



 > BENEFITS OF OOPS:

-    1.OOP is faster and easier to execute.
-
-    2.OOP makes it possible to create full reusable applications with less code and shorter development time.
-
-    3.Easier to debug, classes often contain all applicable information to them.
-
-    4.Secure, protects information through encapsulation.


> LIMITATIONS of OOPS:

-   1. Steep learning curve: The thought process involved in object-oriented programming
-      may not be natural for some people, and it can take time to get used to it. It is
-      complex to create programs based on interaction of objects. Some of the key
-      programming techniques, such as inheritance and polymorphism, can be
-      challenging to comprehend initially

-   2. Larger program size: Object-oriented programs typically involve more lines of code
-      than procedural programs

-   3. Slower programs: Object-oriented programs are typically slower than procedure based
-      programs, as they typically require more instructions to be executed.

-   4. Not suitable for all types of problems: There are problems that lend themselves well
-      to functional-programming style, logic-programming style, or procedure-based
-      programming style, and applying object-oriented programming in those situations will
-      not result in efficient programs

----------------------------------------------------------------------------------------------------------------------------------------------------------

> Classes and Objects :

> CLASS :
-    A class in C++ is the building block that leads to Object-Oriented programming.
-    It is a user-defined data type, which holds its own data members and member functions,
-    which can be accessed and used by creating an instance of that class. A C++ class
-    is like a blueprint for an object. For Example: Consider the Class of Cars.
-    There may be many cars with different names and brand but all of them will share
-    some common properties like all of them will have 4 wheels, Speed Limit, Mileage range etc.
-    So here, Car is the class and wheels, speed limits, mileage are their properties.

> OBJECT :
 -   An Object is an instance of a Class. When a class is defined, no memory is allocated
 -   but when it is instantiated (i.e. an object is created) memory is allocated.



    >> syntax for creating object


    * Diff types to instantiate object in C++
    https://www.geeksforgeeks.org/different-ways-to-instantiate-an-object-in-c-with-examples/

        class Solution{

        };

        int main(){

            >> object created of class Solution
            Solution S;

        }


*/

//_ EXAMPLE : Different ways to instantiate objects in C++
class Car
{
private:
    int horespower;

public:
    int mileage;
    int speed;

    void changePower(int p)
    {
        horespower = p;
    }

    int getPower()
    {
        return horespower;
    }
};

int main()
{

    //> static allocation
    Car c;

    c.speed = 10;
    c.changePower(854);
    cout << c.getPower() << endl;

    //> Dynamic allocation
    Car *cd = new Car();
    cd->speed = 10;
    cd->changePower(865);
    cout << cd->getPower() << endl;

    // OR

    (*cd).speed = 10;
    (*cd).changePower(866);
    cout << (*cd).getPower();
}

/*


! IMP POINTS :
   * When a class it created without and data members(empty class) 1 byte memeory is allocated for its identification


    > empty class --> size -> 1 byte

        class A{


        };

        >> cout << sizeof(A); --> 1


   * When a class it created with data members(not empty class) its size is equal to its data members

   > Not empty class -> size -> equal to data members

        class A{

            int x;
            > int ==> 4 bytes -> size == 4 bytes allocated
        };


        >> cout << sizeof(A); --> 4


----------------------------------------------------------------------------------------------------------------------------------------------------------
> Data Members and Members functions:

 **   class Car{


:       public:
            int limit;           ----->} Data Members
            double mileage;      ----->}

            void applyBrakes(){}       --->
                                            } Member functions
            void increaseSpeed(){}     --->
 **   }

-    A Class is a user defined data-type which has data members and member functions.
-
-    Data members are the data variables and member functions are the functions used to
-    manipulate these variables and together these data members and member functions defines
-    the properties and behavior of the objects in a Class.
-
-    In the above example of class Car, the data member will be speed limit, mileage etc and
-    member functions can be apply brakes, increase speed etc.


------------------------------------------------------------------------------------------------------------------------------------------------

> ACCESS MODIFIERS:

-    One of the main features of object-oriented programming languages such as C++ is data hiding.
-
-    Data hiding refers to restricting access to data members of a class. This is to prevent other
-    functions and classes from tampering with the class data.
-
-    However, it is also important to make some member functions and member data accessible so that
-    the hidden data can be manipulated indirectly.
-
-    The access modifiers of C++ allows us to determine which class members are accessible to other
-    classes and functions, and which are not.

    * Data Members and Member functions can be accessed using .(dot operator)



> TYPES OF ACCESS MODIFIERS IN C++

    * 1. public
    * 2. private
    * 3. protected
    *
*/
// _Example

class Patient
{
private:
    int patientNumber;
    string diagnosis;

public:
    void billing()
    {
        // code
    }
    void makeAppointment()
    {
        // code
    }
};

/*
! IMP Point :
* if no access modifier is provided in class then, by default 'private' access modifier is applied__



> 1.__public Access Modifier :____________________________________________________________________

    -The public keyword is used to create public members (data and functions).

    -The public members are accessible from any part of the program.

    _EXAMPLE :

-        #include <iostream>
-        using namespace std;
-
*        class Sample
-        {
-
:           public:
-               int age;
-
-               void displayAge()
-               {
-                   cout << "Age = " << age << endl;
-               }
*        };
-

*        int main()
-        {
-
>>           Sample obj1;
-
-            cout << "Enter your age: ";
-
>>           cin >> obj1.age;
-
>>           obj1.displayAge();
-
-            return 0;
*        }


        !IMP POINTS:
        - In main(), we have created an object of the Sample class named obj1. We then access the public
        - elements directly by using the codes obj1.age and obj1.displayAge().

        - Notice that the public elements are accessible from main(). This is because public elements
        - are accessible from all parts of the program.





> 2.__private Access Modifiers :____________________________________________________________________

-    The private keyword is used to create private members (data and functions).

-    The private members can only be accessed from within the class.

-    However, friend classes and friend functions can access private members.
*/

class Car
{
private:
    int horespower;

public:
    int mileage;
    int speed;
};

int main()
{
    Car c;

    // as speed is public is can be access and modified
    c.speed = 10;

    // gives error as private data memebers can only be access inside class
    //-     c.horespower = 860;

    //* so to access private data members and memeber functions, we use GETTERS and SETTERS
}

/*
    > Getters and Setters :
        - To access privata data members and members functions we can use the concepts of getters and setters
        - It is the indirect way of access and modifying the private data members and member function


**      class Car
        {
:        private:
            int horespower;

 :       public:
            int mileage;
            int speed;

           void changePower(int p){
                this.horespower = p;
            }
**       };

**        int main()
        {
>            Car c;

            -as speed is public is can be access and modified
            c.speed = 10;

            -gives error as private data memebers can only be access inside class
            c.horespower = 860;  cant do it -> error

            c.changePower(854); -> calling setter function

**        }

*/

//_EXAMPLE ::

class Car
{
private:
    int horespower;

public:
    int mileage;
    int speed;

    void changePower(int p)
    {
        horespower = p;
    }

    int getPower()
    {
        return horespower;
    }
};

int main()
{
    Car c;

    //-as speed is public is can be access and modified
    c.speed = 10;

    //-gives error as private data memebers can only be access inside class
    // c.horespower = 860;   cant do it->error

    //- calling setter function
    c.changePower(854);

    // -calling getter function
    cout << c.getPower() << endl;
}

/*

/*
> __3. Protected Access Modifier____________________________________________________________________
    - The protected access modifier is similar to the private access modifier in the sense
    - that it can’t be accessed outside of its class unless with the help of a friend class.
    - The difference is that the class members declared as Protected can be accessed by
    - any subclass (derived class) of that class as well.

    ! Note: This access through inheritance can alter the access modifier of the
    !       elements of base class in derived class depending on the mode of Inheritance.
*/

class Parent
{

protected:
    int id_protected; //> Protect members
};

class Child : public Parent //> Sub class or Derived class from public base class
{
public:
    void setId(int id)
    {

        //> Child class is able to access the inherited
        //> protected data members of base class

        id_protected = id;
    }

    void displayId()
    {
        cout << "id_protected is: " << id_protected << endl;
    }
};

int main()
{

    Child obj1;

    //> member function of the derived class can
    //> access the protected data members of the base class
    obj1.setId(81);
    obj1.displayId();
    return 0;
}

/*
-------------------------------------------------------------------------------------------------------------------------------------------------

> CONSTRUCTORS:

    -   A constructor is a special type of member function that is called automatically when an object is created.

    -   A Constructor initializes the class data members with garbage value if we dont put any value to it explicitly.

    -   If we do not specify any constructor then the c++ complier generates a default constructor for an object(which excepts no parameters and has no body).

    -   In C++, a constructor has the same name as that of the class and it does not have a return type.


**      class  Wall
        {
:        public:

    -        Wall()   -> constructor
    -        {
                # code
    -        }

  **      };

        * Here, the function Wall() is a constructor of the class Wall. Notice that the constructor,
            - has the same name as the class,
            - does not have a return type, and
            - is public




> 1. Default constructor
    - A constructor with no parameters is known as a default constructor.
    - If we do not specify any constructor then the c++ complier generates a default constructor for an object(which excepts no parameters and has no body).
    - When we write our own constructor explicitly, the  inbuilt constructor will not be available for us.
*/

//_EXAMPLE: default constructor

class Wall
{
private:
    double length;

public:
    // default constructor to initialize variable
    Wall()
    {
        length = 5.5;
        cout << "Creating a wall." << endl;
        cout << "Length = " << length << endl;
    }
};

int main()
{
    Wall w1;
    return 0;
}

//- Output:
// * Creating a Wall
// * Length = 5.5

/*
! IMP NOTE:
    - If we have not defined a constructor in our class, then the C++ compiler will automatically create a
    - default constructor with an empty code and no parameters.
*/

/*


> 2. Parameterized Constructor

    - A constructor with parameters is known as a parameterized constructor.
    - This is the preferred method to initialize member data.
*/

//_EXAMPLE: Parametrised constructor

// declare a class
class WallP
{
private:
    double length;
    double height;

public:
    // parameterized constructor to initialize variables
    WallP(double len, double hgt)
    {
        length = len;
        height = hgt;
    }

    double calculateArea()
    {
        return length * height;
    }
};

int main()
{
    // create object and initialize data members
    WallP wall1(10.5, 8.6);
    WallP wall2(8.5, 6.3);

    cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
    cout << "Area of Wall 2: " << wall2.calculateArea();

    return 0;
}

//- Output:
//* Area of Wall 1: 90.3
//* Area of Wall 2: 53.55

/*

> 3. Copy Constructor

    - The copy constructor in C++ is used to copy data of one object to another.

    - These are particular type of constructor that ''' takes an object as an argument ''' and copies
    - values of one objects's data members to another object.

    - We have to pass the object's name whose values we want to copy, and we are using or passing
    - an objects to a constructor, we must use the &(ampersand) or address operator.


    _Syntax :

         **   class class_name

            {
        -       int data_member1;
        -       string data_member2;

        :   public:
                // explicit copy constructor of our own

        -       class_name(class_name &obj)
        -       {
        -           data_member1 = obj.data_member1;
        -           data_member2 = obj.data_member2;
        -       }

       **     };

    !IMP NOTE :
    * if we dont use &(ampersand) we will get _infinte loop_ as the address of object in arguments of copy Const. will be same as,
    * the calling function. SEE love BABBAR yt video of oops c++ copy constructor.


*/

//_EXAMPLE : Copy constuctor

class smartphone
{
    string model;
    int year_of_mau;
    bool is_5g;

public:
    // Default constuctor
    smartphone()
    {
        model = "unknown";
        int year_of_mau = 0;
        bool is_5g = false;
    }

    // parameterized constructor
    smartphone(string m, int y, bool _5g)
    {
        model = m;
        year_of_mau = y;
        is_5g = _5g;
    }

    // Copy constructor of our own
    smartphone(smartphone &obj)
    {
        model = obj.model;
        year_of_mau = obj.year_of_mau;
        is_5g = obj.is_5g;
    }
};

int main()
{

    // using default constructor
    smartphone iphone;

    // using parameterised constructor
    smartphone iphone("iphone 14 pro", 2022, true);

    // using copy constructor
    smartphone iphone_2(iphone);
}
/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

>> CONSTRUCTOR OVERLOADING :

    - Concept of having more then one constructor with different parameters.

    - It is same as function overloading

    - Criteria of overloading a constructor is to differ the number of arguments or type of arguments

*/
//_EXAMPLE : Constuctor oveloading

class smartphone
{
    string model;
    int year_of_mau;
    bool is_5g;

public:
    // Default constuctor
    smartphone()
    {
        model = "unknown";
        int year_of_mau = 0;
        bool is_5g = false;
    }

    // parameterized constructor 1
    smartphone(string m, int y)
    {
        model = m;
        year_of_mau = y;
    }

    // parameterized constructor 2
    smartphone(string m, bool _5g)
    {
        model = m;
        is_5g = _5g;
    }
    // parameterized constructor 3
    smartphone(string m, int y, bool _5g)
    {
        model = m;
        year_of_mau = y;
        is_5g = _5g;
    }
};

int main()
{

    // using default constructor
    smartphone iphone;

    // using parameterised constructor
    smartphone iphone("iphone 14 pro", 2022);
    smartphone iphone("iphone 14 pro", true);
    smartphone iphone("iphone 14 pro", 2022, true);
}
/*


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
>> this keyword :
-> https://www.scaler.com/topics/cpp/this-pointer-in-cpp/

    - this pointer holds the address of the current  object. In  simple words, you can say that,
    - this pointer points to the current object of class.

    -- There can be three main usage of this keyword in C++:
      -1. It can be refer to current class instance variable.
      -2. It can be used to pass the current object as a parameter to another method.
      -3. It can be used to declare indexers.

*/
//_EXAMPLE: using this keyword

class Mobile
{

    string model;
    int year_of_mau;

public:
    void set_details(string model, int year_of_mau)
    {
        this->model = model;
        this->year_of_mau = year_of_mau;
    }

    void print()
    {
        cout << this->model << endl;
        cout << this->year_of_mau << endl;
    }
};
int main()
{
    Mobile iphone;

    iphone.set_details("14 pro", 2022);
    iphone.print();
}

//> Deep and shallow copy
//- https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274158/offering/3757643

//> Static keyword in C++
//- https://www.studytonight.com/cpp/static-keyword.php

//> Friend function in C++
// - https://www.programiz.com/cpp-programming/friend-function-class
/*
TODO : this keyword, padding and greedy alignment,destructor, deep and shallow copy, const keyword, const in object creation, initilisation list
*/

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
>> PILLARS OF OOPS::

- There are four pillars of oops
    - 1. Encapsulation
    - 2. Inheritance
    - 3. Polymorphism
    - 4. Abstraction

>---- 1.ENCAPSULATION:______________________________________________________________________________________________

    - Encapsulation refers to the bundling of data and methods inside a single class.

    - It prevents outer classes from accessing and changing data and methods of a class.
    - This also helps to achieve data hiding.

    - The whole idea behind encapsulation is to hide the implementation details from users.
    - If a data member is private it means it can only be accessed within the same class.
    - No outside class can access private data member (variable) of other class.

    - Class is an example of encapsulation

    - In other words encapsulation is wrapping data and methods into single class and protecting  it from outside intervention.

    * How to implement encapsulation

    - 1) Make the instance variables private so that they cannot be accessed
    -    directly from outside the class. You can only set and get values of
    -    these variables through the methods of the class.

    - 2) Have getter and setter methods in the class to set and get
    -    the values of the fields.

    * Real world example : Banking website, where security is important factor
*/
///_Example of encapsulation :

class Person
{

    // private field
private:
    int age;

public:
    // getter method
    int getAge()
    {
        return this->age;
    }

    // setter method,
    void setAge(int age)
    {
        this->age = age;
    }
    //* Note: if we dont write setter method we can make the data members as read only
};

int Main()
{
    // create an object of Person,
    Person p1;

    // change age using setter
    p1.setAge(24);

    // access age using getter
    cout << "My age is " << p1.getAge() << endl;
}

/*

>---- 2. INHERITANCE:______________________________________________________________________________________________

    - Inheritance is one of the key features of OOP that allows
    - us to create a new class from an existing class.

    - The new class that is created is known as Subclass (Child or Derived class)
    - and the existing class from where the child class is derived is known
    - as Superclass (Parent or Base class).

    - The Derived class can also have its own features



    _SYNTAX of Inheritance in C++:

    *    class parent_class{

    *    };

    *    class child_class: access_modifiers parent_class{

    *    };

    - Here child_class is the name of child class, access_modifier is the access mode in which we want to inherit the base class,
    - and parent_class is the name of parent class.



    * MODES OF INHERITANCE :
    > 1. public mode:
         - If we derived a child class from a base class in public mode, the all the public data members  of base class
         - will become public in derived class. All protected will become protected, and private will remain private.

    > 2. protected mode:
         - If we derived a child class from a base class in protected mode, the all the public data members  of base class
         - will become protected in derived class. All protected will become protected, and private will remain private.

    > 3. private mode:
         - If we derived a child class from a base class in private mode, the all the public data members of base class
         - will become private in derived class. All protected will become private, and private will remain private.



    *TABLE FOR REFERENCE:: https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274159/offering/3757646
          ___________________________________________________________________________________
          |  BASE CASE MEMBERS ACCESS SPECIFIERS  |    PUBLIC    |  PROTECTED  |  PRIVATE   |
          |                                       |              |             |            |
          |          public                       |    public    |  protected  |  private   |
          |                                       |              |             |            |
          |          protected                    |    protected |  protected  |  private   |
          |                                       |              |             |            |
          |          private                      |    ----------Not accessible-----------  |
          ___________________________________________________________________________________
*/
//_EXAMPLE : Inheritance in C++

class Vehiclex
{
public:
    string color;
    int max_speed;
    int num_wheels;
};

class Carx : public Vehiclex
{
    int num_gears;
};

class truckx : public Vehiclex
{
    bool isColdStorgeAvail;
};

/*

>-- TYPES OF INHERITANCE::
    >> 1. Single
    >> 2. Multilevel
    >> 3. Multiple
    >> 4. Hierarchical
    >> 5. Hybrid
------------------------------:
    >--- 1. Single Inheritance

        - In single inheritance, one class can extend the functionality of another class.

        - There is only one parent class and one child class in single inheritances.


                            Base_class
                                |
                                |
                                |
                           Derived_class
 */

//_EXAMPLE: single inheritance

class As
{
};

class Bs : public As
{
};

/*
------------------------------:
    >--- 2. Multilevel Inheritance

       - When a class inherits from a derived class, and the derived class becomes the base class of the new class,
       - it is called multilevel inheritance. In multilevel inheritance, there is more than one level.

                            Base_class_A
                                |
                                |
                                |
                           Derived_class_B
                                |
                                |
                                |
                           Derived_class_C
*/
//_EXAMPLE: multilevel inheritance

class A
{
};

class B : public A
{
};

class C : public B
{
};
/*
------------------------------:
    >--- 3. Muliple Inheritance

        - In multiple inheritance, a class can inherit more than one class.
        - This means that a single child class can have multiple parent classes in this type of inheritance.


                   A         B
                    \       /
                     \     /
                      \   /
                        C
*/
//_EXAMPLE: multiple inheritance

class A
{
};

class B
{
};

class C : public A, public B
{
};
/*
     >- AMBIGUITY in Multiple Inheritance::

        - Suppose, two base classes have a same function which is not overridden in derived class.

        - If you try to call the function using the object of the derived class, compiler shows error.
        - It's because compiler doesn't know which function to call.

*/
//_EXAMPLE: Ambiguity in multiple inheritance
class base1
{
public:
    void someFunction() {}
};

class base2
{
public:
    void someFunction() {}
};
class derived : public base1, public base2
{
};

int main()
{
    derived obj;
    //* obj.someFunction() // Error! , doesn't know which function to call
    //>> this problem can be solved using the scope resolution function to specify which function to class either base1 or base2.
}

// _Avoiding ambiguity using scope resolution operator( :: )

int main()
{
    derived obj;
    obj.base1::someFunction(); // Function of base1 class is called
    obj.base2::someFunction(); // Function of base2 class is called.
}

/*
! IMPORTANT :: https://www.makeuseof.com/what-is-diamond-problem-in-cpp/
- What is calling order of contructor and destructor in multiple inheritance ??
- What is Diamond problem and how to avoid it ??
-----------------------------------------------------------------------------------------------------------------------------

------------------------------:
    >--- 4. Hierarchical Inheritance

        - In hierarchical inheritance, one class is a base class for more than one derived class.

                                 A
                              /    \
                             /      \
                            B        C
                          /   \    /   \
                         D     E  F     G
*/
//_EXAMPLE: hierarchical Inheritance

class vehicle
{
};

class car : public vehicle
{
};

class plane : public vehicle
{
};

class ship : public vehicle
{
};

/*
------------------------------:
    >--- 4. Hierarchical Inheritance

        - Hybrid Inheritance is implemented by combining more than one type of inheritance.

        - For example: Combining Hierarchical inheritance and Multiple Inheritance.


                       A      D
                     /   \   /
                    /     \ /
                   B       C
                  / \
                 /   \
                E     F
*/
//_ EXAMPLE : hybrid inheritance

// base class
class Vehicles
{
public:
    Vehicles() { cout << "This is a Vehicle\n"; }
};

// base class
class Fare
{
public:
    Fare() { cout << "Fare of Vehicle\n"; }
};

// first sub class
class Cars : public Vehicles
{
};

// second sub class
class Bus : public Vehicles, public Fare
{
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base class.
    Bus obj2;
    return 0;
}
/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
>---- 3. POLYMORPHISM:______________________________________________________________________________________________

    - It simply means more than one form. That is, the same entity (function or operator)
    - behaves differently in different scenarios.

    - A man at the same time is a father, a husband, and an employee. So the same person
    - exhibits different behavior in different situations. This is called polymorphism.

    * TYPES OF POLYMORPHISM
    - 1. Compile-time polymorphism.
    - 2. Run-time polymorphism.


    >-- COMPILE TIME POLYMORPHISM ::
        - This type of polymorphism is achieved by:
           1. Method overloading
           2. Operator overloading

        >>__A. Method Overloading:

            - When there are multiple functions with the same name but different parameters,
            - then the functions are said to be overloaded, hence this is known as Function Overloading.
            - Functions can be overloaded by changing the number of arguments or/and changing the type of arguments.

            - In simple terms, it is a feature of object-oriented programming providing many functions to have the
            - same name but distinct parameters when numerous tasks are listed under one function.

            *__Method overloading is achieved by either:
                1. changing the number of parameters.
                2. or changing the data type of parameters.

            ! IMP NOTE : Regarding function overloading
                - The RETURN types of the methods may or may not the same,
                - it is because method/function overloading is NOT associated with RETURN types.
                - Overloaded methods may have the same or different return types, but they must differ in parameters.
*/
//_EXAMPLE: Function overloading
class Geeks
{
public:
    // Function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }

    // Function with same name but
    // 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }

    // Function with same name and
    // 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};
int main()
{
    Geeks obj1;

    // Function being called depends
    // on the parameters passed
    // func() is called with int value
    obj1.func(7);

    // func() is called with double value
    obj1.func(9.132);

    // func() is called with 2 int values
    obj1.func(85, 64);
    return 0;
}
/*
        >>__B. Operator Overloading: https://www.programiz.com/cpp-programming/operator-overloading

            - C++ has the ability to provide the operators with a special meaning
            - for a data type, this ability is known as operator overloading.

            - Syntax:
                returnType operator symbol (arguments) {
                        ... .. ...
                }
*/
//_EXAMPLE : Operator overloading
class B
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }
    void operator+(B &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Output: " << val2 - val1 << endl;
    }
};

int main()
{

    B obj1;
    B obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
}
/*
    >-- RUN-TIME  POLYMORPHISM ::

        - This type of polymorphism is achieved by Method Overriding.

        - `Late binding` and `dynamic polymorphism` are other names for runtime polymorphism.

        >> A. Method overriding : https://www.programiz.com/cpp-programming/function-overriding

            - As we know, inheritance is a feature of OOP that allows us to create derived classes from a base class.
            - The derived classes inherit features of the base class.

            - Suppose, the same function is defined in both the derived class and the based class. Now if we call
            - this function using the object of the derived class, the function of the derived class is executed.
            - This is known as function overriding in C++. The function in derived class overrides the function in base class.

            * Rules of method overriding
            - Parent and chlid class must have functions with same name.
            - Both fucntions must have same parameters
            - It is possible through inheritance only.
*/

//_EXAMPLE : function overriding
class Base
{
public:
    void print()
    {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived Function" << endl;
    }
};

int main()
{
    Derived d1;
    d1.print();
    return 0;
}
// OUTPUT :  Derived Function
/*
- Here, the same function print() is defined in both Base and Derived classes.
- So, when we call print() from the Derived object derived1, the print() from Derived is
- executed by overriding the function in Base.


        >> B. Virtual function
        ->   https://www.programiz.com/cpp-programming/virtual-functions

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
>---- 4. ABSTRACTION:______________________________________________________________________________________________

    - Data abstraction is the process of hiding certain details and showing
    - only essential information to the user.

    - Consider a real-life example of a man driving a car. The man only knows that pressing the accelerator
    - will increase the speed of the car or applying brakes will stop the car but he does not know how on
    - pressing the accelerator the speed is actually increasing, he does not know about the inner mechanism
    - of the car or the implementation of the accelerator, brakes, etc in the car. This is what abstraction is.

    ** Abstraction can be achieved:
     -> 1. Using classes in C++.
     -> 2. Using Access Specifiers.
     -> 3. Abstraction In Header Files.

    _Example of Abstraction :
            - Abstraction in header files:
             - when we include a math header file which has pow() function to calculate power
             - Now we are not concerned with the implementation of pow function but we just want to calualate our result.
             - Thus, Abstraction is a mechanism which represent the essential features without including implementation details.




->     Encapsulation:
-      Is the packing of "data" and "functions operating on that data"
-      into a single component and restricting the access to some of the object's components.
-      Encapsulation means that the internal representation of an object is generally
-      hidden from view outside of the object's definition.

->     Abstraction:
-      Is a mechanism which represent the essential features without including implementation details.

-      Encapsulation:-- Information hiding.
-      Abstraction:-- Implementation hiding.

    * WHat is difference between Abstraction and Encapsulatoin in C++
    https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation

*/
