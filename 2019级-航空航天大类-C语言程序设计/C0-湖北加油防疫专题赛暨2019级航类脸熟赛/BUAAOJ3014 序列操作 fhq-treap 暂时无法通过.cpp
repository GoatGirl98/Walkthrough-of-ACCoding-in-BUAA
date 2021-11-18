#include <bits/stdc++.h>
using namespace std;
const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=2e5+50;
int n,a[N],nowmx;
inline unsigned int unit() {static unsigned int x=19260817; x^=(x<<13); x^=(x>>17); x^=(x<<5); return x;}
inline int Max(int x,int y) {return (x>y) ? x : y;}
struct node {
	node *lc,*rc;
	unsigned int pri;
	int val,sze,mx,all,tag;
	node() : lc(NULL),rc(NULL),pri(unit()),sze(0),mx(0),all(1) {}
	inline void upt() {
		mx=Max(Max(rc->mx,lc->mx),val);
		sze=lc->sze+rc->sze+1;
		all=lc->all&rc->all&tag;
	}
} *rt,*nowrt,Pool[N],*pool=Pool,*null=pool;
typedef pair <node*,node*> pii;
inline node* merge(node *x,node *y) {
	if(y==null) return x;
	if(x==null) return y;
	if(x->pri>y->pri) {
		x->rc=merge(x->rc,y);
		x->upt(); return x;
	} else {
		y->lc=merge(x,y->lc);
		y->upt(); return y;
	}
}
inline pii split(node *x,int sze) {
	if(x==null) return pii(null,null);
	if(x->lc->sze>=sze) {
		pii tr=split(x->lc,sze);
		x->lc=tr.second; x->upt();
		return pii(tr.first,x);
	} else {
		pii tr=split(x->rc,sze-x->lc->sze-1);
		x->rc=tr.first; x->upt();
		return pii(x,tr.second);
	}
}
inline void Merge(node *&x,node *y) {
	if(y==null) {return;}
	if(x==null) {x=y; return;}
	node *t=x; while(t->rc!=null) t=t->rc;
	node *t2=y; static node* stk[N]; int top=0;
	while(t2->lc!=null) stk[++top]=t2, t2=t2->lc;
	t2->tag=(t2->val>t->val) ? 1 : 0; t2->upt();
	while(top) stk[top--]->upt();
	x=merge(x,y);
}
inline pii split_val(node *x,int lim) {
	if(x==null) return pii(null,null);
	if(Max(x->val,x->lc->mx)<lim) {
		pii tr=split_val(x->rc,lim);
		x->rc=tr.first; x->upt();
		return pii(x,tr.second);
	} else {
		pii tr=split_val(x->lc,lim);
		x->lc=tr.second; x->upt();
		return pii(tr.first,x);
	}
}
inline pii split_all(node *x) {
	if(x==null) return pii(null,null);
	if(!(x->lc->all&x->tag)) {
		pii tr=split_all(x->lc);
		x->lc=tr.second; x->upt();
		return pii(tr.first,x);
	} else {
		pii tr=split_all(x->rc);
		x->rc=tr.first; x->upt();
		return pii(x,tr.second);
	}
}
inline node* find_nxt(int lim) {
	pii tr=split_val(rt,lim);
	pii tr2=split_all(tr.second);
	Merge(nowrt,tr.first);
	rt=tr2.second;
	return tr2.first;
}
inline node* newnode() {
	node *t=++pool;
	t->lc=t->rc=null;
	return t;
}
node* q[N]; int qt;
int main() {
	n=rd(); rt=null; nowmx=n;
	for(int i=1;i<=n;i++) a[i]=rd();
	for(int i=0;i<=n;i++) {
		node *t=newnode();
		t->val=a[i]; t->sze=1; t->mx=a[i];
		t->all=(i ? (a[i]>a[i-1]) : 1);
		t->tag=t->all;
		rt=merge(rt,t);
	}
	int step=0;
	while(!rt->all) {
		++step;
		int mxval=1, pos=0;
		qt=0;
		nowrt=null;
		while(mxval<nowmx)
			mxval=(q[++qt]=find_nxt(mxval))->mx;
		Merge(nowrt,rt); rt=nowrt;
		for(int i=1;i<=qt;i++) Merge(rt,q[i]);
		while(nowmx>3) {
			pii tr=split(rt,nowmx);
			if(tr.second->val==nowmx) rt=tr.first, --nowmx;
			else {rt=merge(tr.first,tr.second); break;}
		}
	}
	cout<<step<<'\n';
}
