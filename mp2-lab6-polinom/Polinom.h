#include "HeadList.h"


struct TMonom
{
	double coeff;
	int x, y, z;
};
bool operator<(const TMonom& p, const TMonom& g) {
	bool k=false;
	if (p.x==g.x) {
		if (p.y==g.y) {
			if (p.z==g.z) {
				if (p.coeff<g.coeff)
					k=true;
			}
			else if (p.z<g.z)
				k=true;
		}
		else if (p.y<g.y)
			k=true;
	}
	else if (p.x<g.x)
		k=true;	
	return k;
}
TMonom operator*(const TMonom& p, const TMonom& g) {
	TMonom tmp;
	tmp.coeff=p.coeff*g.coeff;
	tmp.x=p.x+g.x;
	tmp.y=p.y+g.y;
	tmp.z=p.z+g.z;
	return tmp;
}
TMonom operator*(const TMonom& p, const int& c) {
	TMonom tmp=p;
	tmp.coeff*=c;
	return tmp;
}

class TPolinom: public THList<TMonom> {

public:
	TPolinom():THList() {
		pHead->val.coeff=0;
		pHead->val.x=-1;
	}

	TPolinom& operator*(const int& c) {
		TPolinom tmp_p;
		int tmp_poz=GetPoz();

		for (Reset(); !IsEnd(); GoNext())
			tmp_p.Push(pCurr->val*c);

		if (pHead->val.coeff != 0) 
			tmp_p.pHead->val.coeff = pHead->val.coeff * c;

		poz=tmp_poz;
		return tmp_p;;
	}
	TPolinom& operator*(const TMonom& m) {
		TPolinom tmp_p;
		int tmp_poz=GetPoz();
		for (Reset(); !IsEnd(); GoNext())
			tmp_p.Push(pCurr->val * m);

		if (pHead->val.coeff != 0) {
		TMonom tmp;
		tmp =  m * pHead->val.coeff;
		tmp_p.Push(tmp);
		tmp_p.pHead->val.coeff = 0;
		}

		poz=tmp_poz;
		return tmp_p;
	}



	void GetCurr() {
		if (this->pCurr->val.coeff>0)
			std::cout << "+" <<this->pCurr->val.coeff << " x^" << this->pCurr->val.x <<
					" y^" << this->pCurr->val.y << " z^" << this->pCurr->val.z;
		else
			std::cout <<this->pCurr->val.coeff << " x^" << this->pCurr->val.x <<
					" y^" << this->pCurr->val.y << " z^" << this->pCurr->val.z;
	}
	double GetHeadCof() { 
		return pHead->val.coeff;
	}
	friend ostream& operator<<(ostream &out, TPolinom &p)
  {
	int tmp_pos = p.GetPoz();
	out << p.GetHeadCof() << " ";
	for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			p.GetCurr();
			out	<< ' ';	
	}
	p.SetPoz(tmp_pos);
    return out;
  }

};