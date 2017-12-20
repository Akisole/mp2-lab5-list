#include <iostream>
using namespace std;

template <class T>
struct TLink 
{
	T val;
	TLink *pNext;
};

template <class T>
class TList {
	TLink<T> *pFirst, *pLast, *pCurr, *pPrev, *pStop;
	int Size, poz;
public:
	TList() {
		Size=0;
		pFirst=pLast=pCurr=pPrev=pStop = NULL;
	}

	int GetSize() {
		return Size;
	}
	int GetPoz() {
		return poz;
	}
	T GetCurr() {
		return pCurr->val;
	}
	void SetPoz(int p) {
		Reset();							
		for (int i=0; i<p-1; i++)			//?
			GoNext();
		poz++;
	}

	void InsFirst (T elem) {
		TLink<T> *tmp = new TLink<T>;
		tmp -> val = elem;
		tmp ->pNext  = pFirst;
		if(pFirst==pStop) {
			pFirst=pLast=pCurr = tmp;
			poz=0;
		}
		else {
			pFirst = tmp;
			poz++;
		}
		Size++;
	}

	void InsLast (T elem) {
		TLink<T> *tmp = new TLink<T>;
		tmp -> val = elem;
		tmp ->pNext  = pStop;
		if(pFirst==pStop) {
			pFirst=pLast=pCurr=tmp;				//?
			poz=0;
		}
		else {
			pLast -> pNext = tmp;
			pLast = tmp;
		}
		Size++;
	}
	void InsCurr (T elem) {
	if(pCurr==pFirst) 
		InsFirst(elem);
	else {
		TLink<T> *tmp = new TLink<T>;
		tmp -> val = elem;
		tmp ->pNext  = pCurr;
		pPrev -> pNext = pCurr;
		pCurr -> pNext = tmp;
		Size++;
	}
}

	void Reset() {
		pCurr=pFirst;
		poz=0;
		pPrev=pStop;
	}
	void GoNext() {
		if(pCurr==pStop)
			throw -1;
		pPrev = pCurr;
		pCurr = pCurr-> pNext;
		poz++;
	}
	bool IsEnd() {
		return (pCurr==pStop);
	}
	void DelFirst() {
		if(size==1) {
			delete pFirst;
			pFirst=pLast=pCurr=pPrev=pStop;
		}
		else {
			TLink<T> *tmp = pFirst;
			pFirst = pFirst -> pNext;
			delete tmp;
		}
		Size--;
		if (pos>0)
			poz--;
	}

	void DelCurr() {
		if(size==1) 
			DelFirst()
		else {
			TLink<T> *tmp = pCurr;
			pCurr = pCurr -> pNext;
			pPrev -> pNext = pCurr;
			delete tmp;
			Size--;
			if (pos>0)
				poz--;
		}
	}

	void DelLast() {
	if(size==1) 
		DelFirst()
	else {
		TLink<T> *tmp_prev = pPrev;
		int tmp_p = poz;

		Reset();
		for(int i=poz; i<Size-1; GoNext()) {}
		pPrev -> pNext = pStop;
		pLast=pPrev;
		delete pCurr;

		pPrev=tmp_prev;
		pCurr=pPrev->pNext;
		poz=tmp_p;

		delete tmp_prev;

		Size--;
		if (pos>0)
			poz--;
	}
}


  friend ostream& operator<<(ostream &out, TList &l)
  {
	  int tmp_pos = l.GetPoz();
	  int i=0;
	for (l.Reset(); !l.IsEnd(); l.GoNext())
			out << l.GetCurr() << ' ';
	
	l.Reset();
	for (i; i<tmp_pos; i++)
		l.GoNext();
    return out;
  }

};