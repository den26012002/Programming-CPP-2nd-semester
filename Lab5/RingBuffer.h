#pragma once
#include<iterator>

template<typename Type>
class RingBuffer {
public:
	class iterator : public std::iterator<std::random_access_iterator_tag, Type> {
	public:
		iterator(Type* _ptr, RingBuffer* _ringBuffer) : ptr_(_ptr), ringBuffer_(_ringBuffer) {}

		iterator() : ptr_(nullptr), ringBuffer_(nullptr) {}

		iterator& operator=(const iterator& other) {
			if (this == &other) {
				return *this;
			}
			ptr_ = other.ptr_;
			ringBuffer_ = other.ringBuffer_;
			return *this;
		}

		Type& operator*() {
			if (!correctIndex(ptr_ - ringBuffer_->buffer_) || ptr_ == ringBuffer_->end_.ptr_) {
				throw "My exception5";
			}
			return *ptr_;
		}

		iterator& operator++() {
			if (ptr_ == ringBuffer_->buffer_ + ringBuffer_->capacity_) {
				ptr_ = ringBuffer_->buffer_;
			}
			else {
				++ptr_;
			}
			return *this;
		}

		const iterator operator++(int) {
			iterator temp = *this;
			++(*this);
			return temp;
		}

		iterator& operator--() {
			if (ptr_ == ringBuffer_->buffer_) {
				ptr_ = ringBuffer_->buffer_ + ringBuffer_->capacity_;
			}
			else {
				--ptr_;
			}
			return *this;
		}

		const iterator operator--(int) {
			iterator temp = *this;
			--(*this);
			return temp;
		}

		iterator& operator-=(int shift) {
			if (shift < 0) {
				return this->operator+=(-shift);
			}
			if (shift > ringBuffer_->size_) {
				throw "My exception1";
			}
			int newIndex = (ringBuffer_->capacity_ + 1 + ptr_ - ringBuffer_->buffer_ - shift) % (ringBuffer_->capacity_ + 1);
			if (!correctIndex(newIndex)) {
				throw "My exception2";
			}
			ptr_ = ringBuffer_->buffer_ + newIndex;
			return *this;
		}

		iterator& operator+=(int shift) {
			if (shift < 0) {
				return this->operator-=(-shift);
			}
			if (shift > ringBuffer_->size_) {
				throw "My exception3";
			}
			int newIndex = (ptr_ - ringBuffer_->buffer_ + shift) % (ringBuffer_->capacity_ + 1);
			if (!correctIndex(newIndex)) {
				throw "My exception4";
			}
			ptr_ = ringBuffer_->buffer_ + newIndex;
			return *this;
		}

		int operator-=(const iterator& other) {
			if (ringBuffer_ != other.ringBuffer_) {
				throw "My exception6";
			}
			//return (ringBuffer_->capacity_ + 1 + (ptr_ - other.ptr_)) % (ringBuffer_->capacity_ + 1);
			//return ptr_ - other.ptr_;
			return (findBufPos(*this) - findBufPos(other));
		}

		Type& operator[](int index) { 
			return *(*this + index);
		}

		const Type& operator[](int index) const {
			return *(this + index);
		}

		friend bool operator==(const iterator&, const iterator&);

	private:
		Type* ptr_;
		RingBuffer* ringBuffer_;
		friend RingBuffer;

		bool correctIndex(int newIndex) {
			int beginIndex = ringBuffer_->begin_.ptr_ - ringBuffer_->buffer_;
			int endIndex = ringBuffer_->end_.ptr_ - ringBuffer_->buffer_;
			return !(((beginIndex < endIndex) && (newIndex > endIndex || newIndex < beginIndex)) ||
					((beginIndex > endIndex) && (newIndex < beginIndex && newIndex > endIndex)));
		}

		int findArrPos(const iterator& it) {
			return (it.ptr_ - ringBuffer_->buffer_);
		}

		int findBufPos(const iterator& it) {
			return ((ringBuffer_->capacity_ + 1) + findArrPos(it) - findArrPos(ringBuffer_->begin_)) % (ringBuffer_->capacity_ + 1);
		}
	};

	friend iterator operator-(iterator it, int shift) {
		return (it -= shift);
	}

	friend iterator operator+(iterator it, int shift) {
		return (it += shift);
	}

	friend iterator operator+(int shift, iterator it) {
		return (it += shift);
	}

	friend int operator-(iterator it1, const iterator& it2) {
		return (it1 -= it2);
	}

	friend bool operator==(const iterator& it1, const iterator& it2) {
		return it1.ptr_ == it2.ptr_;
	}

	friend bool operator!=(const iterator& it1, const iterator& it2) {
		return !(it1 == it2);
	}

	friend bool operator<(const iterator& it1, const iterator& it2) {
		return (it2 - it1 > 0);
	}

	friend bool operator>(const iterator& it1, const iterator& it2) {
		return (it2 < it1);
	}

	friend bool operator<=(const iterator& it1, const iterator& it2) {
		return !(it2 < it1);
	}

	friend bool operator>=(const iterator& it1, const iterator& it2) {
		return !(it1 < it2);
	}

public:
	RingBuffer(RingBuffer& other) : capacity_(other.capacity_), size_(other.size_) {
		buffer_ = new Type[other.capacity_ + 1];
		iterator it = other.begin_;
		for (int i(0); i < other.size_; ++i) {
			buffer_[i] = *it;
			++it;
		}
		begin_ = iterator(buffer_, this);
		end_ = iterator(buffer_ + size_, this);
	}

	explicit RingBuffer(int capacity = 0) : capacity_(capacity), size_(0) {
		buffer_ = new Type[capacity + 1];
		begin_ = iterator(buffer_, this);
		end_ = iterator(buffer_, this);
	}

	int size() {
		return size_;
	}

	int capacity() {
		return capacity_;
	}

	iterator begin() {
		return begin_;
	}

	iterator end() {
		return end_;
	}

	void push_back(const Type& element) {
		if (size_ < capacity_) {
			++size_;
		}
		++end_;
		*(end_ - 1) = element;
		if (end_ == begin_) {
			++begin_;
		}
	}

	void push_front(const Type& element) {
		if (size_ < capacity_) {
			++size_;
		}
		--begin_;
		*(begin_) = element;
		if (begin_ == end_) {
			--end_;
		}
	}

	void pop_back() {
		//add exceptions
		--end_;
		--size_;
	}

	void pop_front() {
		//add exceptions
		++begin_;
		--size_;
	}

	Type& back() {
		//add exceptions
		return *(end_ - 1);
	}

	Type& front() {
		//add exceptions
		return *begin_;
	}

	void insure_capacity(int capacity) {
		if (capacity == capacity_) {
			return;
		}
		Type* newBuffer = new Type[capacity + 1];
		if (capacity > capacity_) {
			iterator it = begin_;
			for (int i(0); i < size_; ++i) {
				newBuffer[i] = *it;
				++it;
			}
			delete[] buffer_;
			buffer_ = newBuffer;
			capacity_ = capacity;
			begin_ = iterator(buffer_, this);
			end_ = iterator(buffer_ + size_, this);
		} else {
			if (size_ > capacity) {
				size_ = capacity;
			}
			iterator it = end_ - 1;
			for (int i(capacity - 1); i >= 0; --i) {
				newBuffer[i] = *it;
				--it;
			}
			delete[] buffer_;
			buffer_ = newBuffer;
			capacity_ = capacity;
			begin_ = iterator(buffer_, this);
			end_ = iterator(buffer_ + size_, this);
		}
	}

	RingBuffer& operator=(const RingBuffer& other) {
		if (this == &other) {
			return *this;
		}
		Type* newBuffer = new Type[other.capacity_ + 1];
		iterator it = other.begin_;
		for (int i(0); i < other.size_; ++i) {
			newBuffer[i] = *it;
			++it;
		}
		delete[] buffer_;
		buffer_ = newBuffer;
		size_ = other.size_;
		capacity_ = other.capacity_;
		begin_ = iterator(buffer_, this);
		end_ = iterator(buffer_ + size_, this);
	}

	Type& operator[](int index) {
		return *(begin_ + index);
	}

	const Type& operator[](int index) const {
		return *(begin_ + index);
	}

	~RingBuffer() {
		delete[] buffer_;
	}

private:
	Type* buffer_;
	int capacity_;
	int size_;
	iterator begin_;
	iterator end_;
	friend iterator;
};