#include <iostream>

using namespace std;

int main() {
	uint32_t N, R;
	uint64_t M=0;
	cin >> N >> R;
	for(uint32_t i = 0; i < N; i++){
		uint64_t W,H,D;
		cin >> W >> H >> D;
		M+=W*H*D*R;
	}
	cout << M;
	return 0;
}
