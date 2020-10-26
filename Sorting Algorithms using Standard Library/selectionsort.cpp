#include<iostream>
#include <algorithm>
#include <cassert>

template<class FwdIt, class Compare = std::less<>>
void selection_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const selection = std::min_element(it, last, cmp);
        std::iter_swap(selection, it); 
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}

 int main() {
  vector<int> a = {3, 5, 1, 3, 4, 8, 1, 7, 11, 9, 2, 5, 6, 1};
  auto frwditr = a.begin();
  auto lastritr = a.end();
  selection_sort(frwditr, lastritr);

 for(auto i : a) {
   std::cout<< i <<" ";
 }
