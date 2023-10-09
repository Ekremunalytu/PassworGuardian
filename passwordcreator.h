#ifndef PASSWORDCREATOR_H
#define PASSWORDCREATOR_H

#include <fstream>
#include "passwordgenerator.h"
#include "passwordstrengthcontroller.h"


int password_func(){
    std::string  password;
    std::string  generated_password;

    std::string *password_pointer = &password;
    std::string *generated_password_pointer = &generated_password;
    int password_selector;
    int password_generation_flag = 1;
    int generated_password_length;

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
    std::cout << "You can also use generated password from our program" << std::endl;
    std::cout << "Enter 1 to generate password or enter 2 to enter your personal password" << std::endl;
    
    while (( !(std::cin>>password_selector)) ||  (!(password_selector == 1 || password_selector == 2))){
        std::cout << "Invalid input. Please enter 1 or 0" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    switch ( password_selector ){
    case 1:{
        
        while (password_generation_flag){

            generated_password_length = 0;

            while (generated_password_length < 8){
                std::cout << "Please enter password length" << std::endl;
                std::cin  >> generated_password_length;
                
            }

            generated_password = password_generator(generated_password_length);

            std::cout << "Generated password:  " << *generated_password_pointer << std::endl;
            std::getline(std::cin , password);
            std::cout << "Press 0 to proceed further " << std::endl;
            std::cout << "Press 1 to generate password again" << std::endl;
            std::cin >> password_generation_flag;

        }
        
        password = *generated_password_pointer;
        break;
    }
    case 2:
        std::cout << "Enter your password" << std::endl;
        std::cin  >> password;
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        return 1;
    }
    

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



#endif 