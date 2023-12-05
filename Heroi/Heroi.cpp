#include <iostream>
#include <vector>
#include <algorithm>

void insertarElemento(std::vector<std::string>& inventario, const std::string& elemento) {
    inventario.push_back(elemento);
    std::cout << "S'ha inserit '" << elemento << "' a l'inventari.\n";
}

void eliminarElemento(std::vector<std::string>& inventario, const std::string& elemento) {
    auto it = std::find(inventario.begin(), inventario.end(), elemento);
    if (it != inventario.end()) {
        inventario.erase(it);
        std::cout << "S'ha eliminat '" << elemento << "' de l'inventari.\n";
    }
    else {
        std::cout << "'" << elemento << "' no s'ha trobat a l'inventari.\n";
    }
}

void buscarElemento(const std::vector<std::string>& inventario, const std::string& elemento) {
    auto it = std::find(inventario.begin(), inventario.end(), elemento);
    if (it != inventario.end()) {
        std::cout << "'" << elemento << "' es troba a l'inventari.\n";
    }
    else {
        std::cout << "'" << elemento << "' no s'ha trobat a l'inventari.\n";
    }
}

void llistarInventari(const std::vector<std::string>& inventario) {
    std::cout << "Inventari del heroi:\n";
    for (const auto& item : inventario) {
        std::cout << "- " << item << "\n";
    }
}

int main() {
    std::vector<std::string> inventari;

    char opcio;
    std::string element;

    do {
        std::cout << "\nOpcions:\n";
        std::cout << "1. Inserir element\n";
        std::cout << "2. Eliminar element\n";
        std::cout << "3. Buscar element\n";
        std::cout << "4. Llistar inventari\n";
        std::cout << "5. Sortir\n";
        std::cout << "Escull una opcio (1-5): ";
        std::cin >> opcio;

        switch (opcio) {
        case '1':
            std::cout << "Introdueix l'element a insertar: ";
            std::cin >> element;
            insertarElemento(inventari, element);
            break;

        case '2':
            std::cout << "Introdueix l'element a eliminar: ";
            std::cin >> element;
            eliminarElemento(inventari, element);
            break;

        case '3':
            std::cout << "Introdueix l'element a buscar: ";
            std::cin >> element;
            buscarElemento(inventari, element);
            break;

        case '4':
            llistarInventari(inventari);
            break;

        case '5':
            std::cout << "Adeu!\n";
            break;

        default:
            std::cout << "Opcio no valida. Torna a intentar.\n";
        }

    } while (opcio != '5');

    return 0;
}