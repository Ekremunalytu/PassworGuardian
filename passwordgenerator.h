#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include <string>

std::string password_generator( int length);


std::string password_generator ( int length){
    srand(time(0));

    length = length - 4;

    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string special_characters = "!@#$%^&*()_-+=<>?";

    std::string generated_password;

    std::string valid_characters = lowercase + uppercase + numbers + special_characters;
   
    generated_password += lowercase[rand() % lowercase.length()];
    generated_password += uppercase[rand() % uppercase.length()];
    generated_password += numbers[rand() % numbers.length()];
    generated_password += special_characters[rand() % special_characters.length()];

    for ( int i = 0 ; i < length ; i++ ){
        generated_password += valid_characters[rand() % valid_characters.length()];
    }

    for( int i = 0 ; i < length ;++i ){
        int j = 0 ; j < rand() % length;
        std::swap(generated_password[i] , generated_password[j]);
    }

    return generated_password;
}

#endif 