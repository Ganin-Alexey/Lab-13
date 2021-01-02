class Author implements Cloneable{
 
    private String name;
     
    public void setName(String n){ name=n;}
    public String getName(){ return name;}
     
    public Author(String name){
     
        this.name=name;
    }
	@Override
	public Author clone() throws CloneNotSupportedException{
     
        return (Author) super.clone();
    }
}