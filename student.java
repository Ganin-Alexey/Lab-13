public class student extends human{
    String name;
    String surname;
    int id;
    int number_of_phone;
    mouth mouth_of_student;
	protected String label = "Student";
	int [] array_of_ratings = new int[10];
	private static int counter=1; /* Статическое поле */
    /*начало блока инициализатора*/
	// Конструктор без параметров
    student(){
        name = "None" + counter;
        surname = "None" + counter;
        id=counter++;
        number_of_phone = 000000;
    }
    /*конец блока инициализатора*/
	// Конструктор со всеми параметрами
    student(String name, String surname, int number_of_phone, mouth mouth_of_student){
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
                System.out.println(ex.getMessage());
                this.number_of_phone = 0;
            }
    }
	// Конструктор со всеми параметрами
    student(String name, String surname, int number_of_phone){
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
                System.out.println(ex.getMessage());
                this.number_of_phone = 0;
            }
    }
	// Конструктор с одним параметром
    student(int number_of_phone){
        name = "None";
        surname = "None";
        this.id = counter++;
        this.number_of_phone = number_of_phone;
		for (int i = 0; i < 10; i++){
                array_of_ratings[i] = 0;
        }
    }
    void display_st(student st){
        System.out.printf("Name: %s \tSurname: %s\tID: %d\tPhone: %d\n", st.name, st.surname, st.id, st.number_of_phone);
    }
    // Правильное использование this
    void display() {
        display_st(this);
    }
	// Переопределение метода toString()
    @Override
    public String toString() {
        return "Name: " + this.name + "\tSurname: " + this.surname + "\tID: " + this.id + "\tPhone: " + this.number_of_phone + "\n";
    }
	// Возрат значения из метода через вспомогательный класс
    void talk(){
        mouth_of_student.talk();
    }
	void give_number(){
        mouth_of_student.give_number();
    }
	static void get_counter(){
		System.out.printf("Num of student: %d \n", counter);
	}
	void RatingPrint(){
		System.out.printf("Rating %s: ", name);
           for (int i = 0; i < 10; i++){
               array_of_ratings[i] = 0;
			   System.out.printf("%d; ", array_of_ratings[1]);
           }
           System.out.printf("\n");
    }
	int IdPrint(){
		return this.id;
	}
	public String NamePrint(){
		return this.name;
	}
	public String SurnamePrint(){
		return this.surname;
	}
	void NameSurnamePrint(){
		System.out.printf("%s %s\n", this.name, this.surname);
    }
}
// Производный класс master(Магистрант) для класса student
class master extends student{
    master(){
		label = "Master";	
	}
	 //Продемонстрировать в конструкторе производного класса с параметрами вызов конструктора базового класса
    master(String name_st, String surname_st, int number_of_phone_st){
		super(name_st,surname_st,number_of_phone_st);
		label = "Master";
    }
	// Продемонстрировать перегрузку метода базового класса в производном классе
    // C вызовом метода базового класса
	@Override
    void NameSurnamePrint(){
		System.out.printf("%s: ", this.label);
        super.NameSurnamePrint();
    }
    // Без вызова метода базового класса
    void Print(){
		System.out.printf("This is Master!\n");
    }
};
