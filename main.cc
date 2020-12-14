/*
 * main.cc
 *
 *  Created on: 20 нояб. 2020 г.
 *      Author: User
 */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>

std:: random_device rd;
std:: default_random_engine rnd {rd()};
std:: uniform_int_distribution <> dist1 {15, 25};
std:: uniform_int_distribution <> dist2 {1, 3};
std:: uniform_int_distribution <> dist3 {0, 1};

int n = dist1(rnd);
int right = dist3(rnd);

int read_int(const char * prompt)	{
	int result;
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	std::stringstream input_ss {input};
	input_ss >> result;
	if (input_ss.fail()){
		if (std::cin.eof()){
			std::cerr<< "Ошибка ввода/вывода" << std::endl;
			exit(1);
		}
		else{
			std::cerr<< "Неверный формат числа!" << std::endl;
			std::cerr.flush();
			return read_int("Введите целое число от 1 до 3!: ");
		}
	}
	else if (!(input_ss.eof())){
		std:: cout << "Неверно введены данные!" << std:: endl;
		return read_int("Введите число от 1 до 3!: ");
	}
	return result;
}
void comp1(){
	std:: cout << "Ходит система" << std:: endl;
		int number = dist2(rnd);
		n -= number;
		std:: cout << "Система взяла "<< number <<" камней" << std:: endl;
		std:: cout << std:: endl;
		std:: cout << "Осталось " << n << " камней" << std:: endl;
		right = 1;
}
void comp2(){
	std:: cout << "Ходит система" << std:: endl;
	if (n % 4 == 0){
		std:: cout << "Система берет 3 камня" << std:: endl;
		n -= 3;
	}
	else if (n % 4 == 2){
		std:: cout << "Система берет 1 камень" << std:: endl;
		n -= 1;
	}
	else if (n % 4 == 3){
		std:: cout << "Система взяла 2 камня" << std:: endl;
		n -= 2;
	}
	else if (n % 4 == 1){
		int number = dist2(rnd);
		n -= number;
		std:: cout << "Система взяла "<< number <<" камня" << std:: endl;
	}
	std:: cout << "Осталось " << n << " камней" << std:: endl;
	std:: cout << std:: endl;
	right = 1;
}
void player(){
	std:: cout << "Ваш ход" << std:: endl;
	int number;
	number = read_int("Введите число от 1 до 3: ");
	while(number > 3 or number < 1){
		std:: cout << "Введено неверное число!" << std:: endl;
		number = read_int("Введите число от 1 до 3!: ");

	};
	n -= number;
	std:: cout << "Осталось " << n << " камней" << std:: endl;
	std:: cout << std:: endl;
	right = 0;
}

int main(){

	std:: cout << "Выберите уровень игры" << std:: endl;
	std:: cout << "1 уровень" << std:: endl;
	std:: cout << "2 уровень" << std:: endl;
	std:: cout << "3 уровень" << std:: endl;
	int t;
	t = read_int("");
	std:: cout << std:: endl;
	switch(t){
		case 1:
		{
			std:: cout << "Перед вами " << n << " камней" << std:: endl;
			std:: cout << std:: endl;

			if (right == 0) std:: cout << "Начинает система" << std:: endl;
			else std:: cout << "Начинает человек" << std:: endl;

			while (n > 1){
				if (right == 0) comp1();
				else player();
			}
			if (right == 0) std:: cout << "Вы победили!" << std:: endl;
			else std:: cout << "Вы проиграли!" << std:: endl;
		}break;
		case 2:
		{
			std:: cout << "Перед вами " << n << " камней" << std:: endl;
			std:: cout << std:: endl;
			while (n > 10){
					if (right == 0) comp1();
					else player();
				}
			while(n > 1){
				if (right == 0) comp2();
				else player();
			}
			if (right == 0) std:: cout << "Вы победили!" << std:: endl;
			else std:: cout << "Вы проиграли!" << std:: endl;
		}break;
		case 3:
		{
			std:: cout << "Перед вами " << n << " камней" << std:: endl;
			std:: cout << std:: endl;
			while(n > 1){
				if (right == 0) comp2();
				else player();
			}
			if (right == 0) std:: cout << "Вы победили!" << std:: endl;
			else std:: cout << "Вы проиграли!" << std:: endl;
		}break;
	}

	return 0;
}






