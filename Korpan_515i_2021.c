/**
 * @file Korpan_515i_2021.c
 * @author ������� �.�., ��. 515�
 * @date 2 ���� 2021
 * @brief ��������
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_CTYPE, "rus");
	srand(time(0));

	short arr[1000] = { 0 };
	struct {
		unsigned pos;
		unsigned num;
	} zeroCurr = { 0 }, zeroMax = { 0 };
	_Bool is_zeroSeries = 0;

	printf("������:\n");
	for (unsigned i = 0; i < 1000; i++) {
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
		if (arr[i] == 0) {
			zeroCurr.num++;
			if (!is_zeroSeries) {
				zeroCurr.pos = i;
			}
			is_zeroSeries = 1;
		}
		else {
			if (is_zeroSeries && zeroCurr.num > zeroMax.num) {
				zeroMax.pos = zeroCurr.pos;
				zeroMax.num = zeroCurr.num;
			}
			zeroCurr.num = 0;
			is_zeroSeries = 0;
		}
	}
	printf(zeroMax.num == 0 ? "\n����� ���\n\n" : "\n���������� ���������� ����� ������ %u, ��������� �� ������� %u\n\n", zeroMax.num, zeroMax.pos);
}