using System;
namespace HelloApp{
// Абстрактный класс
public abstract class human{
    public abstract String NamePrint();
    public abstract String SurnamePrint();
};
// Реализация интерфейса
interface person {
    void NameSurnamePrint();
}
public class student : human, person{
	public string name;
    public string surname;
	private int id = 0;
    public int ID {
		get{ return id;}
		set{
			if(value < 0){ id = 0;}
			else id = value;
		}
	}
    public int number_of_phone;
    public mouth mouth_of_student;
	public int [] array_of_ratings = new int[10];
	public  string label = "Student";
	private static int counter = 1;
	// Конструктор без параметров
	public student()
    {
        this.name = "None" + counter;
	    this.surname = "None" + counter;
		this.ID = counter++;
	    this.number_of_phone = 0000000;
    }
	// Конструктор со всеми параметрами
    public student(string name, string surname, int number_of_phone, mouth mouth_of_student)
    {
        try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            this.name = name;
			this.surname = surname;
			this.id = counter++;
			this.number_of_phone = number_of_phone;
			this.mouth_of_student = mouth_of_student;
            if (number_of_phone < 0){
                throw new Exception("The Number_of_phone is less than 0");// выбрасывается исключение типа const char*
            }
            }
             catch (Exception ex) // обработчик исключений типа const char*
            {
				Console.WriteLine($"{ex.Message}\n");
                this.number_of_phone = 0;
            }
    }
	// Конструктор со всеми параметрами
    public student(string name, string surname, int number_of_phone)
    {
        try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
            {
            this.name = name;
			this.surname = surname;
			this.id = counter++;
			this.number_of_phone = number_of_phone;
            if (number_of_phone < 0){
                throw new Exception("The Number_of_phone is less than 0");// выбрасывается исключение типа const char*
            }
            }
             catch (Exception ex) // обработчик исключений типа const char*
            {
				Console.WriteLine($"{ex.Message}\n");
                this.number_of_phone = 0;
            }
    }
	// Конструктор с одним параметром
	public student(int number_of_phone){
        this.name = "None";
	    this.surname = "None";
		this.ID = counter++;
	    this.number_of_phone = number_of_phone;
		for (int i = 0; i < 10; i++){
                array_of_ratings[i] = 0;
        }
    }
	// Перегрузка оператора +
    public static student operator + (student p1, student p2) {
		mouth mouth_nan = new mouth("Hello", 1);
        return new student(p1.name + p2.name, p1.surname + p2.surname, p1.number_of_phone + p2.number_of_phone, mouth_nan);
    }
    // Перегрузка оператора ++ (префиксная)
    public static student operator ++(student x){
        return new student(x.name, x.surname + " - Student", x.number_of_phone, x.mouth_of_student);
    }
	// Правильное использование this
	private void display_st(student st){
        Console.WriteLine($"Name: {st.name}  Surname: {st.surname} ID: {st.ID}  Phone: {st.number_of_phone}\n");
    }
    public void display() {
        display_st(this);
    }
	// Переопределение метода toString()
	public override string ToString(){
        return "Name: " + this.name + "\tSurname: " + this.surname + "\tID: " + this.id + "\tPhone: " + this.number_of_phone + "\n";
    }
    public void talk(){
        mouth_of_student.talk();
    }
	public static void get_counter(){
		Console.WriteLine($"Num of student:{student.counter}\n", student.counter);
	}
	public void RatingPrint(){
		Console.WriteLine($"Rating {name}: ");
           for (int i = 0; i < 10; i++){
               array_of_ratings[i] = 0;
			   Console.WriteLine($"{array_of_ratings[1]}; ");
           }
		   Console.WriteLine($"\n");
        }
	public int IdPrint(){
		return this.ID;
	}
	public override string NamePrint(){
		return this.name;
	}
	public override string SurnamePrint(){
		return this.surname;
	}
	public virtual void NameSurnamePrint(){
		Console.WriteLine($"{this.name} {this.surname}\n");
    }
}
// Производный класс master(Магистрант) для класса student
public class master : student, person{
    public master(){
		label = "Master";
	}
	 //Продемонстрировать в конструкторе производного класса с параметрами вызов конструктора базового класса
    public master(String name_st, String surname_st, int number_of_phone_st) : base(name_st,surname_st,number_of_phone_st){
		label = "Master";
    }
	// Продемонстрировать перегрузку метода базового класса в производном классе
    // C вызовом метода базового класса
	public override void NameSurnamePrint(){
		Console.Write($"{this.label}: ");
        base.NameSurnamePrint();
    }
    // Без вызова метода базового класса
    public void Print(){
		Console.WriteLine($"This is Master!\n");
    }
};
}