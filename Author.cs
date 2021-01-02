public class Author : ICloneable{
 
    public string name;
     
    public void setName(string n){ name=n;}
    public string getName(){ return name;}
     
    public Author(string name){
     
        this.name=name;
    }
	public object Clone()
    {
        return this.MemberwiseClone();
    }
}