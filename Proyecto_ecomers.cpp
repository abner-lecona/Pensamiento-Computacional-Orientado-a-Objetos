// Author: Abner Maximiliano Lecona Nieves
#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    string _name;
    string _description;
    int _value;
    int _quantity;

public:
    Product(string name, string description, int value, int quantity)
    {
        _name = name;
        _description = description;
        _value = value;
        _quantity = quantity;
    }

    string get_name()
    {
        return _name;
    }

    string get_description()
    {
        return _description;
    }

    int get_value()
    {
        return _value;
    }

    int get_quantity()
    {
        return _quantity;
    }

    void set_quantity(int quantity)
    {
        _quantity = quantity;
    }
};

class Cart {
private:
    int _total;

public:
    Cart(int total)
    {
        _total = total;
    }

    int get_total()
    {
        return _total;
    }

    void set_total(int total) 
    {
        _total = total;
    }
};

class Menu {
private:
    Cart cart {0};
    vector<Product> _products;
    vector<Product> _user_cart;

public:
    Menu()
    {
        _products.push_back(Product{"Resident Evil 4 ", 
        "A Leon S. Kennedy se le asigna la mision de rescatar a la hija del presidente de los EUA. ",
         299, 0});
        _products.push_back(Product{"Martha Is Dead  ", 
        "Es un oscuro thriller  en primera persona ambientado en la Italia de 1944.                ",
         279, 0});
        _products.push_back(Product{"The Walking Dead", 
        "Las mejoras graficas y las recreaciones fieles de los menus originales proporcionan.      ",
         459, 0});
        _products.push_back(Product{"MADiSON         ",  
        "Es un videojuego de terror, con una jugabilidad terrorifica y una narrativa inquietante.  ",
         449, 0});
        _products.push_back(Product{"Dead by Daylight", 
        "Es un juego de horror de multijugador (4 contra 1) en el que un jugador representa el rol.",
         279, 0});
    }

    void run_menu()
    {
        cout << "\nE-COMERS" << endl;
        cout << "By: Max:)" << endl;
        cout << "==========================" << endl;
        int option;
        do {
            cout << endl;
            cout << "===========MENU===========" << endl;
            cout << "1) Seleccionar productos" << endl;
            cout << "2) Ver carrito de compras" << endl;
            cout << "3) Terminar compra" << endl;
            cout << "4) Salir" << endl;
            cout << "Seleccionar opcion -> "; cin >> option;
            switch (option) {
            case 1:
                show_products();
                make_purch();
                break;
            case 2:
                if( !(_user_cart.empty()) ) {
                    show_cart();
                } else {
                    cout << "\nEl carrito esta vacio" << endl;
                }
                break;
            case 3:
                end_purch();
                break;
            }
        } while ( ! (option == 4) );

        cout << "\nAplicacion finalizada" << endl;
        cout << endl;
    }

    void show_products()
    {
        int n = 1;
        cout << "\n********SELECIONA UN PRODUCTO********" << endl;
        cout << "\n\tProducto" << "\t\t\t\t" << "Descripcion" << "\t\t\t\t\t\t\t\t" 
        << "P. Unitario" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0 ; i != _products.size(); ++i){
            cout << n << ") " << _products[i].get_name() << "\t" << _products[i].get_description() 
            << "\t\t$" << _products[i].get_value() << endl;
            n += 1;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    void make_purch()
    {
        int n_prod, c_product;
        cout << "Que producto deseas adquirir? -> "; cin >> n_prod;
        if (n_prod > 0 && n_prod <= _products.size()) {
            cout << "Cuantos quieres adquirir? -> "; cin >> c_product;
            cout << c_product << " unidades adquiridas de " << _products[n_prod-1].get_name() 
            << " a $" << _products[n_prod-1].get_value() 
            << " c/u, importe = $" << _products[n_prod-1].get_value()*c_product << endl;
            _user_cart.push_back(_products[n_prod-1]);
            _user_cart[n_prod-1].set_quantity( (_products[n_prod-1].get_quantity()) + c_product );
            cart.set_total( cart.get_total() + (_products[n_prod-1].get_value()*c_product) );
        } else {
            cout << "No existe ese producto..." << endl;
        }
    }

    void end_purch() 
    {
        int elem = _user_cart.size();
        cout << "\nEl total de tu compra es de : $" << cart.get_total() << endl;
        cout << "Gracias por comprar en la tienda en linea ;)" << endl;
        for (int i = 0 ; i != elem; ++i) {
        _user_cart.erase(_user_cart.end() - 1);      
    } 
    }

    void show_cart()
    {
        cout << endl;
        cout << "Cantidad" << "\tProducto" << "\t\tP. Unitario" << "\tImporte" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0 ; i != _user_cart.size(); ++i){
            cout << _user_cart[i].get_quantity() << "\t\t" << _user_cart[i].get_name() << "\t$" 
            << _user_cart[i].get_value() 
            << "\t\t$" << _user_cart[i].get_value() * _user_cart[i].get_quantity() << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "Importe a pagar: $" << cart.get_total() << endl;
    }
};

int main() 
{
    Menu app;
    app.run_menu();

    return 0;
}