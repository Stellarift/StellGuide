#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//общие функции

const int PHONE_LENGTH = 20;

//функция для копирования строки
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//функция для сравнения строк
int compareStrings(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

//функция для обмена двух строк
void swapPhones(char a[], char b[]) {
    char temp[PHONE_LENGTH];
    copyString(temp, a);
    copyString(a, b);
    copyString(b, temp);
}

//функция для копирования массива чисел
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

//задание 1 - справочник
const int SIZE = 5;

void printData(char mobile[][PHONE_LENGTH], char home[][PHONE_LENGTH]) {
    cout << "Мобильные номера:\tДомашние номера:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << mobile[i] << "\t\t\t" << home[i] << endl;
    }
}

void sortByMobile(char mobile[][PHONE_LENGTH], char home[][PHONE_LENGTH]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (compareStrings(mobile[j], mobile[j + 1]) > 0) {
                swapPhones(mobile[j], mobile[j + 1]);
                swapPhones(home[j], home[j + 1]);
            }
        }
    }
}

void sortByHome(char mobile[][PHONE_LENGTH], char home[][PHONE_LENGTH]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (compareStrings(home[j], home[j + 1]) > 0) {
                swapPhones(home[j], home[j + 1]);
                swapPhones(mobile[j], mobile[j + 1]);
            }
        }
    }
}

void task1() {
    cout << "задание 1-телефонный справочник" << endl;

    char mobile[SIZE][PHONE_LENGTH];
    char home[SIZE][PHONE_LENGTH];

    //ввод данных
    cout << "Введите " << SIZE << " мобильных номеров и домашних номеров:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Запись " << i + 1 << ":" << endl;
        cout << "Мобильный номер: ";
        cin >> mobile[i];
        cout << "Домашний номер: ";
        cin >> home[i];
    }

    int choice;
    do {
        cout << "\nМЕНЮ" << endl;
        cout << "1. Отсортировать по мобильным номерам" << endl;
        cout << "2. Отсортировать по домашним номерам" << endl;
        cout << "3. Вывести все данные" << endl;
        cout << "4. Вернуться в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sortByMobile(mobile, home);
            cout << "Данные отсортированы по мобильным номерам!" << endl;
            break;
        case 2:
            sortByHome(mobile, home);
            cout << "Данные отсортированы по домашним номерам!" << endl;
            break;
        case 3:
            printData(mobile, home);
            break;
        case 4:
            cout << "Возврат в главное меню." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 4);
}

//задание 2-усовершенствованная сортировка
void task2() {
    cout << "задание 2-усовершенствованная сортировка" << endl;

    const int ARRAY_SIZE = 10;
    int arr[ARRAY_SIZE];

    //ввод массива
    cout << "Введите " << ARRAY_SIZE << " элементов массива:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nИсходный массив: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //усовершенствованная сортировка пузырьком
    int totalSwaps = 0;
    bool sorted = false;

    for (int i = 0; i < ARRAY_SIZE - 1 && !sorted; i++) {
        int swapsInStep = 0;
        sorted = true;

        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapsInStep++;
                totalSwaps++;
                sorted = false;
            }
        }

        cout << "Шаг " << i + 1 << ": перестановок = " << swapsInStep << endl;

        if (sorted) {
            cout << "Массив отсортирован досрочно!" << endl;
        }
    }

    cout << "Всего перестановок: " << totalSwaps << endl;
    cout << "Отсортированный массив: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//задание 3 - сортировка опалий

//функция переворота
void flip(int arr[], int i) {
    int start = 0;
    while (start < i) {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

//функция для поиска индекса максимального элемента
int findMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void task3() {
    cout << "задание 3 - сортировка опалий" << endl;

    const int STACK_SIZE = 6;
    int arr[STACK_SIZE];

    cout << "Введите " << STACK_SIZE << " радиусов опалий (снизу вверх):" << endl;
    for (int i = 0; i < STACK_SIZE; i++) {
        cout << "Уровень " << i + 1 << " (снизу): ";
        cin >> arr[i];
    }

    cout << "\nИсходная стопка опалий (снизу вверх): ";
    for (int i = 0; i < STACK_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nПроцесс сортировки:" << endl;
    int operations = 0;

    for (int currSize = STACK_SIZE; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);

        if (maxIndex != currSize - 1) {
            if (maxIndex != 0) {
                cout << "Переворот до позиции " << maxIndex + 1 << ": ";
                flip(arr, maxIndex);
                operations++;

                for (int i = 0; i < STACK_SIZE; i++) cout << arr[i] << " ";
                cout << endl;
            }

            cout << "Переворот до позиции " << currSize << ": ";
            flip(arr, currSize - 1);
            operations++;

            for (int i = 0; i < STACK_SIZE; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }

    cout << "Всего операций переворота: " << operations << endl;
    cout << "Отсортированная стопка (снизу вверх по убыванию): ";
    for (int i = 0; i < STACK_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//задание 4 - сравнение сортировок

//усовершенствованная пузырьковая сортировка
int bubbleSort(int arr[], int n) {
    int swaps = 0;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return swaps;
}

//сортировка выбором
int selectionSort(int arr[], int n) {
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    return swaps;
}

//функция для заполнения массива случайными числами
void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void task4() {
    cout << "задание 4 - сравнение сортировок" << endl;

    const int ARRAY_SIZE = 1000;
    const int TEST_COUNT = 10;

    srand(time(NULL));

    int totalBubbleSwaps = 0;
    int totalSelectionSwaps = 0;

    cout << "Тестирование на " << TEST_COUNT << " массивах по " << ARRAY_SIZE << " элементов:" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int test = 0; test < TEST_COUNT; test++) {
        int original[ARRAY_SIZE];
        int arr1[ARRAY_SIZE];
        int arr2[ARRAY_SIZE];

        fillRandom(original, ARRAY_SIZE);
        copyArray(original, arr1, ARRAY_SIZE);
        copyArray(original, arr2, ARRAY_SIZE);

        int bubbleSwaps = bubbleSort(arr1, ARRAY_SIZE);
        int selectionSwaps = selectionSort(arr2, ARRAY_SIZE);

        totalBubbleSwaps += bubbleSwaps;
        totalSelectionSwaps += selectionSwaps;

        cout << "Тест " << test + 1 << ": ";
        cout << "Пузырьковая = " << bubbleSwaps << " перестановок, ";
        cout << "Выбором = " << selectionSwaps << " перестановок" << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << "Среднее число перестановок:" << endl;
    cout << "Пузырьковая сортировка: " << totalBubbleSwaps / TEST_COUNT << endl;
    cout << "Сортировка выбором: " << totalSelectionSwaps / TEST_COUNT << endl;
}

//главное меню
int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    do {
        cout << "главное меню" << endl;
        cout << "1. Телефоный справочник" << endl;
        cout << "2. Усовершенствованная сортировка" << endl;
        cout << "3. Сортировка опалий" << endl;
        cout << "4. Сравнение сортировок" << endl;
        cout << "5. Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            cout << "Выход из программы" << endl;
            break;
        default:
            cout << "Неверно" << endl;
        }
    } while (choice != 5);
    return 0;
}
