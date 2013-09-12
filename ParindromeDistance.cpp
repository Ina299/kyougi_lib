// �������񕶂ɂ���̂ɕK�v�Ȏ萔�����߂�
// test@uva10739

#include <string> 
#include <algorithm>
using namespace std;

const int N = 1001;
int d[N][N]; // fill(&d[0][0], &d[N-1][N], 0);

// s[i]�`s[j]
// call: parindromeDistance(s, 0, s.length()-1)
int parindromeDistance(const string &s, int i, int j)
{
	if (j-i < 1) return 0;
	if (d[i][j]!=0) return d[i][j];
	if (s[i]==s[j]) {
		d[i][j] = parindromeDistance(s, i+1, j-1);
		return d[i][j];
	}
	else {
		int a = parindromeDistance(s, i+1, j); // �����폜
		a = min(a, parindromeDistance(s, i, j-1)); // �E���폜
		a = min(a, parindromeDistance(s, i+1, j-1)); // ������ύX
		d[i][j] = (1 + a);
		return d[i][j];
	}
}
