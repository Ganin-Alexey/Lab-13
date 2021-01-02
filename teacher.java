// Реализация интерфейса
interface person {
    public void NameSurnamePrint();
}
public class teacher extends human implements person, Cloneable { // Реализуем клонирование через интерфейс Cloneable
	String name;
    String surname;
	teacher(){
        name = "None";
        surname = "None";
    }
	teacher(String name, String surname){
        this.name = name;
        this.surname = surname;
    }
	public String NamePrint(){
		return this.name;
	}
	public String SurnamePrint(){
		return this.surname;
	}
	public void NameSurnamePrint(){
		System.out.printf("%s %s\n", this.name, this.surname);
    }
	public void setName(String name){
		this.name = name;
    }
	public teacher clone() throws CloneNotSupportedException{
      
        return (teacher) super.clone();
    }
}