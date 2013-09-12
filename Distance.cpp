

// �ˉe�����߂�
P projection(const Line &l, const P &p)
{
	double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
	return l.p1 + t*(l.p1-l.p2);
}

// �_a�Ɠ_b�Ƃ̋���
double distPP(const P &a, const P &b)
{
  return abs(b-a);
}

// �����Ɠ_�̋���
// test@10709
double distLP(const Line &l, const P &p)
{
	return abs(p - projection(l, p));
}

// �����Ɠ_�̋���
// test@10709
double distSP(const Segment &s, const P &p)
{
	const P r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return (min(abs(s.p1-p), abs(s.p2-p)));
}

// �����Ɛ����̋���
// test@10709
double distSS(const Segment &s, const Segment &t)
{
	if (intersectSS(s, t)) return 0;
	return min(min(distSP(s, t.p1), distSP(s, t.p2)),
		min(distSP(t, s.p1), distSP(t, s.p2)));
}

// �����Ɛ���
// test@10709
double distLS(const Line &l, const Segment &s)
{
	if (intersectLS(l, s)) return 0;
	return min(distLP(l, s.p1), distLP(l, s.p2));
}

// �����ƒ����̋���
// test@10709
double distLL(const Line &a, const Line &b)
{
	return (intersectLL(a, b) ? 0 : distLP(a, b.p1));
}
