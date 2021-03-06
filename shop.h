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
    void run();

private:
    bool verifyUser(std::string username, std::string password);
    void adminMenu();
    void userMenu();
    void mainMenu();
    void login();
};

#endif