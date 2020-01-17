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
	int bank;
	double saving;
	double lend;
public:
	void deposit();
	void loan();
	interest(int bk, double s, double l);
};
class sanup_interest :public interest
{
	double business;
public:
	void business_loan();
	sanup_interest(int bk, double s, double l, double b);
};
void interest::deposit()
{
	// �����ڵ� bank�� �޾Ƽ� 
	// �ش��ϴ� ���࿡ ���� �Ѿ��� saving�� ������ ����Ѵ�.
	int month;
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
	cout << "���� �Ⱓ�� �� �������� �Է��Ͻÿ� ";
	cin >> month;

	result = amount + (amount * saving * (month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";
}
void interest::loan()
{
	// �����ڵ� bank�� �޾Ƽ� 
	// �ش��ϴ� ���࿡ ���� �Ѿ��� lend�� ������ ����Ѵ�.
	int month;
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
	cout << "���� �Ⱓ�� �� �������� �Է��Ͻÿ� ";
	cin >> month;

	result = amount + (amount * lend * (month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";
}
interest::interest(int bk, double s, double l)
{
	bank = bk;
	saving = s;
	lend = l;
}
sanup_interest::sanup_interest(int bk, double s, double l, double b)
	:interest(bk, s, l)
{
	business = b;
}
void sanup_interest::business_loan()
{
	// ���� business�� ������ bank���࿡ ������� �Ѿ��� ����Ѵ�.
	int month;
	double amount;
	double result;
	string bName = "���";

	cout << bName << "������ ������� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "������� �Ⱓ�� �� �������� �Է��Ͻÿ� ";
	cin >> month;

	result = amount + (amount * business * (month / 12.0));
	cout << "������ " << bName << "���� ������� �Ѿ��� " << result << "�Դϴ�.";
}
interest kookmin(KOOKMIN, 0.03, 0.035), hana(HANA, 0.032, 0.033),
shinhan(SHINHAN, 0.031, 0.032);
sanup_interest sanup(SANUP, 0.04, 0.041, 0.04);
void main()
{
	int bank, type;
	cout << "�����̸� 1, �ϳ��̸� 2, �����̸� 3, ����̸� 4�� �Է��Ͻÿ� ";
	cin >> bank;
	cout << "�����̸� 1, �����̸� 2, ����ڱݴ����̸� 3�� �Է��Ͻÿ� ";
	cin >> type;
	switch (bank) {
	case KOOKMIN:
		if (type == DEPOSIT) kookmin.deposit();
		else kookmin.loan();
		break;
	case HANA:
		if (type == DEPOSIT) hana.deposit();
		else hana.loan();
		break;
	case SHINHAN:
		if (type == DEPOSIT) shinhan.deposit();
		else shinhan.loan();
		break;
	case SANUP:
		if (type == DEPOSIT) sanup.deposit();
		else if (type == LOAN) sanup.loan();
		else sanup.business_loan();
		break;
	}
}