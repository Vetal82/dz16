// dz16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Запис у файл
//1.	Створити три бінарні файли і записати в них :
//•	15 цілих чисел випадкових чисел від A до B;
//•	5 однакових дійсних чисел;
//•	5 однакових слів(слово - масив символів = > зберігаємо розмірність рядка, символи рядка).
//Записувані числа і слова вводяться з клавіатури.

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <random>
//
//using namespace std;
//
//int main() {
//    int A, B;
//    cout << "Enter diapazon number (A and B): ";
//    cin >> A >> B;
//
//    
//    ofstream intFile("rand.bin", ios::binary);
//    ofstream floatFile("numb.bin", ios::binary);
//    ofstream stringFile("string.bin", ios::binary);
//
//    
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dis(A, B);
//
//    
//    for (int i = 0; i < 15; ++i) {
//        int randomNumber = dis(gen);
//        intFile.write(reinterpret_cast<const char*>(&randomNumber), sizeof(randomNumber));
//    }
//
//    
//    vector<double> floats(5);
//    cout << "Enter 5 number podobnyh: ";
//    for (int i = 0; i < 5; ++i) {
//        cin >> floats[i];
//    }
//    floatFile.write(reinterpret_cast<const char*>(&floats[0]), floats.size() * sizeof(double));
//
//    
//    vector<string> strings(5);
//    cout << "Enter 5 odnakovyh sliv: ";
//    for (int i = 0; i < 5; ++i) {
//        cin >> strings[i];
//    }
//    for (const string& word : strings) {
//        int wordSize = word.size();
//        stringFile.write(reinterpret_cast<const char*>(&wordSize), sizeof(wordSize));
//        stringFile.write(word.c_str(), wordSize);
//    }
//
//    
//    intFile.close();
//    floatFile.close();
//    stringFile.close();
//
//    cout << "dane save to files bin" << endl;
//
//    return 0;
//}

//2.	Є бінарний файл із цілими числами(завдання 1).Надрукувати всі його елементи, більші за число D.Розмір наявного файлу невідомий.

//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//    const char* fileName = "rand.bin";
//    int D;
//
//    cout << "Enter D: ";
//    cin >> D;
//
//    
//    ifstream inFile(fileName, ios::binary);
//    if (!inFile) {
//        cerr << "ERROR" << endl;
//        return 1;
//    }
//
//    
//    inFile.seekg(0, ios::end);
//    streampos fileSize = inFile.tellg();
//    inFile.seekg(0, ios::beg);
//
//    
//    int num;
//    while (inFile.tellg() < fileSize) {
//        inFile.read(reinterpret_cast<char*>(&num), sizeof(int));
//        if (num > D) {
//            cout << num << " ";
//        }
//    }
//
//    
//    inFile.close();
//
//    return 0;
//}

//3.	Є бінарний файл, у якому записано цілі числа(завдання 1).
//Створити два динамічні масиви, що складаються з :
//•	позитивних чисел
//•	парних чисел

//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    const char* fileName = "numb.bin";
//
//    
//    ifstream inFile(fileName, ios::binary);
//    if (!inFile) {
//        cerr << "Error" << endl;
//        return 1;
//    }
//
//    vector<int> positiveNumbers;
//    vector<int> evenNumbers;
//
//    
//    int num;
//    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
//        if (num > 0) {
//            positiveNumbers.push_back(num);
//        }
//        if (num % 2 == 0) {
//            evenNumbers.push_back(num);
//        }
//    }
//
//    
//    inFile.close();
//
//    
//    cout << "Positiv number:" << endl;
//    for (int num : positiveNumbers) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    cout << "Parni number:" << endl;
//    for (int num : evenNumbers) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


//Робота з функцією fseek
//4.	Дано два цілих числа I, J і файл «9.bin» цілих чисел, що містить елементи прямокутної матриці(за рядками), причому перший елемент файлу містить кількість стовпців матриці.Вивести елемент матриці, розташований у I - му рядку та J - му стовпчику(рядки та стовпчики нумеруються від 1).Якщо потрібний елемент відсутній, то вивести 0.

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    ifstream inFile("9.bin", ios::binary);
    if (!inFile) {
        cerr << "ERROR" << endl;
        return 1;
    }

    int columns;
    
    inFile.read(reinterpret_cast<char*>(&columns), sizeof(int));

    
    int i, j;
    cout << "Enter (i): ";
    cin >> i;
    cout << "Enter (j): ";
    cin >> j;

    
    int position = (i - 1) * columns + j - 1;

    
    inFile.seekg(sizeof(int) + position * sizeof(int));

    
    int element;
    inFile.read(reinterpret_cast<char*>(&element), sizeof(int));

    
    cout << "Element: " << ((inFile) ? to_string(element) : "0") << endl;

    
    inFile.close();

    return 0;
}


//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
