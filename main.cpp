#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <iomanip>


const double basic_brute_speed    = 1000;
const double avarage_brute_speed  = 100000;
const double advanced_brute_speed = 100000000;


void password_checker(std::string password , int *p_exit_pointer);

void brute_force_time(const std::string& password);

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
    std::cout << "5-Attackers can brute force your passwords if they have them. To prevent this , this program supports time complexity calculations." << std::endl;
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
            brute_force_time(password);
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


void brute_force_time(const std::string& password){

    int password_length = password.length();
    int character_set_size = 94;

    double total_calculations = std::pow(character_set_size , password_length);

    double basic_brute_force_time    = ( total_calculations / basic_brute_speed    ) / 31536000;
    double average_brute_force_time  = ( total_calculations / avarage_brute_speed  ) / 31536000;
    double advanced_brute_force_time = ( total_calculations / advanced_brute_speed ) / 31536000;

    std::cout << std::fixed << std::setprecision(0);

    std::cout << "It takes " << basic_brute_force_time << " years to crack your password for basic brute force techniques" << std::endl;
    std::cout << "It takes " << average_brute_force_time << " years to crack your password for average brute force techniques" << std::endl;
    std::cout << "It takes " << advanced_brute_force_time << " years to crack your password for advanced brute force techniques" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
    exit(0);

    
    
}



