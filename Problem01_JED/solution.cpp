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

	// �����ڵ带 bank�� �޾Ƽ� �ش��ϴ� ���࿡ ���� �Ѿ��� ����Ѵ�.
	if (bank == KOOKMIN) {
		printf("���������� ���� �ݾ��� �Է��Ͻÿ� ");
		scanf_s("%lf", &amount);
		printf("���� �Ⱓ�� �� �������� �Է��Ͻÿ� ");
		scanf_s("%d", &month);

		printf("������ �������� ���� �Ѿ��� %lf�Դϴ�.", amount + (amount*kookmin.saving*(month / 12.0)));
	}
	else if (bank == HANA) {
		printf("�ϳ������� ���� �ݾ��� �Է��Ͻÿ� ");
		scanf_s("%lf", &amount);
		printf("���� �Ⱓ�� �� �������� �Է��Ͻÿ� ");
		scanf_s("%d", &month);

		printf("������ �ϳ����� ���� �Ѿ��� %lf�Դϴ�.", amount + (amount*hana.saving*(month / 12.0)));
	}
	else if (bank == SHINHAN) {
		printf("���������� ���� �ݾ��� �Է��Ͻÿ� ");
		scanf_s("%lf", &amount);
		printf("���� �Ⱓ�� �� �������� �Է��Ͻÿ� ");
		scanf_s("%d", &month);

		printf("������ �������� ���� �Ѿ��� %lf�Դϴ�.", amount + (amount*shinhan.saving*(month / 12.0)));
	}

}
void loan(int bank)
{
	int month;
	double amount;

	// �����ڵ带 bank�� �޾Ƽ� �ش��ϴ� ���࿡ ���� �Ѿ��� ����Ѵ�.
	if (bank == KOOKMIN) {
		printf("���������� ���� �ݾ��� �Է��Ͻÿ� ");
		scanf_s("%lf", &amount);
		printf("���� �Ⱓ�� �� �������� �Է��Ͻÿ� ");
		scanf_s("%d", &month);

		printf("������ �������� ���� �Ѿ��� %lf�Դϴ�.", amount + (amount*kookmin.lend*(month / 12.0)));
	}
	else if (bank == HANA) {
		printf("�ϳ������� ���� �ݾ��� �Է��Ͻÿ� ");
		scanf_s("%lf", &amount);
		printf("���� �Ⱓ�� �� �������� �Է��Ͻÿ� ");
		scanf_s("%d", &month);

		printf("������ �ϳ����� ���� �Ѿ��� %lf�Դϴ�.", amount + (amount*hana.lend*(month / 12.0)));
	}
	else if (bank == SHINHAN) {
		printf("���������� ���� �ݾ��� �Է��Ͻÿ� ");
		scanf_s("%lf", &amount);
		printf("���� �Ⱓ�� �� �������� �Է��Ͻÿ� ");
		scanf_s("%d", &month);

		printf("������ �������� ���� �Ѿ��� %lf�Դϴ�.", amount + (amount*shinhan.lend*(month / 12.0)));
	}
}
void main()
{
	int bank, type;
	printf("�����̸� 1, �ϳ��̸� 2, �����̸� 3�� �Է��Ͻÿ�");
	scanf_s("%d", &bank);
	printf("�����̸� 1, �����̸� 2�� �Է��Ͻÿ�");
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