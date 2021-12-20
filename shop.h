/*This class will be used to
- Keep track of inventory
- Give administrator access
    - Change count, add items,delete items, change price
- Give user access
    - Buy, browse items
*/
#ifndef _SHOP_H_
#define _SHOP_H_
#include <iostream>
#include <string>

class Shop
{
private:
    bool endProgram = false;
    bool isAdmin;
    std::string username;
    std::string password;
    enum State
    {
        Login = 0,
        MainMenu,
        AdminMenu,
        UserMenu
    };
    State state = MainMenu;

public:
    void run()
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

private:
    bool verifyUser(std::string username, std::string password)
    {
        return true;
    }

    void adminMenu()
    {
        std::cout << "------ADMIN MENU------" << std::endl;
    }

    void userMenu()
    {
        std::cout << "------USER MENU------" << std::endl;
    }

    void mainMenu()
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

    void login()
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
};

#endif