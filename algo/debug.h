#include <bits/stdc++.h>
using namespace std;
string to_string(string s){
	return '"' + s + '"';
}

string to_string(const char *s){
	return to_string((string)s);
}

string to_string(const char s){
	string c(1,s);
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

template <typename T, typename Compare>
string to_string(std::priority_queue<T, std::vector<T>, Compare> pq){
	priority_queue<T,std::vector<T>,Compare>q(pq);
	vector<T>v(pq.size());
	for(T &x:v)
	{
		x=pq.top();
		pq.pop();
	}
	return to_string(v);
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
