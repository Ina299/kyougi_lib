// ���茋�����
// test@uva.live-archive3837

const int N = 28;

int prefer[N][N]; // �j���̌�����������([0]={0},[][0]=0)
int fiancee[N]; // �������猩����������([]=0)
int rank[N][N]; // �����̌����������x([][0]=N+1)
bool use[N];

// O(N^2)
void stableMarriage(int n)
{
	fill(fiancee, fiancee+N, 0);
	int next[N] = { 0 }; // ���ԖڂɌ�������������ƌ���������

	for (int m=1; m < N; ++m) {
		if (use[m]==false) continue;
		for (int s=m; s!=0;) {
			++next[s];
			int w = prefer[s][next[s]];
			if (rank[w][s] < rank[w][fiancee[w]]) {
				 swap(fiancee[w], s);
			}
		}
	}
}
