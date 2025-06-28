/*Define a class `Calculator` with a method that performs division.
 Implement exception handling to handle the case of division by zero. 
 Create an object of the `Calculator` class and demonstrate exception handling for division by zero.*/

#include <iostream>
using namespace std;

class Calculator
 {
public:
    int divide(int a, int b) 
	{
        if (b == 0) {
            throw runtime_error(" cannot divide by zero");
        }
        return a/b;
    }
};

int main() 
{
    Calculator calc;
    int c = 10, d = 0;

    try {
       int result = calc.divide(c, d);
        cout << "Result: " << result << endl;
    } 
	catch (const runtime_error& e)
	 {
        cout << "Exception caught: " << e.what() << endl;
    }

    
}
/*output:
Exception caught:  cannot divide by zero
*/

  