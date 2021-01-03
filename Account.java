// Шаблон класса
class Account<T,E>{
     
    private T id;
    private E sum;
     
    Account(T id, E sum){
        this.id = id;
        this.sum = sum;
    }
     
    public T getId() { return id; }
    public E getSum() { return sum; }
    public void setSum(E sum) { this.sum = sum; }
}