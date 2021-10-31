#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void USE_25()
{
    setlocale(LC_ALL, "rus");
    // [154026; 154043]
    const int start = 154026;
    const int end = 154043;
    int count = 0;
    int maxDelFirst = 0;
    int maxDelSecond = 0;

    for (unsigned int i = start; i < end; i++)
    {
        for (unsigned int n = 1; n <= i; n++)
        {
            if (count <= 4 && i % n == 0)
            {
                count++;

                switch (count)
                {
                case 3:
                    maxDelSecond = n;
                    break;
                case 4:
                    maxDelFirst = n;
                    break;
                }
            }
            else if (count == 4)
            {
                count++;
                break;
            }
        }
        if (count == 4)
        {
            cout << maxDelSecond
                << ", ";
            cout << maxDelFirst
                << '.';
            cout << '\n';
        }
        count = 0;
    }
}

void USE_24()
{
    string str;
    int summ = 0;
    int s = 0;
    int x = 0;

    setlocale(LC_ALL, "rus");
    std::cout << "Подсчёт Х и S\n";

    fstream theFile; // <=> ofstream theFile("24 - s1.txt"); Тогда следующая строка не требуется.
    theFile.open("24-s1.txt");

    // Пока файл не кончился, пока мы не строим в конце файла
    while (!theFile.eof())
    {
        // Получить строку
        getline(theFile, str);
        // Если полученная строка не пустая
        if (str != "")
        {
            // Идём посимвольно по строке
            for (unsigned int i = 0; i < str.length(); i++)
            {
                // Если встретили s или x то инкрементируем соответствующие переменные
                if (str[i] == 'S')
                    s++;
                else if (str[i] == 'X')
                    x++;
            }
            // Если кол-во совпало, инкрементируем сумму
            if (s == x)
                summ++;
            // Обнуляем счётчики
            s = 0;
            x = 0;
        }
    }
    // Выводим сумму
    cout << summ;
    // Закрываем файл
    theFile.close();
}

void USE_somenumber()
{
        long int x, y, a, b, c;
        a = 0;
        b = 0;
        c = 100000;
        x = 0;
        y = 0;
    
        // cin >> x;
        while (!(a == 5 && b == 3) && c < 1000000) 
        {
            a = 0;
            b = 0;
            c++;
            x = c;
            while (x > 0) {
                y = x % 10;
                if (y > 3)
                    a = a + 1;
                if (y < 8)
                    b = b + 1;
                x = x / 10;
            }
        }
        cout << a << endl << b << endl << c << endl << "-----------" << endl;
}

void USE_27()
{
    const short numberInARow = 3;
    setlocale(LC_ALL, "rus");
    fstream fileA("27-30a — копия.txt");
    fstream fileB("27-30b.txt");
    string row = "";
    int minNumberInArow = 100000;
    int preMinNumber = 100000;
    unsigned int quantityLines = 0;
    long summ = 0;
    int buffer = 0;
    int min = 100000;

    fileA >> quantityLines; // Считали кол-во.

    for (unsigned int i = 0; i < quantityLines; i++)
    {
        for (unsigned short x = 0; x < numberInARow; x++)
        {
            fileA >> buffer;
            if (buffer < minNumberInArow)
            {
                minNumberInArow = buffer;
                if (buffer < preMinNumber && minNumberInArow < 100000 && (buffer - preMinNumber) % 7 != 0)
                    preMinNumber = minNumberInArow;
                if (buffer < min)
                    min = buffer;
            }
        }
        summ += minNumberInArow;
        minNumberInArow = 100000;
    }
    if (summ % 7 == 0)
    {
        summ -= min;
        summ += preMinNumber;
    }

    cout << summ << " | " << min << ", " << preMinNumber << ' ';
    fileA.close();

    summ = 0;
    minNumberInArow = 100000;
    preMinNumber = 100000;
    min = 100000;
    fileB >> quantityLines; // Считали кол-во.
    for (unsigned int i = 0; i < quantityLines; i++)
    {
        for (unsigned short x = 0; x < numberInARow; x++)
        {
            fileB >> buffer;
            if (buffer < minNumberInArow)
            {
                minNumberInArow = buffer;
                if (buffer < min)
                    min = buffer;
                if (minNumberInArow < preMinNumber && minNumberInArow < 100000 && (minNumberInArow - preMinNumber) % 7 != 0)
                    preMinNumber = minNumberInArow;
            }
        }
        summ += minNumberInArow;
        minNumberInArow = 100000;
        if (min == preMinNumber)
            preMinNumber = 100000;
    }
    if (summ % 7 == 0)
    {
        summ -= min;
        summ += preMinNumber;
    }
    cout << summ << " | " << min << ", " << preMinNumber;

    fileB.close();
}

void USE_22()
{
    int s, n = 0;
    cin >> s;
    while (s + n < 450) {
        s = s - 5;
        n = n + 25;
    }
    cout << n << endl;
}

int main()
{
    // USE_25();
    // cout << "\n";
    // 
    // USE_24();
    // cout << "\n";
    // 
    // USE_somenumber();
    // cout << "\n";
    // 
    // USE_27();
    // cout << "\n";
    //
    // USE_22();

}