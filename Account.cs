// Шаблон класса
using System;
public class Account<T>{
     
    private T id;
    private double sum;
     
    public Account(T id, double sum){
        this.id = id;
        this.sum = sum;
    }
     
    public T getId() { return id; }
    public double getSum() { return sum; }
    public void setSum(double sum) { this.sum = sum; }
	
	// Работа с делегатом
	delegate void Message(); // 1. Объявляем делегат
	public void Print_MyRating(){
		Message mes; // 2. Создаем переменную делегата
			if ((int)sum > 50)
			{
				mes = GoodRating; // 3. Присваиваем этой переменной адрес метода
			}
			else
			{
				mes = BadRating;
			}
			mes(); // 4. Вызываем метод
    }    
    
    private static void GoodRating()
    {
        Console.WriteLine($"Good Rating");
    }
    private static void BadRating()
    {
        Console.WriteLine($"Bad Rating");
    }
}