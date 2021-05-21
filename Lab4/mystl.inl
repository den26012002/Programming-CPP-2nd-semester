//#include"mystl.h"

template<typename It, typename Pr>
bool all_of(It begin, It end, Pr predicate) {
	for (; begin != end; ++begin) {
		if (!predicate(*begin)) {
			return false;
		}
	}
	return true;
}

template<typename It, typename Pr>
bool any_of(It begin, It end, Pr predicate) {
	for (; begin != end; ++begin) {
		if (predicate(*begin)) {
			return true;
		}
	}
	return false;
}

template<typename It, typename Pr>
bool none_of(It begin, It end, Pr predicate) {
	for (; begin != end; ++begin) {
		if (predicate(*begin)) {
			return false;
		}
	}
	return true;
}

template<typename It, typename Pr>
bool one_of(It begin, It end, Pr predicate) {
	bool ans = false;
	for (; begin != end; ++begin) {
		if (predicate(*begin)) {
			if (ans) {
				return false;
			}
			ans = true;
		}
	}
	return ans;
}

template<typename It, typename Pr>
bool is_sorted(It begin, It end, Pr predicate) {
	It it = begin;
	++begin;
	for (; begin != end; ++begin, ++it) {
		if (!predicate(*it, *begin)) {
			return false;
		}
	}
	return true;
}

template<typename It, typename Pr>
bool is_partitioned(It begin, It end, Pr predicate) {
	for (; begin != end; ++begin) {
		if (!predicate(*begin)) {
			break;
		}
	}
	for (; begin != end; ++begin) {
		if (predicate(*begin)) {
			return false;
		}
	}
	return true;
}

template<typename It, typename Pr>
It find_not(It begin, It end, Pr object) {
	for (; begin != end; ++begin) {
		if (*begin != object) {
			break;
		}
	}
	return begin;
}

template<typename It, typename Pr>
It find_backward(It begin, It end, Pr object) {
	if (begin == end) {
		return end;
	}
	--end;
	for (; end != begin; --end) {
		if (*end == object) {
			return end;
		}
	}
}

template<typename It, typename Pr>
bool is_palindrome(It begin, It end, Pr predicate) {
	if (begin == end) {
		return true;
	}
	--end;
	while (begin != end) {
		if (!predicate(*begin, *end)) {
			return false;
		}
		++begin;
		if (begin == end) {
			break;
		}
		--end;
	}
	return true;
}