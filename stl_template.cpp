#include <iostream>
#include <list>
#include <cassert>
#include <algorithm>
#include <vector>
#include <numeric> 

using namespace std;

template <typename Container>

Container make(const char s[])

{
    return Container(&s[0], &s[strlen(s)]);
}

template<typename T>
std::ostream& print(std::ostream &out, T const &val) { 
    return (out << val << " ");
}

template<typename T1, typename T2>
std::ostream& print(std::ostream &out, std::pair<T1, T2> const &val) { 
    return (out << "{" << val.first << " " << val.second << "} ");
}

template<template<typename, typename...> class TT, typename... Args>
std::ostream& operator<<(std::ostream &out, TT<Args...> const &cont) {
  for(auto&& elem : cont) print(out, elem);
  return out;
}

void tprint(const int* t, int n) {
​    for (int i = 0; i < n; ++i) {
​        std::cout << t[i] << " ";
​    }
​    std::cout << std::endl;
}

template<typename T>
void print(const T& t) {
​    using type = typename T::value_type;
​    for_each(t.begin(), t.end(), [](const type& e){std::cout << e << " ";});
​    std::cout << std::endl;
}

template<typename T, typename ...Types>
void print(const T& t, const Types ...args) {
​    print(t);
​    print(args...); 
}


#include <type_traits>
template<typename T, typename ...Types>
void print(const T& t, const Types ...args) {
    using type = typename T::value_type;
    for_each(t.begin(), t.end(), [](const type& e){std::cout << e << " ";});
    std::cout << std::endl;
    static_if (sizeof...(args) != 0)
        print(args...);  
}

template <typename T>
class calc_square {
  T i;
 public:
  calc_square(): i(0) {}

  T operator()() { ++i; return i * i; }

};

int main(int argc, const char *argv[]) {

​    // driver_list.insert(driver_list.end(), "Clark");

​    // 常用部分

​    // reverse

​    // find, find_if, 

​    // count, count_if(&a[0], &a[9], bind2nd(not_equal_to<int>(), 1));

​    // search

​    // copy

​    // reverse_copy

​    // copy_backward

​    // fill

​    // fill_n(vector1.begin() + 5, 3, 'Y');

​    // random_shuffle

​    // for_each

​    // partial sort // partial_sort(b, b+6, e);  只排好前6个元素

​    // binary_search lower_bound upper_bound

​    // min_element max_element 

​    // prev_permutation next_permutation

​    // accumulate

​    // inner_product 内积 nner_product(&x1[0], &x1[N], &x2[0], 1, multiplies<int>(), plus<int>());

​    const int N = 6;

​    ostream_iterator<int> out(cout, " ");

​    

​    // {

​    //     // mismatch equal

​    //     list<string> driver_list{"Clark","Rindt","Senna","Berger"};

​    //     vector<string> names{"Clark","Rindt","Senna","Berger"};

​    //     cout << equal(driver_list.begin(), driver_list.end(), names.begin()) << endl;

​    //     auto itpair = mismatch(driver_list.begin(), driver_list.end(), names.begin()); //iterator pair

​    // }

​    

​    // {

​    //     // generate        

​    //     vector<int> v1(10);

​    //     generate(v1.begin(), v1.end(), calc_square<int>());

​    //     print(v1);  // 1 4 9 16 25 36 49 64 81 100

​    // }

​    

​    // {

​    //      // partition   

​    //     vector<int> v1{50, 30, 10, 70, 60, 40, 20};

​    //     auto split = partition(v1.begin(), v1.end(), [](int e){return e>40;});

​    //     copy(v1.begin(), split, out); cout << "| ";

​    //     copy(split, v1.end(), out); cout << endl;   // 50 60 70 | 10 30 40 20

​    //     v1 = {50, 30, 10, 70, 60, 40, 20};

​    //     split = stable_partition(v1.begin(), v1.end(), [](int e){return e>40;});

​    //     copy(v1.begin(), split, out); cout << "| ";

​    //     copy(split, v1.end(), out); cout << endl;   // 50 70 60 | 30 10 40 20 keep relative 

​    // }

​    

​    // {

​    //     // erase

​    //     vector<int> v1{1, 2, 0, 3, 4, 0, 5, 6, 7, 0, 8};

​    //     auto new_end = remove(v1.begin(), v1.end(), 0); // 

​    //     print(v1); // 1 2 3 4 5 6 7 8 7 0 8
            
            v1.find()
​    //     v1.erase(new_end, v1.end());  

​    //     print(v1); // 1 2 3 4 5 6 7 8

​    // }

​    // {

​    //     // replace

​    //     string s1("FERRARI");

​    //     replace(s1.begin(), s1.end(), 'R', 'S');

​    //     cout << s1 << endl; // FESSASI replace all

​    // }

​    

​    // {

​    //     // rotate ??

​    //     string s1("Software Engineering ");

​    //     rotate(s1.begin(), s1.begin() + 9, s1.end());

​    //     cout << s1 << endl;

​    // }

​    // {

​    //     // swap

​    //     vector<int> v1(10, 1), v2(5, 2);

​    //     swap(v1, v2);

​    //     print(v1, v2);

​    //     // swap_ranges

​    //     swap_ranges(v1.begin(), v1.end(), v2.begin());

​    //     print(v1, v2);

​    // }

​    // {

​    //     // transform 可以一元和二元

​    //     vector<int> v1(10, 1), v2(10, 2);

​    //     transform(v1.begin(), v1.end(), v2.begin(), out, [](int x, int y){return x+y;});

​    //     transform(v1.begin(), v1.end(), out, [](int x){return x+1;});

​    //     cout << endl;

​    // }

​    

​    // {

​    //     // unique

​    //     vector<int> v1{1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};

​    //     auto new_end = unique(v1.begin(), v1.end());

​    //     v1.erase(new_end, v1.end());

​    //     print(v1);

​    // }

​    // {

​    //     // nth_element ??

​    //     vector<int> v1{1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};

​    //     nth_element(v1.begin(), v1.begin() + 3, v1.end());

​    //     print(v1);

​    // }

​    // {

​    //     // adjacent_find 找到相邻相同

​    //     i = adjacent_find(player.begin(), player.end());

​    //     assert (*i == "Maradona" && *(i+1) == "Maradona");

​    //     i = adjacent_find(player.begin(), player.end(), greater<string>());

​    // }

​    {

​        // merge inplace_merge

​    }

​    // {

​    //     // include union

​    //     // set_insection() set_difference()

​    //     string s1("abcde"), s2("aeiou");

​    //     bool result = includes(s1.begin(), s1.end(), s2.begin(), s2.end()); // s1 是否包含 s2 所有

​    //     cout << result << " ";

​    //     string setUnion;

​    //     set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(setUnion));

​    //     cout << setUnion << endl;

​    // }

​    // {

​    //     // lexicographical_compare ??

​    //     string s1("xabcde"), s2("aeiou");

​    //     bool result = lexicographical_compare(s1.begin(),

​    //         s1.end(), s2.begin(), s2.end());

​    //     cout << result <<  endl;

​    // }

​    // {

​    //     // partial_sum ajacent_diff 在numeric中 

​    //     int x1[10] = {1,2,3,4,5,6,7,8,9,10};

​    //     int x2[10];

​    //     partial_sum(&x1[0], &x1[10], &x2[0]);  // 累加和

​    //     tprint(x2, 10);

​    //     adjacent_difference(&x2[0], &x2[10], &x2[0]);

​    //     tprint(x2, 10);        

​    // }

​    {

​        // heap
​        int i;
​        vector<int> v1{1,2,3,4,5};
​        random_shuffle(v1.begin(), v1.end());

​        for (i = 2; i <= 5; ++i)

​        push_heap(v1.begin(), v1.begin() + i);

​        for (i = 5; i >= 2; --i)

​        pop_heap(v1.begin(), v1.begin() + i);

​        print(v1);

​        // make_heap(vector1.begin(), vector1.end());

​        // sort_heap(vector1.begin(), vector1.end());

​    }

​    

​    // set<string, pointer_to_binary_function<const string&, 

​    //                            const string&, bool> >  

​    // set_type1 set1(ptr_fun(less1));                           

​    

​    // // file stream

​    // ifstream ifs(dictionary_name.c_str());

​    // if (!ifs.is_open()) {

​    // }

​    // typedef istream_iterator<string> string_input;

​     

​    // vector<PS> word_pairs;

​    // copy(string_input(ifs), string_input(), 

​    //      back_inserter(word_pairs));

​         

​    return 0;

} <iostream>

\#include <list>

\#include <cassert>

\#include <algorithm>

\#include <vector>

\#include <numeric> 

using namespace std;

// template <typename Container>

// Container make(const char s[])

// {

//   return Container(&s[0], &s[strlen(s)]);

// }

// template<typename T>

// std::ostream& print(std::ostream &out, T const &val) { 

//   return (out << val << " ");

// }

// template<typename T1, typename T2>

// std::ostream& print(std::ostream &out, std::pair<T1, T2> const &val) { 

//   return (out << "{" << val.first << " " << val.second << "} ");

// }

// template<template<typename, typename...> class TT, typename... Args>

// std::ostream& operator<<(std::ostream &out, TT<Args...> const &cont) {

//   for(auto&& elem : cont) print(out, elem);

//   return out;

// }

void tprint(const int* t, int n) {

​    for (int i = 0; i < n; ++i) {

​        std::cout << t[i] << " ";

​    }

​    std::cout << std::endl;

}

template<typename T>

void print(const T& t) {

​    using type = typename T::value_type;

​    for_each(t.begin(), t.end(), [](const type& e){std::cout << e << " ";});

​    std::cout << std::endl;

}

template<typename T, typename ...Types>

void print(const T& t, const Types ...args) {

​    print(t);

​    print(args...);  

}

// #include <type_traits>

// template<typename T, typename ...Types>

// void print(const T& t, const Types ...args) {

//     using type = typename T::value_type;

//     for_each(t.begin(), t.end(), [](const type& e){std::cout << e << " ";});

//     std::cout << std::endl;

//     static_if (sizeof...(args) != 0)

//         print(args...);  

// }

template <typename T>

class calc_square {

  T i;

 public:

  calc_square(): i(0) {}

  T operator()() { ++i; return i * i; }

};

int main(int argc, const char *argv[]) {

​    // driver_list.insert(driver_list.end(), "Clark");

​    // 常用部分

​    // reverse

​    // find, find_if, 

​    // count, count_if(&a[0], &a[9], bind2nd(not_equal_to<int>(), 1));

​    // search

​    // copy

​    // reverse_copy

​    // copy_backward

​    // fill

​    // fill_n(vector1.begin() + 5, 3, 'Y');

​    // random_shuffle

​    // for_each

​    // partial sort // partial_sort(b, b+6, e);  只排好前6个元素

​    // binary_search lower_bound upper_bound

​    // min_element max_element 

​    // prev_permutation next_permutation

​    // accumulate

​    // inner_product 内积 nner_product(&x1[0], &x1[N], &x2[0], 1, multiplies<int>(), plus<int>());

​    const int N = 6;

​    ostream_iterator<int> out(cout, " ");

​    

​    // {

​    //     // mismatch equal

​    //     list<string> driver_list{"Clark","Rindt","Senna","Berger"};

​    //     vector<string> names{"Clark","Rindt","Senna","Berger"};

​    //     cout << equal(driver_list.begin(), driver_list.end(), names.begin()) << endl;

​    //     auto itpair = mismatch(driver_list.begin(), driver_list.end(), names.begin()); //iterator pair

​    // }

​    

​    // {

​    //     // generate        

​    //     vector<int> v1(10);

​    //     generate(v1.begin(), v1.end(), calc_square<int>());

​    //     print(v1);  // 1 4 9 16 25 36 49 64 81 100

​    // }

​    

​    // {

​    //      // partition   

​    //     vector<int> v1{50, 30, 10, 70, 60, 40, 20};

​    //     auto split = partition(v1.begin(), v1.end(), [](int e){return e>40;});

​    //     copy(v1.begin(), split, out); cout << "| ";

​    //     copy(split, v1.end(), out); cout << endl;   // 50 60 70 | 10 30 40 20

​    //     v1 = {50, 30, 10, 70, 60, 40, 20};

​    //     split = stable_partition(v1.begin(), v1.end(), [](int e){return e>40;});

​    //     copy(v1.begin(), split, out); cout << "| ";

​    //     copy(split, v1.end(), out); cout << endl;   // 50 70 60 | 30 10 40 20 keep relative 

​    // }

​    

​    // {

​    //     // erase

​    //     vector<int> v1{1, 2, 0, 3, 4, 0, 5, 6, 7, 0, 8};

​    //     auto new_end = remove(v1.begin(), v1.end(), 0); // 

​    //     print(v1); // 1 2 3 4 5 6 7 8 7 0 8

​    //     v1.erase(new_end, v1.end());  

​    //     print(v1); // 1 2 3 4 5 6 7 8

​    // }

​    // {

​    //     // replace

​    //     string s1("FERRARI");

​    //     replace(s1.begin(), s1.end(), 'R', 'S');

​    //     cout << s1 << endl; // FESSASI replace all

​    // }

​    

​    // {

​    //     // rotate ??

​    //     string s1("Software Engineering ");

​    //     rotate(s1.begin(), s1.begin() + 9, s1.end());

​    //     cout << s1 << endl;

​    // }

​    // {

​    //     // swap

​    //     vector<int> v1(10, 1), v2(5, 2);

​    //     swap(v1, v2);

​    //     print(v1, v2);

​    //     // swap_ranges

​    //     swap_ranges(v1.begin(), v1.end(), v2.begin());

​    //     print(v1, v2);

​    // }

​    // {

​    //     // transform 可以一元和二元

​    //     vector<int> v1(10, 1), v2(10, 2);

​    //     transform(v1.begin(), v1.end(), v2.begin(), out, [](int x, int y){return x+y;});

​    //     transform(v1.begin(), v1.end(), out, [](int x){return x+1;});

​    //     cout << endl;

​    // }

​    

​    // {

​    //     // unique

​    //     vector<int> v1{1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};

​    //     auto new_end = unique(v1.begin(), v1.end());

​    //     v1.erase(new_end, v1.end());

​    //     print(v1);

​    // }

​    // {

​    //     // nth_element ??

​    //     vector<int> v1{1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};

​    //     nth_element(v1.begin(), v1.begin() + 3, v1.end());

​    //     print(v1);

​    // }

​    // {

​    //     // adjacent_find 找到相邻相同

​    //     i = adjacent_find(player.begin(), player.end());

​    //     assert (*i == "Maradona" && *(i+1) == "Maradona");

​    //     i = adjacent_find(player.begin(), player.end(), greater<string>());

​    // }

​    {

​        // merge inplace_merge

​    }

​    // {

​    //     // include union

​    //     // set_insection() set_difference()

​    //     string s1("abcde"), s2("aeiou");

​    //     bool result = includes(s1.begin(), s1.end(), s2.begin(), s2.end()); // s1 是否包含 s2 所有

​    //     cout << result << " ";

​    //     string setUnion;

​    //     set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(setUnion));

​    //     cout << setUnion << endl;

​    // }

​    // {

​    //     // lexicographical_compare ??

​    //     string s1("xabcde"), s2("aeiou");

​    //     bool result = lexicographical_compare(s1.begin(),

​    //         s1.end(), s2.begin(), s2.end());

​    //     cout << result <<  endl;

​    // }

​    // {

​    //     // partial_sum ajacent_diff 在numeric中 

​    //     int x1[10] = {1,2,3,4,5,6,7,8,9,10};

​    //     int x2[10];

​    //     partial_sum(&x1[0], &x1[10], &x2[0]);  // 累加和

​    //     tprint(x2, 10);

​    //     adjacent_difference(&x2[0], &x2[10], &x2[0]);

​    //     tprint(x2, 10);        

​    // }

​    {

​        // heap

​        int i;

​        vector<int> v1{1,2,3,4,5};

​        random_shuffle(v1.begin(), v1.end());

​        for (i = 2; i <= 5; ++i)

​        push_heap(v1.begin(), v1.begin() + i);

​        for (i = 5; i >= 2; --i)

​        pop_heap(v1.begin(), v1.begin() + i);

​        print(v1);

​        // make_heap(vector1.begin(), vector1.end());

​        // sort_heap(vector1.begin(), vector1.end());

​    }

​    

​    // set<string, pointer_to_binary_function<const string&, 

​    //                            const string&, bool> >  

​    // set_type1 set1(ptr_fun(less1));                           

​    

​    // // file stream

​    // ifstream ifs(dictionary_name.c_str());

​    // if (!ifs.is_open()) {

​    // }

​    // typedef istream_iterator<string> string_input;

​     

​    // vector<PS> word_pairs;

​    // copy(string_input(ifs), string_input(), 

​    //      back_inserter(word_pairs));

​         

​    return 0;

}