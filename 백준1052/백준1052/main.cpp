#include<bitset>
#include<iostream>
using namespace std;
int main() {
	int n, k;
	int ans=0;
	cin >> n >> k;
	while (true) {
		int temp = n;
		// ���� 1�� �������ٴ� �ǹ�
		int firstOnidx = -1;
		//  ����  ������ �ִ� ������ ����
		int cnt=0;
		// ���� ���Ϸ��� �ε����� ��ȣ
		int idx = 0;
		
		//���� ������ ���� ���� ����
		while (temp) {
			if (temp & 1) {
				if (firstOnidx == -1)
					firstOnidx = idx;
				cnt++;
			}
			idx++;
			//���� ��° �ε����� ���ϱ� ���� ���������� 1ĭ �̵�
			temp >>= 1;
		}
		//
		if (cnt <= k) {
			break;
		}
		else {
			//���� ���� ���� ����� �ִ� ������ ���ļ� ����  ũ���� ������ ����� ���� �ݺ��ϴٺ��� �����ִ� ��ū ũ���� ������ �������鼭 ũ�Ⱑ �پ��
			n += (1 << firstOnidx);
			//�� ������  ���� ũ��2¥�� ������ 1��¥�� ���� 2�� ��ģ��
			ans += (1 << firstOnidx);
		}

		
	}
	cout << ans;
}