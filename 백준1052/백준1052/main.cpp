#include<bitset>
#include<iostream>
using namespace std;
int main() {
	int n, k;
	int ans=0;
	cin >> n >> k;
	while (true) {
		int temp = n;
		// 현재 1을 못만났다는 의미
		int firstOnidx = -1;
		//  내가  가지고 있는 물병의 갯수
		int cnt=0;
		// 내가 비교하려는 인덱스의 번호
		int idx = 0;
		
		//현재 물병의 수를 세는 로직
		while (temp) {
			if (temp & 1) {
				if (firstOnidx == -1)
					firstOnidx = idx;
				cnt++;
			}
			idx++;
			//다음 번째 인덱스를 비교하기 위해 오른쪽으로 1칸 이동
			temp >>= 1;
		}
		//
		if (cnt <= k) {
			break;
		}
		else {
			//가장 작은 양이 담겨져 있는 물병을 합쳐서 다음  크기의 물병을 만들기 위함 반복하다보면 원래있던 더큰 크기의 물병과 합쳐지면서 크기가 줄어듬
			n += (1 << firstOnidx);
			//산 물병의  갯수 크기2짜리 물병은 1개짜리 물병 2개 합친것
			ans += (1 << firstOnidx);
		}

		
	}
	cout << ans;
}