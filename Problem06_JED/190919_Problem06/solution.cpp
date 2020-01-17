#include <iostream>
using namespace std;
using std::cout;
#define KOOKMIN 1
#define HANA 2
#define SHINHAN 3
#define SANUP 4
#define DEPOSIT 1
#define LOAN 2
#define BUSINESS 3
class interest
{
protected:
	double saving;
	double lend;
public:
	virtual void deposit(int);
	void loan(int);
	void loan(int, int);
	interest(double s, double l);
};
class sanup_interest :public interest
{
	double business;
public:
	void deposit(int);
	void business_loan(int);
	sanup_interest(double s, double l, double b);
};
void interest::deposit(int bank)
{
	// �����ڵ� bank�� �޾Ƽ� 
	// �ش��ϴ� ���࿡ ���� �Ѿ��� saving�� ������ ����Ѵ�.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	string bName;

	if (bank == KOOKMIN) {
		bName = "����";
	}
	else if (bank == HANA) {
		bName = "�ϳ�";
	}
	else if (bank == SHINHAN) {
		bName = "����";
	}

	cout << bName << "������ ���� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "������ 2019�� 9�� �Դϴ�. ���� �����ϼ̴��� ������ ���� �Է��Ͻÿ�.(�� : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * saving * (month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";
}
void interest::loan(int bank)
{
	// �����ڵ� bank�� �޾Ƽ� 
	// �ش��ϴ� ���࿡ ���� �Ѿ��� lend�� ������ ����Ѵ�.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	string bName;

	if (bank == KOOKMIN) {
		bName = "����";
	}
	else if (bank == HANA) {
		bName = "�ϳ�";
	}
	else if (bank == SHINHAN) {
		bName = "����";
	}
	else if (bank == SANUP) {
		bName = "���";
	}

	cout << bName << "������ ���� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "������ 2019�� 9�� �Դϴ�. ���� �����ϼ̴��� ������ ���� �Է��Ͻÿ�.(�� : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * lend * (month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";

}
void interest::loan(int bank, int special)
{
	// �����ڵ� bank�� �ް� ���ڰ��� ���� special�� �޾Ƽ� 
	// �����Ѿ��� lend�� ������ ����Ѵ�.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	string bName;

	if (bank == KOOKMIN) {
		bName = "����";
	}
	else if (bank == HANA) {
		bName = "�ϳ�";
	}
	else if (bank == SHINHAN) {
		bName = "����";
	}
	else if (bank == SANUP) {
		bName = "���";
	}

	cout << bName << "������ ���� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "������ 2019�� 9�� �Դϴ�. ���� �����ϼ̴��� ������ ���� �Է��Ͻÿ�.(�� : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * (lend - ((4 - special) / 200.0)) * (month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";
}
interest::interest(double s, double l)
{
	saving = s;
	lend = l;
}
void sanup_interest::deposit(int bank)
{
	// �����ڵ� bank�� �޾Ƽ� �ش��ϴ� ���࿡ ���� �Ѿ��� saving�� ������ 
	// ���ݿ�� ������� ����Ѵ�.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	double last_saving;
	string bName = "���";

	cout << bName << "������ ���� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "������ 2019�� 9�� �Դϴ�. ���� �����ϼ̴��� ������ ���� �Է��Ͻÿ�.(�� : 2016 03)";
	cin >> year >> mon;
	cout << bName << "���࿡�� ���� ���� ����ڱ��� ���� �׼��� ���Դϱ�? ";
	cin >> last_saving;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * (business - (last_saving / 1000000000)) * (month / 12.0));
	cout << "������ " << bName << "���� ���ݿ�� ���� �Ѿ��� " << result << "�Դϴ�.";
}
sanup_interest::sanup_interest(double s, double l, double b)
	:interest(s, l)
{
	business = b;
}
void sanup_interest::business_loan(int bank)
{
	//���� business�� ������ bank���࿡ ������� �Ѿ��� ����Ѵ�.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	string bName = "���";

	cout << bName << "������ ������� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "������ 2019�� 9�� �Դϴ�. ���� �����ϼ̴��� ������ ���� �Է��Ͻÿ�.(�� : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * business * (month / 12.0));
	cout << "������ " << bName << "���� ������� �Ѿ��� " << result << "�Դϴ�.";
}
sanup_interest* Banks;
void main()
{
	int bank, type, special;
	cout << "�����̸� 1, �ϳ��̸� 2, �����̸� 3, ����̸� 4�� �Է��Ͻÿ� ";
	cin >> bank;
	cout << "�����̸� 1, �����̸� 2, ����ڱݴ����̸� 3�� �Է��Ͻÿ� ";
	cin >> type;
	switch (bank) {
	case KOOKMIN:
		Banks = (sanup_interest*) new interest(0.03, 0.035);
		break;
	case HANA:
		Banks = (sanup_interest*) new interest(0.032, 0.033);
		break;
	case SHINHAN:
		Banks = (sanup_interest*) new interest(0.031, 0.032);
		break;
	case SANUP:
		Banks = new sanup_interest(0.04, 0.041, 0.04);
		break;
	}
	if (type == DEPOSIT)
		Banks->deposit(bank);
	else if (type == LOAN)
	{
		cout << "1.����� 2.����� 3.���ҵ��� 4.�ش���� �� �����Ͻÿ�";
		cin >> special;
		if (special == 4)
			Banks->loan(bank);
		else
			Banks->loan(bank, special);
	}
	else if (type == BUSINESS)
		Banks->business_loan(bank);
}