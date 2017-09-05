// random_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <type_traits>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;

template<typename range, typename callable>
void trans(const range& r, callable c) {
	for (const auto& e : r)
		cout << invoke(c, e)<<"\n";
}
vector<pair<int, int>> v{ {4,40},{5,50}, {6,60} };

template<typename... Ts>
constexpr auto make_array(Ts&&... ts)
{
	return std::array<std::common_type_t<Ts...>, sizeof...(ts)>{ std::forward<Ts>(ts)... };
}
template <typename T, typename Callable>
auto transform_sort(const vector<T>& v, Callable c)
{
	//result_of_t< Callable(T)> means what is the result of rvalue callabe on rvalue T
	//vector<decay_t<result_of_t< Callable&(const T&)>>> ret;

	//string s;
	//vector<decay_t<decltype(invoke(c, s))>> ret;
	vector<decay_t<decltype(invoke(std::declval<Callable>(), std::declval<T>()))>> ret;
	//vector<decay_t<decltype(invoke(Callable(), T()))>> ret;
	for (const auto& t : v) { ret.push_back(invoke(c,t)); }
	sort(ret.begin(), ret.end());
	return ret;
}
template <class T1,class T2, class T3>
void merge(typename T1::iterator b1, typename T1::iterator e1, typename T2::iterator b2,
	typename T2::iterator e2, typename T3::iterator o3,  bool(*comp)(typename T1::const_reference, typename T2::const_reference)  ) {
	typename T1::iterator it = b1;
	typename T3::iterator be = o3;
	for (; it != e1; ++it, ++be)
		*be = *it;
	typename T2::iterator it2 = b2;
	for (; it2 != e2; ++it2, ++be)
		*be = *it2;
	
	sort(o3, be, comp);
	return;
}
class employee{
	
public:
	template <class String, class = enable_if_t< !std::is_same< decay_t<String>, string>::value>>
	explicit employee(String &&name) : _name(forward<String> (name)) { cout << "afh\n"; }
	 employee(string &&name) : _name(move(name)) { cout << "strg\n"; }
	 employee(const string &name) : _name(name) { cout << "c strg\n"; }
	/*void set_name(String &&name) {
		_name = forward<String>(name);
	}*/
	 string _name;
};
template <typename T, int dur>
double power(double s, int fe = 100) { return 0.0; }
struct Element
{
	bool IsMetal()const { return true; }
};
void fo1()  { throw exception(); }
void fo() noexcept(noexcept(fo1())) { fo1(); }
int main()
{
	/*power<int>(2.0, 100);
	power<int,char>(2.0)*/;
	power<int,500>(2.0, 100);
	power<int, 500>(2.0, 'a');
	unordered_map<int, int> m112;
	m112.insert({ 1,1 });
	auto saa = m112.bucket_count();
	auto ss = m112.max_load_factor();
	int data[5] = {1,2,3,4,5};
	int numValues = 5;
	vector<int> vv(6, 10);
	copy(data,data + numValues, inserter(vv, vv.begin()));
	vector<Element> ve{ Element(),Element() ,Element(), Element() };
	vector<Element> ve1{ Element(),Element() ,Element(), Element() };
	ve = ve1;
	vector<Element>::iterator re = ve.begin();
	vector<Element>::const_iterator sc = re;
//	re = sc;
	auto j = count_if(ve.begin(), ve.end(), [](const auto& e) {return e.IsMetal(); });
	const vector<string> v1{ "hydrogen", "hellium","etc" };
	
	auto lambda = [](const auto& s) {
		return s.size(); 
	};
	for (const auto& e : transform_sort(v1, lambda)) {
		cout << e << "\n";
	}
	
		
		trans(v, [](const auto& p) {return p.first*p.second; });
	//cout << invoke(&pair<int, int>::second, pair<int, int>(2, 3))<<"\n";
	trans(v, &pair<int, int>::second);
	vector<int> v{234,24,45,1,2,8,11};
	vector < int> v2{12,1,23,56,47,24,7};
	vector<int> s(v2.size() + v.size(), 0 );
	//s.reserve(v2.size()+v.size(),0);
	merge<vector<int>, vector<int>, vector<int> >
		(v.begin(), v.end(), v2.begin(), v2.end(), s.begin(), [](typename vector<int>::const_reference r1, typename vector<int>::const_reference r2) {return r1 < r2; });

	//vector < int>::const_reference
	//	, std::function< bool(typename T1::const_reference, typename T1::const_reference)> comp
	//merge<vector<int>, vector<int>, set<int>, std::function< bool(typename vector<int>::const_reference, typename vector<int>::const_reference)> >
	//	(v.begin(), v.end(), v2.begin(), v2.end(), s.begin(), [](typename vector<int>::const_reference r1, typename vector<int>::const_reference r2) {return r1 < r2; });
	//auto ssd = std::is_same< decay_t<const char*>, string>::value;
	//auto ssd1 = std::is_same< decay_t<string>, string>::value;
	//employee e("adfasdf");
	//employee e1(string("123"));
	//employee e2(e1._name);
	////e.set_name("adfasdf");
	//auto b = make_array(1, 2, 3);
	//std::cout << b.size() << '\n';
	//for (auto i : b)
	//	std::cout << i << ' ';
    return 0;
}

