#ifndef DEBUG_H
#define DEBUG_H

//#include<bits/stdc++.h>
using namespace std;

namespace debug
{

	// Declaring
	template <class T, class V> ostream &operator<<(ostream &o, pair <T, V> p);
	template <class T> ostream &operator<<(ostream &o, vector <T> v);
	template <class T> ostream &operator<<(ostream &o, deque <T> v);
	template <class T, size_t size> ostream &operator<<(ostream &o, array<T, size >v);
	template <class T> ostream &operator<<(ostream &o, set <T> v);
	template <class T> ostream &operator<<(ostream &o, set <T, greater<T>> v);
	template <class T> ostream &operator<<(ostream &o, multiset <T> v);
	template <class T> ostream &operator<<(ostream &o, multiset <T, greater<T>> v);
	template <class T, class V> ostream &operator<<(ostream &o, map <T, V> v);
	template <class T, class V> ostream &operator<<(ostream &o, unordered_map <T, V> v);
	template <class T, class V> ostream &operator<<(ostream &o, multimap <T, V> v);
	template <class T> ostream &operator<<(ostream &o, priority_queue<T> a);
	template <class T> ostream &operator<<(ostream &o, priority_queue<T, vector<T>, greater<T>> a);
	template <class T> ostream &operator<<(ostream &o, priority_queue<T, greater<T>> a);
	template <class T> ostream &operator<<(ostream &o, queue<T> a);
	template <class T> ostream &operator<<(ostream &o, stack<T> a);



	//pair
	template <class T, class V> ostream &operator<<(ostream &o, pair <T, V> p) { o<<"{ "; o<<(p.first); o<<","; o<<(p.second); o<<" }"; return o; }
	//vector
	template <class T> ostream &operator<<(ostream &o, vector <T> v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Deque
	template <class T> ostream &operator<<(ostream &o, deque <T> v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//<STL array<int,size_t> [a] ->no size 
	template <class T, size_t size> ostream &operator<<(ostream &o, array<T, size >v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Set
	template <class T> ostream &operator<<(ostream &o, set <T> v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Reverse set
	template <class T> ostream &operator<<(ostream &o, set <T, greater<T>> v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Multiset
	template <class T> ostream &operator<<(ostream &o, multiset <T> v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Reverse multiset
	template <class T> ostream &operator<<(ostream &o, multiset <T, greater<T>> v) { o<<"[ "; bool f=false; for(T i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }

	//Map
	template <class T, class V> ostream &operator<<(ostream &o, map <T, V> v) { o<<"[ "; bool f=false; for(auto i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Unordered_Map
	template <class T, class V> ostream &operator<<(ostream &o, unordered_map <T, V> v) { o<<"[ "; bool f=false; for(auto i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Multimap
	template <class T, class V> ostream &operator<<(ostream &o, multimap <T, V> v) { o<<"[ "; bool f=false; for(auto i:v) { f?o<<", ":o; o<<(i); f=true; } o<<" ]"; return o; }
	//Priority Queue
	template <class T> ostream &operator<<(ostream &o, priority_queue<T> a) { bool k=false; o<<"[ "; while(!a.empty()) { if(k) { o<<", "; }o<<(a.top()); a.pop(); k=true; } o<<" ]"; return o; }
	//Reverse Priority Queue(with vector as container)
	template <class T> ostream &operator<<(ostream &o, priority_queue<T, vector<T>, greater<T>> a) { bool k=false; o<<"[ "; while(!a.empty()) { if(k) { o<<", "; } o<<(a.top()); a.pop(); k=true; } o<<" ]"; return o; }
	//Reverse Priority Queue(with default container)
	template <class T> ostream &operator<<(ostream &o, priority_queue<T, greater<T>> a) { bool k=false; o<<"[ "; while(!a.empty()) { if(k) { o<<", "; } o<<(a.top()); a.pop(); k=true; } o<<" ]"; return o; }
	//Queue
	template <class T> ostream &operator<<(ostream &o, queue<T> a) { bool k=0; o<<"[ "; while(!a.empty()) { if(k) { o<<", "; }o<<(a.front()); a.pop(); k=1; } o<<" ]"; return o; }
	//Stack
	template <class T> ostream &operator<<(ostream &o, stack<T> a) { bool k=0; o<<"[ "; while(!a.empty()) { if(k) { o<<", "; }o<<(a.top()); a.pop(); k=1; } o<<" ]"; return o; }
	//__int128_t
	ostream &operator<<(ostream &o, __int128_t x) { if(x==0) { o<<0; return o; } bool f=false; std::string s; if(x<0)f=true, x=-x; while(x)s+=x%10+'0', x/=10; std::reverse(s.begin(), s.end()); if(f)o<<'-'; o<<s; return o; }

	// Multiarg...
	template <typename... V>void prt(ostream &o, const char *func, int lineno, string name, V... v)
	{
		o<<func<<"()"<<":"<<lineno<<" ";
		auto parse=[&](string s)->queue<string>
		{
			queue<string>names;
			if(s.back()!=',')s+=',';
			int cnt0=0, cnt1=0, cnt2=0;
			auto getName=[&](int start, int end)->string
			{
				while(s[start]==' ')start++;
				return s.substr(start, end-start+1);
			};
			int start=0;
			for(int i=0; i<s.size(); i++)
			{
				const char c=s[i];
				if(c==',')
				{
					if(cnt0==0&&cnt1==0&&cnt2==0)
					{
						string name=getName(start, i-1);
						names.push(name);
						start=i+1;
					}
				}
				else if(c=='(')cnt0++;
				else if(c==')')cnt0--;
				else if(c=='[')cnt1++;
				else if(c==']')cnt1--;
				else if(c=='{')cnt2++;
				else if(c=='}')cnt2--;
			}
			return names;
		};
		queue<string> q=parse(name);
		(..., (o<<q.front()<<'='<<v, q.pop(), q.size()?o<<", ":o));
		o<<'\n';
	}
}//namespace debug

//dbg defined
#define dbg(args...) debug::prt(cout, __func__, __LINE__, #args, args)

#endif //DEBUG_H