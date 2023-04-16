#include <bits/stdc++.h>
using namespace std;
string to_string(string s){
	return '"' + s + '"';
}

string to_string(const char *s){
	return to_string((string)s);
}

string to_string(const char s){
	string c{s};
	return "'"+ c +"'";
}

string to_string(bool b){
	return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p){
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v){
	bool first = true;
	string res = "{";
	for (const auto &x : v){
		if (!first){
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <class _Ty, class _Container = std::vector<_Ty>, class Compare = std::less<_Ty>>
static std::vector<_Ty> &Container(std::priority_queue<_Ty, _Container, Compare> &q){
	struct HackedQueue : private std::priority_queue<_Ty, _Container, Compare>{
		static std::vector<_Ty> &Container(std::priority_queue<_Ty, _Container, Compare> &q){
			return q.*&HackedQueue::c;
		}
	};
	return HackedQueue::Container(q);
};

template <typename T, typename Compare = std::less<T>>
string to_string(std::priority_queue<T, std::vector<T>, Compare> pq){
	std::vector<T> heap = Container<T, std::vector<T>, Compare>(pq);
	sort(heap.begin(), heap.end(), Compare());
	return to_string(heap);
}

void debug_out(){
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){
	cerr << " " << to_string(H);
	debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
