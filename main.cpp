#include <iostream>
#include <cassert>
#include "doublelist.hpp"

int main() {
    std::cout << "--- Rozpoczecie testow klasy DoubleList ---" << std::endl;
    DoubleList<int> list;
    
    // Test początkowy
    assert(list.empty() == true);
    assert(list.size() == 0);
    std::cout << "Lista poczatkowa utworzona. Rozmiar: " << list.size() << std::endl;
    
    // Dodawanie
    std::cout << "\nDodawanie elementow (push_back 10, push_front 20, push_back 30)..." << std::endl;
    list.push_back(10);
    list.push_front(20);
    list.push_back(30);
    
    // Stan na teraz: 20, 10, 30
    assert(list.size() == 3);
    assert(list.front() == 20);
    assert(list.back() == 30);
    
    std::cout << "Zawartosc listy (od poczatku): ";
    list.display();
    
    std::cout << "Zawartosc listy (od konca): ";
    list.display_reversed();
    
    // Test kopiowania
    std::cout << "\nTest konstruktora kopiujacego..." << std::endl;
    DoubleList<int> list2 = list;
    assert(list2.size() == 3);
    assert(list2.front() == 20);
    std::cout << "Kopia listy: ";
    list2.display();
    
    // Usuwanie
    std::cout << "\nUsuwanie z przodu (pop_front)..." << std::endl;
    list.pop_front();
    assert(list.front() == 10);
    assert(list.size() == 2);
    std::cout << "Lista po usunieciu: ";
    list.display();
    
    std::cout << "Usuwanie z tylu (pop_back)..." << std::endl;
    list.pop_back();
    assert(list.back() == 10);
    assert(list.size() == 1);
    std::cout << "Lista po usunieciu: ";
    list.display();
    
    // Czyszczenie
    std::cout << "\nCzyszczenie listy (clear)..." << std::endl;
    list.clear();
    assert(list.empty() == true);
    assert(list.size() == 0);
    std::cout << "Rozmiar po czyszczeniu: " << list.size() << std::endl;
    
    std::cout << "\n[OK] Wszystkie asercje przeszly bez bledu" << std::endl;
    return 0;
}
