// Factores primarios.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

	while(true) {
		int n;
		std::cout << "Ingrese un numero entero positivo: ";
		std::cin >> n;
		if (n == 0) {
			break;
		}
		if (n < 0) {
			std::cout << "Por favor, ingrese un numero entero positivo." << std::endl;
			continue;
		}
		std::cout << "Factores primarios de " << n << " son: ";
		for (int i = 2; i <= n; i++) {
			while (n % i == 0) {
				std::cout << i << " ";
				n /= i;
			}
		}
		std::cout << std::endl;
	}
}
