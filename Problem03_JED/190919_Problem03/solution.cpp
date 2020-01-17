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
	else if (bank == SANUP) {
		bName = "산업";
	}

	cout << bName << "은행의 저축 금액을 입력하시오 ";
	cin >> amount;
	cout << "저축 기간은 몇 개월인지 입력하시오 ";
	cin >> month;

	result = amount + (amount * saving * (month / 12.0));
	cout << "고객님의 " << bName << "은행 저축 총액은 " << result << "입니다.";
}
void interest::loan()
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
	else if (bank == SANUP) {
		bName = "산업";
	}

	cout << bName << "은행의 대출 금액을 입력하시오 ";
	cin >> amount;
	cout << "대출 기간은 몇 개월인지 입력하시오 ";
	cin >> month;

	result = amount + (amount * lend * (month / 12.0));
	cout << "고객님의 " << bName << "은행 대출 총액은 " << result << "입니다.";
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
	// 이율 business을 가지고 bank은행에 기업대출 총액을 계산한다.
	int month;
	double amount;
	double result;
	string bName = "산업";

	cout << bName << "은행의 기업대출 금액을 입력하시오 ";
	cin >> amount;
	cout << "기업대출 기간은 몇 개월인지 입력하시오 ";
	cin >> month;

	result = amount + (amount * business * (month / 12.0));
	cout << "고객님의 " << bName << "은행 기업대출 총액은 " << result << "입니다.";
}
interest kookmin(KOOKMIN, 0.03, 0.035), hana(HANA, 0.032, 0.033),
shinhan(SHINHAN, 0.031, 0.032);
sanup_interest sanup(SANUP, 0.04, 0.041, 0.04);
void main()
{
	int bank, type;
	cout << "국민이면 1, 하나이면 2, 신한이면 3, 산업이면 4를 입력하시오 ";
	cin >> bank;
	cout << "저축이면 1, 대출이면 2, 사업자금대출이면 3을 입력하시오 ";
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