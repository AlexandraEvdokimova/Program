// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;

class MyException : public std::exception
{
    std::string message;
public:
    MyException(const char* msg) :message(msg) {}
    const char* what() const { return message.c_str(); }
}; 

int main()
{
    try {
        ifstream fin("Input.txt");
        if (!fin)
        {
            throw  MyException("No file");
        }
        typedef std::vector<std::string > Strings;
        std::map< char, Strings > Text;
        string str;
        Strings vect;
        char a, b;
        cout << "Vvedite bukvu";
        map<char, Strings>::iterator it;
        while (getline(fin, str))
        {
            a = str[0];
            vect.push_back(str) ;
            Text.insert(make_pair(a, vect));
        
        }
        cin >> b;
        it = Text.find(b);
        if (it == Text.end())
        {
            throw  MyException("No line starting with this symbol");
        }
        else
        {
            cout << b << endl;
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i]<< "\n";
            }
        }
        fin.close();
        
    }
    catch (const MyException& ex)
    {
        std::cout << "MyException: " << ex.what();
    }
    catch (...)
    {
        std::cout << "Unknown exception!";
    }
}

