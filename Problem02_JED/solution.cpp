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
	// 은행코드 bank를 받아서 
	// 해당하는 은행에 저축 총액을 saving을 가지고 계산한다.
	int month;
	double amount;
	double result;
	string bName;

	if (bank == KOOKMIN) {
		bName = "국민";
	}
	else if (bank == HANA) {
		bName = "하나";
	}
	else if (bank == SHINHAN) {
		bName = "신한";
	}

	cout << bName << "은행의 저축 금액을 입력하시오 ";
	cin >> amount;
	cout << "저축 기간은 몇 개월인지 입력하시오 ";
	cin >> month;

	result = amount + (amount*saving*(month / 12.0));
	cout << "고객님의 " << bName << "은행 저축 총액은 " << result << "입니다.";

}
void interest::loan(int bank)
{
	// 은행코드 bank를 받아서 
	// 해당하는 은행에 대출 총액을 lend를 가지고 계산한다.
	int month;
	double amount;
	double result;
	string bName;

	if (bank == KOOKMIN) {
		bName = "국민";
	}
	else if (bank == HANA) {
		bName = "하나";
	}
	else if (bank == SHINHAN) {
		bName = "신한";
	}

	cout << bName << "은행의 대출 금액을 입력하시오 ";
	cin >> amount;
	cout << "대출 기간은 몇 개월인지 입력하시오 ";
	cin >> month;

	result = amount + (amount * lend * (month / 12.0));
	cout << "고객님의 " << bName << "은행 대출 총액은 " << result << "입니다.";
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
	cout << "국민이면 1, 하나이면 2, 신한이면 3을 입력하시오";
	cin >> bank;
	cout << "저축이면 1, 대출이면 2를 입력하시오";
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