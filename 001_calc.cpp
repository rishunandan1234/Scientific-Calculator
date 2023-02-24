

#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define new_cal 1
#define old_cal 0

// stand_calc class to define standard calculator functions

class stand_calc
{
    /*  Protyping of standard calculator functions. These functions are static, therefore calling of these funcions is possible with the name of the class. There is no need to create an object of the class. */

public:
    static double addition(double, double);
    static double subtract(double, double);
    static double multiplication(double, double);
    static double division(double, double *);
    static double modulus(double *, double *);
};

//  scien_calc class to define scientific calculator functions

class scien_calc
{
public:
    static double square(double);
    static double cube(double);
    static double power(double, double);
    static double sq_root(double);
    static long int fact(double);
    static double sin_func(double);
    static double cos_func(double);
    static double tan_func(double);
};

//  addition function will add two numbers

double stand_calc::addition(double a, double b)
{
    return (a + b);
}

//  subtract function will subtract the second number from the first number

double stand_calc::subtract(double a, double b)
{
    return (a - b);
}

//  multiplication function will multiply two numbers

double stand_calc::multiplication(double a, double b)
{
    return (a * b);
}

/*  division function will divide the first number by the second numbr. This function accepts two arguments, one is copy of a variable and another is poijnter type because if accepting divisor is zero, then this function will show a message to enter teh divisor again. Using pointer means that the entered value of the divisor for this function should be updated at the main function also. */

double stand_calc::division(double a, double *b)
{
    while (*b == 0)
    {
        cout << endl
             << "Cannot divide by zero.";
        cout << endl
             << "Enter second number again:";
        cin >> *b;
    }
    return (a / (*b));
}

/*  Modulus function will divide the first number by the second number and return the remainder part of the idvision. Similar to division function, it will not accept zero in the divisor. Modulus cannot be performed on a double number, so we need to convert it into an integer. */

double stand_calc::modulus(double *a, double *b)
{
    while (*b == 0)
    {
        cout << endl
             << "Cannot divide by zero.";
        cout << endl
             << "Enter second number again:";
        cin >> *b;
    }

    //  Converting double into an integer

    int x = (int)*a;
    int y = (int)*b;
    if (*a - x > 0 || *b - y > 0)
        cout << endl
             << "Converting decimal number into an integer to perform mofulus";
    *a = x;
    *b = y;
    return (x % y);
}

// Declaration of scien_calc calss functions starts from here.
//square function of scien_calc calss to return accepting number to the power 2

double scien_calc::square(double x)
{
    return (pow(x, 2));
}

//cube function of scien_calc class to return accepting number to the power 3

double scien_calc::cube(double x)
{
    return (pow(x, 3));
}

//power function of scien_calc class to return the dirst number to the power of the second number

double scien_calc::power(double x, double y)
{
    return (sqrt(x));
}

/*  fact function of the scien_calc class to return a long integer as factorial of an accepting number. This will convert accepting number into an integer before calculating the factorial. */

long int scien_calc::fact(double x)
{
    int n = (int)x;
    long int f = 1;
    while (n > 1)
    {
        f *= n;
        n--;
    }
    return f;
}

//  sin_func of the scien_calc class to return the sin value of x

double scien_calc::sin_func(double x)
{
    return (sin(x));
}

//  cos_func of the scien_calc class to return the cos value of x

double scien_calc::cos_func(double x)
{
    return (cos(x));
}

//  tan_func of the scien_calc class to return the tan value of x

double scien_calc::tan_func(double x)
{
    return (tan(x));
}

//  Displaying the menus to enter the options and values

int main()
{
    double num1, num2, num3, temp;
    int choice1 = 0, choice2, flag;
    //  Loop of main menu from where the program starts. It will show the meny to choose the type of calculator.

    do
    {
        system("cls");
        cout << "==================Type of Calculators============";
        cout << endl
             << "1\tStandard Calculator" << endl
             << "2\tScientific Calculator" << endl
             << "3\tQuit";
        cout << endl
             << "Choose the type of calculator:";

        cin >> choice1;

        flag = new_cal;

        //  To perform an operation according to the entered option in the main menu

        switch (choice1)
        {
        case 1:
            //  Loop to display the standard calculator menu
            do
            {
                system("cls");

                cout << "====================Standard Calculator==================";
                cout << endl
                     << "1.\tAddition"
                        "\n2.\tSubtraction"
                        "\n3.\tMultiplication"
                        "\n4.\tDivision"
                        "\n5.\tModulus"
                        "\n6.\tReturn to Previous Menu"
                        "\n7.\t Quit";
                // Option 8 will be displayed only when woekig on old calculations. Here, already a number is saved in the calculator memory.
                if (flag == old_cal)
                    cout << endl
                         << "8.\tClear Memory";
                cout << endl
                     << "Choose the type of calculation:";
                cin >> choice2;

                //   To perform operation and call functions of the stand_calc class

                switch (choice2)
                {
                case 1:
                    //If a new calculation is there, then accept the first number else previous calculation result will be the first number.
                    if (flag == new_cal)
                    {
                        cout << "Enter first number:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "First number is " << num1 << endl;
                    }
                    cout << "Enter second number:";
                    cin >> num2;

                    num3 = stand_calc::addition(num1, num2);
                    cout << endl
                         << "Addition of " << num1 << " and " << num2 << " is " << num3;
                    cout << endl
                         << "Press any key to continue.........";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 2:
                    if (flag == new_cal)
                    {
                        cout << "Enter first number:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "First number is " << num1 << endl;
                    }

                    cout << "Enter second numebr:";
                    cin >> num2;

                    num3 = stand_calc::subtract(num1, num2);
                    cout << endl
                         << "Subtraction of " << num2 << " from " << num1 << " is " << num3;
                    cout << endl
                         << "Press any key to continue............";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 3:
                    if (flag == new_cal)
                    {
                        cout << "Enter first number:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "First number is " << num1 << endl;
                    }

                    cout << "Enter second number:";
                    cin >> num2;

                    num3 = stand_calc::multiplication(num1, num2);
                    cout << endl
                         << "Multiplication of " << num1 << " and " << num2 << " is " << num3;
                    cout << endl
                         << "Press any key to continue...........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 4:
                    if (flag == new_cal)
                    {
                        cout << "Enter first number:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "First number is " << num1 << endl;
                    }
                    cout << "Enter second number:";
                    cin >> num2;
                    num3 = stand_calc::division(num1, &num2);
                    cout << endl
                         << "Division of" << num1 << "by" << num2 << "is" << num3;
                    cout << endl
                         << "Press any key to continue........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 5:
                    if (flag == new_cal)
                    {
                        cout << "Enter first number:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "First number is " << num1 << endl;
                    }

                    cout << "Enter second number:";
                    cin >> num2;
                    num3 = stand_calc::modulus(&num1, &num2);
                    cout << endl
                         << "Modulus of " << num1 << " by " << num2 << " is " << num3;
                    cout << endl
                         << "Press any key to continue..........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 6:
                    cout << endl
                         << "Returning to previous menu.";
                    cout << endl
                         << "Press any key to continue........";
                    getch();
                    break;

                case 7:
                    cout << endl
                         << "Quitting..........";
                    cout << endl
                         << "Press any key to continue.......";
                    exit(0);

                case 8:
                    //  If a new calculation is going on then 8 is an invalid option, else 8 is an option to start a new calculation.
                    if (flag == new_cal)
                    {
                        cout << endl
                             << "Invalid choice.";
                        cout << endl
                             << "Press any key to continue......";
                        getch();
                    }
                    else
                    {
                        temp = 0;
                        flag = new_cal;
                    }
                    break;

                default:
                    cout << endl
                         << "Invalid choice.";
                    cout << endl
                         << "Press any key to continue........";
                    getch();
                    break;
                }
            } while (choice2 != 6);
            break;

        case 2:
            //Loop to display a scientific calculator menu

            do
            {
                system("cls");

                cout << "===========Scientific Calculator==============";
                cout << endl
                     << "1.\tSquare"
                        "\n2.\tCube"
                        "\n3.\tPower"
                        "\n4.\tFactorial"
                        "\n5.\tSin"
                        "\n6.\tCos"
                        "\n7.\tTan"
                        "\n8.\tReturn to previous menu"
                        "\n9.\tQuit";

                if (flag == old_cal)
                    cout << endl
                         << "10.\tClear Memory";

                cout << endl
                     << "Choose the type of calculation:";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    if (flag == new_cal)
                    {
                        cout << "Enter number to find square:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number is " << num1 << endl;
                    }
                    num3 = scien_calc::square(num1);
                    cout << endl
                         << "Square of " << num1 << " is " << num3;
                    cout << endl
                         << "Press any key to continue...........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 2:
                    if (flag == new_cal)
                    {
                        cout << "Enter number to find cube:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number is " << num1 << endl;
                    }
                    num3 = scien_calc::cube(num1);
                    cout << endl
                         << "cube of " << num1 << " is " << num3;
                    cout << endl
                         << "Press any key to continue...........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 3:
                    if (flag == new_cal)
                    {
                        cout << "Enter first number for base to find power:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number is " << num1 << endl;
                    }
                    cout << "Enter second number for power to find power:";
                    cin >> num2;
                    num3 = scien_calc::power(num1, num2);
                    cout << endl
                         << "Square of " << num1 << " to the power " << num2 << " is " << num3;
                    cout << endl
                         << "Press any key to continue...........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 4:
                {
                    if (flag == new_cal)
                    {
                        cout << "Enter number to find factorial:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number to find factorial is " << num1 << endl;
                    }

                    long int num4 = scien_calc::fact(num1);
                    cout << endl
                         << "Factorial of " << num1 << " is " << num4;
                    cout << endl
                         << "Press any key to continue...............";

                    getch();
                    temp = num4;
                    flag = old_cal;
                    break;
                }

                case 5:
                    if (flag = new_cal)
                    {
                        cout << "Enter number to find sin value:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number ofr sin value is " << num1 << endl;
                    }
                    num3 = scien_calc::sin_func(num1);
                    cout << endl
                         << "Sin value of " << num1 << " is " << num3;
                    cout << endl
                         << "Press any key to continue........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 6:
                    if (flag = new_cal)
                    {
                        cout << "Enter number to find cos value:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number of cos value is " << num1 << endl;
                    }
                    num3 = scien_calc::cos_func(num1);
                    cout << endl
                         << "Cos value of " << num1 << " is " << num3;
                    cout << endl
                         << "Press any key to continue........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 7:
                    if (flag = new_cal)
                    {
                        cout << "Enter number to find tan value:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << endl
                             << "Number of tan value is " << num1 << endl;
                    }
                    num3 = scien_calc::tan_func(num1);
                    cout << endl
                         << "Tan value of " << num1 << " is " << num3;
                    cout << endl
                         << "Press any key to continue........";

                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;

                case 8:
                    cout << endl
                         << "Returning to previous menu.";
                    cout << endl
                         << "Press any key to continue.........";

                case 9:
                    cout << endl
                         << "Quitting..........";
                    cout << endl
                         << "Press any key to continue.........";
                    getch();
                    exit(0);

                case 10:
                    if (flag == new_cal)
                    {
                        cout << endl
                             << "Invalid choice.";
                        cout << endl
                             << "Press any key to continue........";
                        getch();
                    }
                    else
                    {
                        temp = 0;
                        flag = new_cal;
                    }
                    break;

                default:
                    cout << endl
                         << "Invalid choice.";
                    cout << endl
                         << "Press any key to continue.........";
                    getch();
                    break;
                }
            } while (choice2 != 8);
            break;
        case 3:
            cout << endl
                 << "Quitting.......";
            cout << endl
                 << "Press any key to continue........";
            getch();
            break;

        default:
            cout << endl
                 << "Invalid Choice.";
            cout << endl
                 << "Press any key to continue........";
            getch();
            break;
        }
    } while (choice1 != 3);

    return 0;
}