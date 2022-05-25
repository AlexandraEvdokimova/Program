Цель работы:
Получение навыков программирования алгоритмов по их описанию, оценки трудоемкости алгоритмов, выявление зависимости трудоемкости алгоритмов от объемов выборки.




Листинг программы 1:
#include <iostream>
#include <cmath>

int board() // функция вычисления длины доски
{
	int num;
	std::cout << "The number of tea bags: ";
	std::cin >> num;

	int c = 5; // максимальное число пакетиков для данной длины
	int length = 5; // минимальная длина стороны доски
	int k = 0;
	while (num > c)
	{
		length++;
		c = (length / 5) * (length / 5) * 5 + (length % 5) * (length / 5); // length/5 - количество слотов по 5 в ряду
		++k; // для подсчета Тэ
	}
	std::cout << "The lentg of board is: " << length << std::endl;
	return length;
}

void O() // функция вычисления асимптотической сложности
{
	int a = 4;
	while (a < 4096)
	{
		a *= 2;
		int s = sqrt(a);
		std::cout << "num = " << a << "   O(g(n)) = sqrt(num) = " << s << std::endl;
	}
}
int main()
{
	board();
	O();
	std::cout << "\n\n";
	std::cout << "      T'1      T1      T'1/T1      T'2       T2        T'2/T2" << 
		"\n8      3       2         1,5        1        1            1\n16     5       4         1,25       1        1            1\n" << 
		"32     10      5         2          1        1            1\n64     15      8         1,88       1        1            1\n" << 
		"128    21      11        1,9        1        1            1\n256    32      16        2          1        1            1\n" <<
		"512    47      22        2,1        1        1            1\n1024   69      32        2,2        1        1            1\n" <<
		"2048   98      45        2,17       1        1            1\n4096   140     64        2,19       1        1            1";
}

Блок-схема:
int board()
 
Листинг программы 2:
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num;
    cin >> num;
    int slots = num / 5; // количество слотов по 5 штук
    int square = floor(sqrt(slots)); // расположение слотов по квадрату
    if (square * square * 5 + square * 4 < num) 
    {
        cout << (square + 1) * 5;
    }
    else 
    {
        cout << square * 5 + ceil((double)(num - square * square * 5) / square);
    }
    return 0;
}
Блок-схема:
 
Вывод: По результатам экспериментов выяснили, что алгоритм, не содержащий цикл, оказался более эффективен для выполнения данной задачи для любого размера входных данных.

