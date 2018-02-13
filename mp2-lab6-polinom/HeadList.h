#include "TList.h"

template <class T>
class THList : public TList<T>
{
protected:
	TLink<T> *pHead;
public:
	THList():TList() {
		pHead = new TLink<T>;
		pHead->pNext = pHead;
		
		pFirst = pLast = pCurr = pPrev = pStop = pHead;
		poz=-1;
	}

	void Push (T elem) {
		TLink<T> *tmp = new TLink<T>;
		tmp -> val = elem;
		if (poz == -1){
			InsFirst(elem);
		}
		else {
			Reset();	
			while (pCurr->val < elem && pCurr->pNext != pHead) {
				pPrev = pCurr;
				pCurr = pCurr->pNext;
			}
			
			if (pCurr->val < elem && pCurr->pNext == pHead) {
				pCurr->pNext = tmp;
				tmp -> pNext = pHead;
				pLast = tmp;
				Size++;
			}
			 else if (elem < pCurr->val){
				tmp->pNext = pCurr;
				pPrev->pNext = tmp;
				pPrev = tmp;
				Size++;
				if(pCurr==pFirst)
					pFirst = tmp;

			} 
		}
	}
	void InsFirst (T elem) {
		TLink<T> *tmp = new TLink<T>;
		tmp -> val = elem;
		if (poz == -1) {
			tmp->pNext=pHead;
			pFirst=pLast=pCurr = tmp;
			pHead->pNext = pPrev->pNext=pFirst;
			poz = 0;
		}
		else {
		tmp -> pNext  = pFirst;
		pHead->pNext = tmp;
		pFirst = tmp;
		poz++;
		}
		Size++;
	}
	void DelFirst() {
		if(Size==1) {
			delete pFirst;
			pFirst=pLast=pCurr=pPrev=pStop;
			poz = -1;
		}
		else {
			TLink<T> *tmp = pFirst;
			pFirst = pFirst -> pNext;
			delete tmp;
			pHead->pNext = pFirst;
			if (poz>0)
				poz--;
		}
		Size--;
	}

	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr-> pNext;
		if(pCurr==pLast) 
			poz = -1;
		else
			poz++;
	}
	bool IsEnd() {
		return (pCurr==pHead);
	}



	friend ostream& operator<<(ostream &out, THList &l)
  {
	int tmp_pos = l.GetPoz();
	for (l.Reset(); !l.IsEnd(); l.GoNext())
			out << l.GetCurr() << ' ';	
	l.SetPoz(tmp_pos);
    return out;
  }
};
