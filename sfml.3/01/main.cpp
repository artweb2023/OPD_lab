#include <iostream>

int main()
{
    int num = 0;
    for (int num = 1; num <= 100; num++)
    {
        switch (num % 15)
        {
        case 0:
            std::cout << "Fizzuzz" << std::endl;
            break;
        case 5:
        case 10:
            std::cout << "Buzz" << std::endl;
            break;
        case 3:
        case 6:
        case 9:
        case 12:
            std::cout << "Fizz" << std::endl;
            break;
        default:
            std::cout << num << std::endl;
        }
    }
}