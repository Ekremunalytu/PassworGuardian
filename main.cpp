#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>



int main() {

    std::string  password;

    int exit_flag = 1;

    int length_flag = 0;
    int lowercase_flag = 0 , uppercase_flag = 0 , number_flag = 0 , special_character_flag = 0;

    std::ifstream file("passwords.txt");

    if (!file){
        std::cerr << "File could not opened!" << std::endl;
    }

    
    

    std::cout << "Welcome to Password Guardian" << std::endl;
    std::cout << "Please enter your password to see how safe it is" << std::endl;

    std::getline(std::cin , password);

    while (exit_flag){

        uppercase_flag = 0;
        lowercase_flag = 0;
        special_character_flag = 0;
        number_flag = 0;
        
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
            exit_flag = 0;

        } else{
           
            std::cout << "Your password is too weak!!" << std::endl;
            std::cout << "Try again.. " << std::endl;
            std::getline( std::cin , password);
        }

        
            
    }
    file.close();

    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    return 0;

}