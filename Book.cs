public interface ICloneable{
    object Clone();
}
public class Book : ICloneable{
 
    public string name;
    public Author author;

    public void setName(string n){ name=n;}
    public string getName(){ return name;}
     
    public void setAuthor(string n){ author.setName(n);}
    public string getAuthor(){ return author.getName();}
 
    public Book(string name, string author){
        this.name = name;
        this.author = new Author(author);
    }
    public Book(string name){
        this.name = name;
    }
    public string toString(){
         
        return "Book '" + name + "' (Author " +  author + ")";
    }
    public object Clone()
    {	
		Book newBook = (Book) base.MemberwiseClone();
		newBook.author=(Author) this.author.Clone() ;
		return newBook;
    }
}