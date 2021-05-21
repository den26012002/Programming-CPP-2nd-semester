#pragma once

template<typename It, typename Pr>
bool all_of(It, It, Pr);

template<typename It, typename Pr>
bool any_of(It, It, Pr);

template<typename It, typename Pr>
bool none_of(It, It, Pr);

template<typename It, typename Pr>
bool one_of(It, It, Pr);

template<typename It, typename Pr>
bool is_sorted(It, It, Pr);

template<typename It, typename Pr>
bool is_partitioned(It, It, Pr);

template<typename It, typename Pr>
It find_not(It, It, Pr);

template<typename It, typename Pr>
It find_backward(It, It, Pr);

template<typename It, typename Pr>
bool is_palindrome(It, It, Pr);

#include"mystl.inl"