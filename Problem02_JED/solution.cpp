#include <iostream>
using namespace std;
using std::cout;
#define KOOKMIN 1
#define HANA 2
#define SHINHAN 3
#define DEPOSIT 1
#define LOAN 2
class interest
{
protected:
	double saving;
	double lend;
public:
	void deposit(int);
	void loan(int);
	interest(double s, double l);
};
void interest::deposit(int bank)
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

	cout << bName << "������ ���� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "���� �Ⱓ�� �� �������� �Է��Ͻÿ� ";
	cin >> month;

	result = amount + (amount*saving*(month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";

}
void interest::loan(int bank)
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

	cout << bName << "������ ���� �ݾ��� �Է��Ͻÿ� ";
	cin >> amount;
	cout << "���� �Ⱓ�� �� �������� �Է��Ͻÿ� ";
	cin >> month;

	result = amount + (amount * lend * (month / 12.0));
	cout << "������ " << bName << "���� ���� �Ѿ��� " << result << "�Դϴ�.";
}
interest::interest(double s, double l)
{
	saving = s;
	lend = l;
}
interest kookmin(0.03, 0.035), hana(0.032, 0.033),
shinhan(0.031, 0.032);
void main()
{
	int bank, type;
	cout << "�����̸� 1, �ϳ��̸� 2, �����̸� 3�� �Է��Ͻÿ�";
	cin >> bank;
	cout << "�����̸� 1, �����̸� 2�� �Է��Ͻÿ�";
	cin >> type;
	switch (bank) {
	case KOOKMIN:
		if (type == DEPOSIT) kookmin.deposit(KOOKMIN);
		else kookmin.loan(KOOKMIN);
		break;
	case HANA:
		if (type == DEPOSIT) hana.deposit(HANA);
		else hana.loan(HANA);
		break;
	case SHINHAN:
		if (type == DEPOSIT) shinhan.deposit(SHINHAN);
		else shinhan.loan(SHINHAN);
		break;
	}
}