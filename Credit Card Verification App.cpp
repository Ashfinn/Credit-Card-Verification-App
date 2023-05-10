#include <iostream>
#include <string>
#include <vector>

std::string validateCreditCardNumber(std::string input) {
    std::vector<int> creditCardNumber;
    
    for (int i{ 0 };i < input.length();i++) {
        creditCardNumber.push_back(input[i] - '0');
    }
    
    for (int i{static_cast<int>( input.length() - 2) }; i >= 0; i -= 2) {
        int temp{ creditCardNumber[i] };
        temp *= 2;
        if (temp > 9) {
            temp = temp % 10 + 1;
        }
        creditCardNumber[i] = temp;
    }

    int sum{ 0 };
    size_t size = creditCardNumber.size();
    for (size_t i{ 0 }; i < size; i++) {
        sum += creditCardNumber[i];
    }
    if (sum % 10 == 0) {
        return "The Credit Card Number is Valid";
    }
    else {
        return "You have entered an Incorrect Credit Card Number";
    }
}

int main()
{
    std::cout << "Welcome to my Credit Card Verification App\n";
    std::cout << "Enter Your Credit Card Number: \n";
    std::string userNumber;
    std::cin >> userNumber;
    
    std::cout << validateCreditCardNumber(userNumber);
    return 0;
}
