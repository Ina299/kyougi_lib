
// ���p�`�̖ʐς����߂�
// pt�̏����F
//   (��)���v���
//   pt[0] == pt[pt.size()-1]
// test@10065
double areaOfPolygon(const vector<P> &pt)
{
	double s = 0.0;
	for (int i=0; i < pt.size()-1; i++) {
		s += real(pt[i])*imag(pt[i+1]) - real(pt[i+1])*imag(pt[i]);
	}
	return abs(s / 2);
}