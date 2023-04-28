#include<iostream>
#include<random>
#include <string>

using namespace std;


class BranchFinances
{
public:

	const float Procent = 0.07;//Процент Ставки
	const float Rate = 50.0;//Основная Ставка
	const float MAFIP = 270.0; //Minimum Amount For Interest Payment || Сумма выручки, сверх которой Олливандеру нужно платить процент
	const float PayWorker = 35.0;//Зарплата сотрудника
	const float PayPolice = 15.0;//Оплата Услуг Мракоборцев
	float Random() //функция ГПСЧ
	{
		int res;//Результат
		res = rand() % 500 + 250;;//Выявление случайного числа 
		return float(res);//Возвращаем Результат
	}
	float Income = Random();//Прибыль
	float RentCalculation() //Расчёт Аренды
	{
		if (Income >= MAFIP) //Если Аренда > Сумма выручки, сверх которой Олливандеру нужно платить процент
		{
			return Rate + ((Income - Rate) * Procent); //Вернуть: Ставка + ((Прибыль - Сумма, сверх которой нужно платить Процент) × Процент)
		}
		else
		{
			return Rate;//Вернуть: Ставка
		}
	}
	float Expenses() //Расходы
	{
		return PayWorker + PayPolice + RentCalculation(); //Вернуть ЗП Сотрудников + Усл. Мракоборцов + Аренда
	}

	int WhiteIncome() //Расчёт Чистой(Белой) Прибыли
	{
		return Income - Expenses();//Вернуть Прибыль - Расходы
	}

	void Check(string name) //Вывод информации
	{
		cout << "_____________________________________________________\n";
		cout << "|Program for Monitor Finance Resources Magic Edition|\n";
		cout << "|                                                   |\n";
		cout << "|       By Danila Shaykevich (MemStudio/NotBot)     |\n";
		cout << "|                                                   |\n";
		cout << "_____________________________________________________\n\n";
		cout << "  Hello: " << name << "\n\n";
		cout << "  Your Result: \n\n";
		cout << "     Expenses: \n\n";
		cout << "        Rent: " << RentCalculation() << '\n';//Цена Аренды
		cout << "        Pay for Worker:" << PayWorker << '\n';//ЗП сотрудников
		cout << "        Pay for MagicPolice:" << PayPolice << '\n';//Усл. Мракоборцов
		cout << "        Total: " << Expenses() << "\n\n";//Общ. Расходы
		cout << "     Income: " << Income << "\n\n";//Прибыль
		cout << "  Total: " << WhiteIncome() << "\n\n";//Чистая Прибыль
		cout << "_____________________________________________________\n";
		cout << "|           Thank you for using our program :       |\n";
		cout << "|                                                   |\n";
		cout << "|                PMFR Magic Edition                 |\n";
		cout << "|                                                   |\n";
		cout << "_____________________________________________________\n";
	}

};
class NewBranch : public BranchFinances //Класс NewBranch
{
public://Публичная часть 
	NewBranch(string name)//Конструктор 
	{
		NameOfBranch = name;//Имя = введённое имя
	}
	~NewBranch() //Деструктор
	{
		cout << "Branch Closet";//Вывести сообщение о том что магазин Закрыт
	}
	string get_name() //Геттер для Имени
	{
		return NameOfBranch;//Вернуть Имя
	}
private://Приватные поля
	string NameOfBranch;//Имя магазина
};
int main() //Функция main
{
	srand(time(nullptr));//Основа Рандома
	string TN;//Имя Нового Магазина
	//Ввод Имени Магазина
	cout << "Name your Branch: ";
	getline(cin, TN);

	NewBranch MyBranch(TN);//Новый объект NewBranch
	MyBranch.Check(MyBranch.get_name());//Вывести Информацию
}