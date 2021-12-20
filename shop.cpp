#include <iostream>
#include <string>

#include "shop.h"

void Shop::run()
{
    std::cout << "------WELCOME TO THE SHOP------" << std::endl;
    while (!endProgram)
    {
        switch (state)
        {
        case Login:
            login();
            break;
        case AdminMenu:
            adminMenu();
            break;
        case UserMenu:
            userMenu();
            break;
        case MainMenu:
            mainMenu();
            break;
        }
    }
}

bool Shop::verifyUser(std::string username, std::string password)
{
    return true;
}

void Shop::adminMenu()
{
    std::cout << "------ADMIN MENU------" << std::endl;
}

void Shop::userMenu()
{
    std::cout << "------USER MENU------" << std::endl;
}

void Shop::mainMenu()
{
    std::string userInput;
    bool quit = false;
    std::cout << "------WELCOME TO THE SHOP------" << std::endl;
    while (true)
    {
        std::cout << "0. Quit" << std::endl
                  << "1. Login Page" << std::endl;
        std::cin >> userInput;
        if (userInput == "0")
        {
            endProgram = true;
            break;
        }
        else if (userInput == "1")
        {
            state = Login;
            break;
        }
    }
}

void Shop::login()
{
    bool quit = false;
    std::string userInput;
    std::cout << "Press 0 at any time to return to Main Menu" << std::endl;
    std::cout << "------LOGIN PAGE------" << std::endl;

    enum LoginState
    {
        User,
        Pass,
        Verif,
        MainMenuReturn,
        Done
    };
    LoginState s = User;
    while (s != Done)
    {
        switch (s)
        {
        case User:
            std::cout << "Please enter username" << std::endl;
            std::cin >> userInput;
            if ("0" == userInput)
                s = MainMenuReturn;
            else
            {
                username = userInput;
                s = Pass;
            }
            break;
        case Pass:
            std::cout << "Please enter password" << std::endl;
            std::cin >> userInput;
            if ("0" == userInput)
                s = MainMenuReturn;
            else
            {
                password = userInput;
                s = Verif;
            }
            break;
        case Verif:
            if (username == "admin" && password == "admin1234")
            {
                state = AdminMenu;
            }
            else if (verifyUser(username, password))
            {
                state = UserMenu;
            }
            else
            {
                s = User;
                break;
            }
            std::cout << "Login successfull" << std::endl;
            s = Done;
            break;
        case MainMenuReturn:
            state = MainMenu;
            s = Done;
            break;
        }
    }
    //       std::cout << "Please enter username" << std::endl;
    //       std::cin >> userInput;
    //       if ("0" == userInput)
    //       {
    //           quit = true;
    //           state = MainMenu;
    //           return;
    //       }
    //       else
    //       {
    //           username = userInput;
    //       }
    //       std::cout << "Please enter password" << std::endl;
    //       std::cin >> userInput;
    //       if ("0" == userInput)
    //       {
    //           quit = true;
    //           state = MainMenu;
    //           return;
    //       }
    //       else
    //       {
    //           password = userInput;
    //       }
    //
    //       if (quit)
    //       {
    //           state = MainMenu;
    //       }
}
