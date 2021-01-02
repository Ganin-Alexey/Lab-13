#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <sstream>  //include this to use string streams
#include <string>
#include <assert.h>
// Абстрактный класс
 class human{
    public:
        virtual std::string NamePrint() = 0;
        virtual std::string SurnamePrint() = 0;
};

class student : public human{
    public:
        // Дружественная функция
        friend void reset(student &student);
        // Перегрузка <<
        friend std::ostream& operator<< (std::ostream &out, const student &st);
        // Виртуальная функция
        virtual void print_greeting() { std::cout << "I am student"; }
        void print_full_greeting() { print_greeting(); std::cout << " - " << *this << std::endl; }
        // Конструктор без параметров
        student(){
            name = "None_" + std::to_string(num_of_stud);
            surname = "None_" + std::to_string(num_of_stud);
            id = num_of_stud++;
            number_of_phone = 000000;
        }
        // Конструктор с одним параметром
        student(int id_st){
            name = "None";
            surname = "None";
            id = id_st;
            number_of_phone = 000000;
            num_of_stud++;
            /*for (int i = 0; i < 10; i++){
                array_of_ratings[i] = 1 + rand() % 5;
            }*/
        }
        // Конструктор со всеми параметрами
        student(std::string name_st, std::string surname_st, int id_st, int number_of_phone_st){
            try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            name = name_st;
            surname = surname_st;
            // Если пользователь ввел отрицательное число, то выбрасывается исключение
            id = id_st;
            number_of_phone = number_of_phone_st;
            if (id_st < 0.0){
               // throw "Can not take sqrt of negative number";// выбрасывается исключение типа const char*
            }
            if (number_of_phone_st < 0.0){
                throw -1;// выбрасывается исключение типа const char*
            }
            }
             catch (const char* exception) // обработчик исключений типа const char*
            {
                std::cerr << "Error: id < 0" << '\n';
                this->id = 0;
            }
            catch(int) // обработчик исключений типа const char*
            {
                std::cerr << "Error: number_of_phone < 0" << '\n';
                this->number_of_phone = 0;
            }
            num_of_stud++;
        }
        void read(){
            try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            std::cout << "Введите Имя: ";
            std::cin >> name;
            std::cout << "Введите Фамилию: ";
            std::cin >> surname;
            std::cout << "Введите ID: ";
            std::cin >> id;
            // Если пользователь ввел отрицательное число, то выбрасывается исключение
            if (id < 0.0){
                throw "Can not take sqrt of negative number";// выбрасывается исключение типа const char*
            }
            std::cout << "Введите Номер телефона: ";
            std::cin >> number_of_phone;
            if (number_of_phone < 0.0){
                throw -1;// выбрасывается исключение типа const char*
            }
            }
             catch (const char* exception) // обработчик исключений типа const char*
            {
                std::cerr << "Error: id < 0" << '\n';
                this->id = 0;
            }
            catch(int) // обработчик исключений типа const char*
            {
                std::cerr << "Error: number_of_phone < 0" << '\n';
                this->number_of_phone = 0;
            }
        }
        void add(class student st2){
            std::cout << "(" << this->id << " + " << st2.id << ")" << std::endl;
        }
        void NameSurnamePrint(){
            std::cout << this->name << " " << this->surname << std::endl;
        }
        std::string NamePrint() override{
            return this->name;
        }
        std::string SurnamePrint() override{
            return this->surname;
        }
        int NumPhonePrint(){
            return this->number_of_phone;
        }
        /*void RatingPrint(){
            std::cout << "Rating " << this->NamePrint() << ": ";
            for (int i = 0; i < 10; i++){
                std::cout << array_of_ratings[i] << "; ";
            }
            std::cout << std::endl;
        }*/
        // Возврат значения из метода через ссылку (&)
        int& IdPrint(){
            return this->id;
        }
        // Возврат значения из метода через указатель (*)
        int* PhonePrint(){
            return &this->number_of_phone;
        }
        // Перегрузка оператора +
        student operator + (student p1) {
            this->add(p1);
            return *this;
        }

        // Перегрузка оператора ++ (префиксная)
        student operator++ (){
            this->id += 1;
            return *this;
        }
        // Перегрузка оператора ++ (постфиксная)
        student operator++ (int){
            student prev = *this;
            this->id += 1;
            return prev;
        }
        // Статические поля и методы
        static int get_num_of_stud() {return num_of_stud;}
        //student() {num_of_stud++;}

        // Конструктор копирования
        student(const student &copy) :
            name(copy.name), surname(copy.surname), id(copy.id), number_of_phone(copy.number_of_phone)
        {}
        // Перегрузка оператора присваивания
        student& operator= (const student &st)
        {
            // Проверка на самоприсваивание
            if (this == &st)
                return *this;
             // Выполняем копирование значений
             name = st.name;
             surname = st.surname;
             id = st.id;
             number_of_phone = st.number_of_phone;

             // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
             return *this;
        }
    public:
        std::string name;
        std::string surname;
        int id;
        int  number_of_phone;
    protected:
        std::string lable = "Student"; // Приписка(бакалавриат, магистрант итд)
        static int num_of_stud; // Статическое поле
        //int array_of_ratings[10];
};
// Перегрузка оператора <<
std::ostream& operator<< (std::ostream &out, const student &st){
    out << st.name << " " << st.surname << " " << st.id << " " << st.number_of_phone << std::endl;
    return out;
}
// Статические поля и методы
int student::num_of_stud = 0;   // инициализация скрытого статического поля

void reset(student &student){
    // Мы имеем доступ к закрытым членам объектов класса student
    student.id = 0;
}
// Производный класс master(Магистрант) для класса student
class master : public student{
public:
    master() : student ()   // конструктор класса master вызывает конструктор класса student
    {
        lable = "Master";
    }
     //Продемонстрировать в конструкторе производного класса с параметрами вызов конструктора базового класса
    master(std::string name_st, std::string surname_st, int id_st, int number_of_phone_st) : student (name_st, surname_st, id_st, number_of_phone_st){
        lable = "Master";
    }
    // Продемонстрировать перегрузку метода базового класса в производном классе
    // C вызовом метода базового класса
    void NameSurnamePrint(){
         std::cout << this->lable << ": ";
         student::NameSurnamePrint();
    }
    // Без вызова метода базового класса
    std::string Print(){
        std::cout << "This is Master!" << std::endl;
    }

    // Перегрузка оператора присваивания
    master& operator= (student &st){
        // Проверка на самоприсваивание
        if (this == &st)
           return *this;

        student::name = st.NamePrint();
        student::surname = st.SurnamePrint();
        student::number_of_phone = st.NumPhonePrint();
        return *this;
    }
    // Переопределение базовой виртуальной функции
    void print_greeting() { std::cout << std::endl << "I am Master" << std::endl; }
};

// Шаблон класса
template <class T>
class Array_of_ratings{
private:
    int length;
    T *array_of_ratings;
public:
    Array_of_ratings(){
        length = 0;
        array_of_ratings = nullptr;
    }
    Array_of_ratings(int length){
        this->length = length;
        array_of_ratings = new T[length];
    }
    ~Array_of_ratings(){
        delete[] array_of_ratings;
    }
    void Erase(){
        delete[] array_of_ratings;
        // Присваиваем значение nullptr для array_of_ratings, чтобы на выходе не получить висячий указатель!
        array_of_ratings = nullptr;
        length = 0;
    }
    T& operator[](int index){
        assert(index >= 0 && index < length);
        return array_of_ratings[index];
    }
    int getLength(){ return length;}
};

int main(){
    setlocale(LC_ALL, "RUS");
    // Конструктор со всеми параметрами
    student stud_1("Aleks", "Ban", -2, 8913339);
    std::cout << stud_1;

    // Конструктор с одним параметром
    student stud_4(5);
    std::cout << stud_4;
    //stud_4.RatingPrint();

    // Конструктор без параметров
    student stud_5();

    // Возврат значения из метода через ссылку (&) (Вывод)
    std::cout << stud_1.IdPrint() << std::endl;
    std::cout << *stud_1.PhonePrint() << std::endl;

    // Дружественная функция
    reset(stud_1);
    std::cout << stud_1;

    // Перегрузка оператора +
    student stud_2;
    stud_1 + stud_2;

    // Перегрузка оператора ++ (постфиксная и префиксная)
    stud_1++;
    ++stud_1;
    std::cout << stud_1;

    // Статические поля и методы
    std::cout << "Кол-во студентов - " << student::get_num_of_stud() << std::endl;

    student stud_3(99999);
    std::cout << stud_3;

    // Перегрузка оператора присваивания и копирования
    student stud_6("Par1", "-", 777777, 8141241);
    student stud_7("Par2", "-", 888888, 8351411);
    stud_7 = stud_6;
    std::cout << stud_7;


    // ПРИМЕР ГЛУБОКОГО И ПОВЕРХНОСТНОГО КОПИРОВАНИЯ
    typedef struct {
    char *name;
    int value;
    } Node;
    Node n1, n2, n3;
    char name[] = "This is the name";
    n1 = (Node){ name, 1337 };
    n2 = n1; // Неглубокая копия, n2.name указывает на ту же строку, что и n1.name
    n3.value = n1.value;
    n3.name = strdup(n1.name); // Глубокая копия - n3.name идентично n1.name в отношении
                               // только его содержимого, но это уже не тот же указатель
    // Одномерный массив из 15-ти студентов
    student students[15];
    for(int i = 0; i < 15; i++){
       std::cout<< "Student №"  <<  students[i].IdPrint() << ": "<< students[i].SurnamePrint() << std::endl;
    }
    // Двумерный массив студентов
    // Введем переменную кол-во аудиторий - classrooms и пусть оно принимает значение от 1 до 3 и в каждой аудитории по 5 студентов
    int classrooms = (2 + rand() % 5);
    student students_and_classrooms[classrooms][5];
    for(int j = 0; j < classrooms; j++)
        for(int i = 0; i < 5; i++){
           std::cout << "Classroom №" << j + 1 << ": " << students_and_classrooms[j][i].IdPrint() << ": "<< students_and_classrooms[j][i].SurnamePrint() << std::endl;
        }

    // Переопределение родительского метода
    master stud_8;
    stud_8.NameSurnamePrint();
    stud_8.Print();

    //Продемонстрировать в конструкторе производного класса с параметрами вызов конструктора базового класса
    master stud_9("Super", "Puper", 9, 8141241);
    std::cout << stud_9;
    stud_9.NameSurnamePrint();

    // Перегрузка оператора присваивания
    student stud_10("Noob", "Puuup", 10,1412);
    stud_9 = stud_10;
    std::cout << stud_9;

    // Работа с виртуальной функцией
    stud_4.print_full_greeting();
    student x;
    student *px = &x;  // Указатель на базовый класс student
    master y;
    px->print_greeting();  // "I am Student!"
    px = &y;
    px->print_greeting();  // "I am Master!"

    // Работа с шаблонами класса
    Array_of_ratings<int> intArray_of_ratings(5);
	Array_of_ratings<double> doubleArray_of_ratings(5);
	for (int count = 0; count < intArray_of_ratings.getLength(); ++count){
		intArray_of_ratings[count] = 25 + rand() % 100;
		doubleArray_of_ratings[count] = 25.7 + rand() % 100;
	}
	for (int count = intArray_of_ratings.getLength()-1; count >= 0; --count)
		std::cout << intArray_of_ratings[count] << "\t" << doubleArray_of_ratings[count] << '\n';
    return 0;
}
