#include<iostream>
#include<random>
#include <string>

using namespace std;


class BranchFinances
{
public:

	const float Procent = 0.07;//������� ������
	const float Rate = 50.0;//�������� ������
	const float MAFIP = 270.0; //Minimum Amount For Interest Payment || ����� �������, ����� ������� ����������� ����� ������� �������
	const float PayWorker = 35.0;//�������� ����������
	const float PayPolice = 15.0;//������ ����� �����������
	float Random() //������� ����
	{
		int res;//���������
		res = rand() % 500 + 250;;//��������� ���������� ����� 
		return float(res);//���������� ���������
	}
	float Income = Random();//�������
	float RentCalculation() //������ ������
	{
		if (Income >= MAFIP) //���� ������ > ����� �������, ����� ������� ����������� ����� ������� �������
		{
			return Rate + ((Income - Rate) * Procent); //�������: ������ + ((������� - �����, ����� ������� ����� ������� �������) ? �������)
		}
		else
		{
			return Rate;//�������: ������
		}
	}
	float Expenses() //�������
	{
		return PayWorker + PayPolice + RentCalculation(); //������� �� ����������� + ���. ����������� + ������
	}

	int WhiteIncome() //������ ������(�����) �������
	{
		return Income - Expenses();//������� ������� - �������
	}

	void Check(string name) //����� ����������
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
		cout << "        Rent: " << RentCalculation() << '\n';//���� ������
		cout << "        Pay for Worker:" << PayWorker << '\n';//�� �����������
		cout << "        Pay for MagicPolice:" << PayPolice << '\n';//���. �����������
		cout << "        Total: " << Expenses() << "\n\n";//���. �������
		cout << "     Income: " << Income << "\n\n";//�������
		cout << "  Total: " << WhiteIncome() << "\n\n";//������ �������
		cout << "_____________________________________________________\n";
		cout << "|           Thank you for using our program :       |\n";
		cout << "|                                                   |\n";
		cout << "|                PMFR Magic Edition                 |\n";
		cout << "|                                                   |\n";
		cout << "_____________________________________________________\n";
	}

};
class NewBranch : public BranchFinances //����� NewBranch
{
public://��������� ����� 
	NewBranch(string name)//����������� 
	{
		NameOfBranch = name;//��� = �������� ���
	}
	~NewBranch() //����������
	{
		cout << "Branch Closet";//������� ��������� � ��� ��� ������� ������
	}
	string get_name() //������ ��� �����
	{
		return NameOfBranch;//������� ���
	}
private://��������� ����
	string NameOfBranch;//��� ��������
};
int main() //������� main
{
	srand(time(nullptr));//������ �������
	string TN;//��� ������ ��������
	//���� ����� ��������
	cout << "Name your Branch: ";
	getline(cin, TN);

	NewBranch MyBranch(TN);//����� ������ NewBranch
	MyBranch.Check(MyBranch.get_name());//������� ����������
}