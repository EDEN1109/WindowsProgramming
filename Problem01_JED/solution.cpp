#include <stdio.h>
#define KOOKMIN 1
#define HANA 2
#define SHINHAN 3
#define DEPOSIT 1
#define LOAN 2
struct interest
{
	double saving;
	double lend;
};
struct interest kookmin, hana, shinhan;
void deposit(int bank)
{
	int month;
	double amount;

	// 은행코드를 bank에 받아서 해당하는 은행에 저축 총액을 계산한다.
	if (bank == KOOKMIN) {
		printf("국민은행의 저축 금액을 입력하시오 ");
		scanf_s("%lf", &amount);
		printf("저축 기간은 몇 개월인지 입력하시오 ");
		scanf_s("%d", &month);

		printf("고객님의 국민은행 저축 총액은 %lf입니다.", amount + (amount*kookmin.saving*(month / 12.0)));
	}
	else if (bank == HANA) {
		printf("하나은행의 저축 금액을 입력하시오 ");
		scanf_s("%lf", &amount);
		printf("저축 기간은 몇 개월인지 입력하시오 ");
		scanf_s("%d", &month);

		printf("고객님의 하나은행 저축 총액은 %lf입니다.", amount + (amount*hana.saving*(month / 12.0)));
	}
	else if (bank == SHINHAN) {
		printf("신한은행의 저축 금액을 입력하시오 ");
		scanf_s("%lf", &amount);
		printf("저축 기간은 몇 개월인지 입력하시오 ");
		scanf_s("%d", &month);

		printf("고객님의 신한은행 저축 총액은 %lf입니다.", amount + (amount*shinhan.saving*(month / 12.0)));
	}

}
void loan(int bank)
{
	int month;
	double amount;

	// 은행코드를 bank에 받아서 해당하는 은행에 대출 총액을 계산한다.
	if (bank == KOOKMIN) {
		printf("국민은행의 대출 금액을 입력하시오 ");
		scanf_s("%lf", &amount);
		printf("대출 기간은 몇 개월인지 입력하시오 ");
		scanf_s("%d", &month);

		printf("고객님의 국민은행 대출 총액은 %lf입니다.", amount + (amount*kookmin.lend*(month / 12.0)));
	}
	else if (bank == HANA) {
		printf("하나은행의 대출 금액을 입력하시오 ");
		scanf_s("%lf", &amount);
		printf("대출 기간은 몇 개월인지 입력하시오 ");
		scanf_s("%d", &month);

		printf("고객님의 하나은행 대출 총액은 %lf입니다.", amount + (amount*hana.lend*(month / 12.0)));
	}
	else if (bank == SHINHAN) {
		printf("신한은행의 대출 금액을 입력하시오 ");
		scanf_s("%lf", &amount);
		printf("대출 기간은 몇 개월인지 입력하시오 ");
		scanf_s("%d", &month);

		printf("고객님의 신한은행 대출 총액은 %lf입니다.", amount + (amount*shinhan.lend*(month / 12.0)));
	}
}
void main()
{
	int bank, type;
	printf("국민이면 1, 하나이면 2, 신한이면 3을 입력하시오");
	scanf_s("%d", &bank);
	printf("저축이면 1, 대출이면 2를 입력하시오");
	scanf_s("%d", &type);

	kookmin.lend = 0.04;
	hana.lend = 0.03;
	shinhan.lend = 0.046;
	kookmin.saving = 0.02;
	hana.saving = 0.015;
	shinhan.saving = 0.023;

	switch (bank)
	{
	case KOOKMIN:
		if (type == DEPOSIT) deposit(KOOKMIN);
		else loan(KOOKMIN);
		break;
	case HANA:
		if (type == DEPOSIT) deposit(HANA);
		else loan(HANA);
		break;
	case SHINHAN:
		if (type == DEPOSIT) deposit(SHINHAN);
		else loan(SHINHAN);
		break;
	}
}