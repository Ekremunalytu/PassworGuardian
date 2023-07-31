#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

void password_checker(std::string password , int *p_exit_pointer);

int main() {

    std::string  password;

    std::string *password_pointer = &password;

    int exit_flag = 1;

    int* p_exit_pointer = &exit_flag;
    
    

    std::ifstream file("passwords.txt");

    if (!file){
        std::cerr << "File could not opened!" << std::endl;
    }

    
    

    std::cout << "Welcome to Password Guardian" << std::endl;
    std::cout << "Please enter your password to see how safe it is" << std::endl;
    std::cout << "Usage" << std::endl;
    std::cout << "1-Minimum password length should be greater than 7" << std::endl;
    std::cout << "2-Users must use at least 1 upper case and lower case letter in their passwords" << std::endl;
    std::cout << "3-Users must use at least 1 number and special character in their passwords" << std::endl;
    std::cout << "4-Users should not use common passwords. Our program detects common passwords and blocks users to obtain common passwords" << std::endl;
    std::getline(std::cin , password);

    while (exit_flag){

        
        
        std::string line;
        file.clear();
        file.seekg(0);

        while (std::getline(file ,line )){
            if ( line == password ){
                std::cout << "Common password alert!" << std::endl;
                std::cout << "Please try again"  << std::endl;
                file.clear();
                file.seekg(0);
                std::getline(std::cin , password);
            }

            }

        password_checker(password , p_exit_pointer);
        
        std::getline( std::cin , password);
        
    }


        file.close();

        std::this_thread::sleep_for(std::chrono::seconds(5));
    
    return 0;

}



void password_checker(std::string password  ,int  *p_exit_pointer ){

    int uppercase_flag = 0;
    int lowercase_flag = 0;
    int special_character_flag = 0;
    int number_flag = 0;

    int password_length = password.length();

        if ( password_length < 8 ) {
            std::cout << "Password is too short!!! try again" << std::endl;
            std::getline(std::cin , password);
        }else if (password_length > 32 ) {
            std::cout << "Password is too long!!! try again" << std::endl;
            std::getline(std::cin , password);
        }

        for (int i = 0 ; i < password_length ; i++){
            if ( std::isalpha(password[i] ) ){
                if ( std::islower(password[i]) ){
                    lowercase_flag = 1;
                }else {
                    uppercase_flag = 1;
                }
            }else if ( std::isdigit( password[i] ) ){
                number_flag = 1;
            }else{
                special_character_flag = 1;
            }
        }

        if  (number_flag && lowercase_flag && uppercase_flag && special_character_flag ){
            
            std::cout << "Well done. Your password is safe" << std::endl;
            *p_exit_pointer = 0;

        } else{
           
            std::cout << "Your password is too weak!!" << std::endl;
            
            if( number_flag == 0 ){
                std::cout << "Please use numbers in your password!!" << std::endl;
            }

            if ( lowercase_flag ==  0 ){
                std::cout << "Please use lower case letters in  your password!!" << std::endl;
            }

            if ( uppercase_flag == 0 ){
                std::cout << "Please use upper case letter in  your password!!" << std::endl;
            }

            if ( special_character_flag == 0 ){
                std::cout << "Please use special characters in your  password!!" << std::endl;
            } 

            std::cout << "Try again.. " << std::endl;
            
        }

    }






