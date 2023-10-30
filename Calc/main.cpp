#include <iostream>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char** argv)
{
    int option;
    bool divide = false;
    bool multiply = false;
    
    if(argc == 1){
        std::cout<<"КАЛЬКУЛЯТОР"<<std::endl
        << "Чтобы выбрать действие, нужно ввести один из параметров:" << std::endl
        << "--multiply или -m — умножение всех введенных значений" << std::endl 
        << "--divide или -d — деление первого значения на все последующие введенные значения"<< std::endl 
        << "Для того чтобы продолжить запустите программу еще раз с нужным параметром и введите значения через пробел"<<std::endl;
        return 0;
    }
    // Проверка наличия аргументов командной строки
    if (argc > 6 or argc < 2) {
        std::cout << "ОШИБКА: Много аргументов" << std::endl;
    } else {
        // Определение возможных параметров командной строки
        static struct option long_options[] = {
            {"divide", no_argument, 0, 'd'},
            {"multiply", no_argument, 0, 'm'},
            {0, 0, 0, 0}
        };
        while ((option = getopt_long(argc, argv, "dm", long_options, NULL)) != -1) {
            switch (option) {
            case 'd':
                divide = true;
                break;
            case 'm':
                multiply = true;
                break;
            default:
                std::cout << "Недопустимая опция!" << std::endl;
                return 1;
            }
        }
        // Выполнение операций калькулятора
        float result = std::atof(argv[optind++]);

        while (optind < argc) {
            float operand = std::atof(argv[optind++]);
            if (divide) {
                if (operand == 0) {
                    std::cout << "Ошибка: деление на ноль!" << std::endl;
                    return 1;
                } else {
                    result /= operand;
                }
            }
            if (multiply) {
                result *= operand;
            }
        }
        // Вывод результата
        std::cout << "Результат: " << result << std::endl;
    }
    return 0;
}
