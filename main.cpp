#include <iostream>
#include <cmath>
#include <string>






int main() {

    std::string  password;

    int exit_flag = 1;

    int lowercase_flag = 0;
    int Uppercase_flag = 0;
    int number_flag = 0;
    int special_character_flag = 0;
    int length_flag = 0;
    

    std::cout << "Welcome to password Password Guardian" << std::endl;
    std::cout << "Please enter your password to see how safe it is" << std::endl;

    std::getline(std::cin , password);

    

    while (exit_flag){
        
        int password_length = password.length();

        if ( password_length < 8 ) {
            std::cout << "Password is too short!!! try again" << std::endl;
            std::getline(std::cin , password);
        }else
            exit_flag = 0;



    }
    



    return 0;




}