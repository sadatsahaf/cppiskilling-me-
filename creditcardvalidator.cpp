#include <iostream>
using namespace std;
int getDigit(const int number);
int sumoddDigit(const string cardNumber);
int sumevenDigit(const string cardNumber);
int main()
{
    string cardNumber;
    int result=0;
    cout << "Enter Credit Card Number:";
    cin >> cardNumber;

    result = sumevenDigit(cardNumber) + sumoddDigit(cardNumber);
    if(result%10 == 0) { 
        cout << "your card is valid \n";
    } 
    else{
        cout << "your card is not valid \n";
    }
    
}
int getDigit(const int number){
    return number%10 + (number / 10 %10); // 18%10 = 8:: 18/10%10 = 1:: 8+1=9
    
}
int sumoddDigit(const string cardNumber){
    int sum=0;
    for (int i = cardNumber.size() - 1; i>=0; i-=2)        //as arr starts with number 0:: i-2 as we need to count the odd var
    {
        sum += cardNumber[i] - '0' ;       // subbing with 0 for itereting the ascii value

    }
    return sum;

}
int sumevenDigit(const string cardNumber){
    int sum=0;
    for (int i = cardNumber.size() - 2; i>=0; i-=2)        //as arr starts with number 0:: i-2 as we need to count the even var
    {
        sum += getDigit((cardNumber[i] - '0')*2);       // multyplying 2 cause it is an even number

    }
    return sum;
}


/*#include <iostream>

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);
int main()
{
    std::string cardNumber;
    int result = 0;

    std::cout << "Enter a credit card #: ";
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is valid";
    }
    else{
        std::cout << cardNumber << " is not valid";
    }

	return 0;
}
int getDigit(const int number){

    return number % 10 + (number / 10 % 10);
}
int sumOddDigits(const std::string cardNumber){

    int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i-=2){
        sum += cardNumber[i] - '0';
    }

    return sum;
}
int sumEvenDigits(const std::string cardNumber){

    int sum = 0;

    for(int i = cardNumber.size() - 2; i >= 0; i-=2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
}*/