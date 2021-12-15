#include <string>

class Item
{
public:
    Item(std::string name, int count, float cost);
    std::string getName();
    void setName(std::string name);

    int getCount();
    void setCount(int count);

    float getCost();
    void setCost(float cost);

    void printInfo();

private:
    std::string name;
    int count;
    float cost;
};
