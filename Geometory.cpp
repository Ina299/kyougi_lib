
static const double PI = acos(0.0)*2.0;

#define EQ(a,b) (abs((a)-(b)) < EPS)

typedef std::complex<double> P;
typedef P V;

bool lessP(const P &a, const P &b)
{
	if (a.real() != b.real()) return a.real() < b.real();
	return a.imag() < b.imag();
}

struct Line
{
	P p1, p2;
	Line(const P &a, const P &b)
		: p1(a), p2(b)
	{}
};

typedef Line Segment;


// �@���x�N�g��
V normalV(const V &a)
{
	return a * P(0, 1);
	//return a * P(0, -1);
}

// �P�ʖ@���x�N�g��
V unitNormalV(const V &a)
{
	return (a * P(0, 1)) / abs(a);
	//return (a * P(0, -1)) / abs(a);
}

// ����
double dot(const V &a, const V &b)
{
	return (a.real() * b.real() + a.imag() * b.imag());
}


double areaOfPolygon(const vector<P> &pt)
{
	double s = 0.0;
	for (int i=0; i < pt.size()-1; i++) {
		s += cross(pt[i], pt[i+1]);
	}
	return abs(s / 2);
}

// �^����ꂽ�Q�̃x�N�g�������p�x(Rad)��Ԃ�
double getAngle(const V &a, const V &b)
{
	return acos(dot(a, b) / (abs(a)*abs(b)));
}

// test@���낢��
double getAngle(Segment &s1, Segment &s2)
{
	P p = (s1.dst-s1.src) / (s2.dst-s2.src);
	return arg(p);
}

// test@���낢��
double getAngle(const P &a, const P &b, const P &c)
{
    P p1 = a-b;
    P p2 = c-b;
    return arg(p1/p2);
}


// 2�����̒��𔻒� => dot(a, b) = 0
bool isOrth(const V &a, const V &b)
{
	return EQ(dot(a, b), 0.0);
}

// 2�����̕��s���� => cross(a, b) = 0
bool isParallel(const V &a, const V &b)
{
	return EQ(cross(a, b), 0.0);
}

// a,b��ʂ钼����c,d��ʂ钼�������������ׂ�
// test@uva378
bool isSameLine(const Line &a, const Line &b)
{
	return abs(cross(a.p2-a.p1, b.p1-a.p1)) < EPS;
}

// 2�����̕��s����
// test@uva378
bool isParallel(const Line &a, const Line &b)
{
	return EQ(cross(a.p2-a.p1, b.p2-b.p1), 0.0);
}


// a -> b -> c �Ɛi�ގ���
// return +1 : ���v����
//         0 : ������
//        -1 : �����v����
//        +2 : c--a--b
//        -2 : a--b--c
// test@���낢��
int ccw(P a, P b, P c)
{
	b-=a, c-=a;
	if (cross(c, b) > 0) return +1;
	if (cross(c, b) < 0) return -1;
	if (dot(b,c) < 0) return +2;
	if (norm(b) < norm(c)) return -2;
	return 0;
}

// ���p�`���ɓ_���܂܂�邩
// return +1 : ���p�`��
//         0 : ����
//        -1 : ���p�`�O
// test@uva191
int contains(vector<P> &v, const P &p)
{
	bool in = false;
	for (int i=0; i < v.size(); ++i) {
		P a = v[i]-p;
		P b = v[(i+1)%v.size()] - p;
		if (a.imag() > b.imag()) swap(a, b);
		if (a.imag() <= 0 && 0 < b.imag()) {
			if (cross(a,b) < 0) in = !in;
		}
		if (cross(a,b) == 0 && dot(a,b) <= 0) return 0;
	}
	return (in ? 1 : -1);
}


// �~�̒��ɓ����Ă��邩(�~������܂�)
bool isInCircle(const P &p, const P &cirPos, double r)
{
	return (r*r >= norm(cirPos-p));
}

// �O�p�`�̒��ɓ����Ă��邩(������܂܂Ȃ�)
bool isInTriangle(const Point &p, const Point &a, const Point &b, const Point &c)
{
	Point g(0, 0);
	g.x = (a.x + b.x + c.x) / 3;
	g.y = (a.y + b.y + c.y) / 3;

	Point interP;
	if (intersectS(g, p, a, b, interP)) return false;
	if (intersectS(g, p, b, c, interP)) return false;
	if (intersectS(g, p, c, a, interP)) return false;

	return true;
}

// ���ډ~�̔��a
// a,b,c = �e�ӂ̒���
double incircleR(double a, double b, double c)
{
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

// �d�S�����߂�
// test@uva10002
P getG(const vector<P> &v, double area)
{
	double sx=0.0, sy=0.0;
	for (int i=0; i < v.size()-1; ++i) {
		sx += ((v[i].real()+v[i+1].real())*cross(v[i],v[i+1]));
		sy += ((v[i].imag()+v[i+1].imag())*cross(v[i],v[i+1]));
	}
	return P(sx/(6.0*area), sy/(6.0*area));
}