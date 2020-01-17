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
	// 은행코드 bank를 받아서 
	// 해당하는 은행에 저축 총액을 saving을 가지고 계산한다.
	int month = 0;
	int year;
	int mon;
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
	cout << "지금은 2019년 9월 입니다. 언제 저축하셨는지 연도와 월을 입력하시오.(예 : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * saving * (month / 12.0));
	cout << "고객님의 " << bName << "은행 저축 총액은 " << result << "입니다.";
}
void interest::loan(int bank)
{
	// 은행코드 bank를 받아서 
	// 해당하는 은행에 대출 총액을 lend을 가지고 계산한다.
	int month = 0;
	int year;
	int mon;
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
	cout << "지금은 2019년 9월 입니다. 언제 대출하셨는지 연도와 월을 입력하시오.(예 : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * lend * (month / 12.0));
	cout << "고객님의 " << bName << "은행 대출 총액은 " << result << "입니다.";
}
interest::interest(double s, double l)
{
	saving = s;
	lend = l;
}
void sanup_interest::deposit(int bank)
{
	// 은행코드 bank를 받아서 해당하는 은행에 저축 총액을 saving을 가지고 
	// 세금우대 방식으로 계산한다.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	double last_saving;
	string bName = "산업";

	cout << bName << "은행의 저축 금액을 입력하시오 ";
	cin >> amount;
	cout << "지금은 2019년 9월 입니다. 언제 저축하셨는지 연도와 월을 입력하시오.(예 : 2016 03)";
	cin >> year >> mon;
	cout << bName << "은행에서 현재 받은 사업자금의 대출 액수는 얼마입니까? ";
	cin >> last_saving;

	month = (2019 - year) * 12 + (9 - mon);
	
	result = amount + (amount * (business - (last_saving / 1000000000)) * (month / 12.0));
	cout << "고객님의 " << bName << "은행 세금우대 저축 총액은 " << result << "입니다.";
}
sanup_interest::sanup_interest(double s, double l, double b)
	:interest(s, l)
{
	business = b;
}
void sanup_interest::business_loan(int bank)
{
	//이율 business을 가지고 bank은행에 기업대출 총액을 계산한다.
	int month = 0;
	int year;
	int mon;
	double amount;
	double result;
	string bName = "산업";

	cout << bName << "은행의 기업대출 금액을 입력하시오 ";
	cin >> amount;
	cout << "지금은 2019년 9월 입니다. 언제 대출하셨는지 연도와 월을 입력하시오.(예 : 2016 03)";
	cin >> year >> mon;

	month = (2019 - year) * 12 + (9 - mon);

	result = amount + (amount * business * (month / 12.0));
	cout << "고객님의 " << bName << "은행 기업대출 총액은 " << result << "입니다.";
}
interest kookmin(0.03, 0.035), hana(0.032, 0.033),
shinhan(0.031, 0.032);
sanup_interest sanup(0.04, 0.041, 0.04);
void main()
{
	int bank, type;
	cout << "국민이면 1, 하나이면 2, 신한이면 3, 산업이면 4를 입력하시오 ";
	cin >> bank;
	cout << "저축이면 1, 대출이면 2, 사업자금대출이면 3을 입력하시오 ";
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
	case SANUP:
		if (type == DEPOSIT) sanup.deposit(SANUP);
		else if (type == LOAN) sanup.loan(SANUP);
		else sanup.business_loan(SANUP);
		break;
	}
}