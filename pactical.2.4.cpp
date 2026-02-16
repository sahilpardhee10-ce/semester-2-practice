#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    Item()
    {
        itemID = 0;
        itemName = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    Item(int id, string name, double p, int q)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    int getItemID()
    {
        return itemID;       }


    string getItemName()
    {
        return itemName;
    }
    double getPrice()
    {
        return price;     }

    int getQuantity()
    {
        return quantity;     }

    void addStock(int amount)   //  enter amout and addd
    {
        if (amount > 0)
        {
            quantity += amount;
            cout << "Stock added successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void sellItem(int amount)    // enter amount and sell
    {
        if (amount <= 0)
        {
            cout << "Invalid sale quantity!\n";
        }
        else if (amount > quantity)
        {
            cout << "Insufficient stock!\n";
        }
        else
        {
            quantity -= amount;
            cout << "Item sold successfully!\n";
        }
    }

    void display()
    {
        cout << "ID: " << itemID
             << " | Name: " << itemName
             << " | Price: " << price
             << " | Quantity: " << quantity << endl;
    }
};

int main()
{

    const int N = 3;

    Item items[N] =
    {
        Item(101, "Laptop", 50000, 10),
        Item(102, "Mouse", 500, 5),
        Item(103, "Keyboard", 1500, 8)
    };

    int choice, id, amount;

    do
    {
        cout << "\n      Inventory Menu\n";
        cout << "1. Display All Items\n";
        cout << "2. Add Stock\n";
        cout << "3. Sell Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            for (int i = 0; i < N; i++)
            {
                items[i].display();
            }
            break;

        case 2:
            cout << "Enter Item ID to add stock: ";
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> amount;

            for (int i = 0; i < N; i++)
            {
                if (items[i].getItemID() == id)
                {
                    items[i].addStock(amount);
                }
            }
            break;

        case 3:
            cout << "Enter Item ID to sell: ";
            cin >> id;
            cout << "Enter quantity to sell: ";
            cin >> amount;

            for (int i = 0; i < N; i++)
            {
                if (items[i].getItemID() == id)
                {
                    items[i].sellItem(amount);
                }
            }
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    }
    while (choice != 4);

    return 0;
}
