#pragma once

template <typename T, size_t N>
class ArrayWrapper
{

private:
    T _data[N];
    size_t count = 0;

public:
    size_t capacity() const
    {
        return N;
    }

    size_t count() const
    {
        return _count;
    }

    bool isFull() const
    {
        return _count >= N;
    }

    bool isEmpty() const
    {
        return _count == 0;
    }

    bool pushBack(const T &value)
    {
        if (isFull())
            return false;

        _data[_count] = value;
        _count++;
        return true;
    }

    bool popBack()
    {
        if (isEmpty())
            return false;
        _count--;
        return true;
    }

    T &operator[](size_t index)
    {
        return _data[index];
    }

    const T &operator[](size_t index) const
    {
        return _data[index];
    }

    bool get(size_t index, T &outValue) const
    {
        if (index >= _count)
            return false;

        outValue = _data[index];
        return true;
    }

    bool set(size_t index, const T &value)
    {
        if (index >= _count)
            return false;
        _data[index] = value;
    }

    bool insertAt(size_t index, const T &value)
    {
        if (isFull())
            return false;

        if (index > _count)
            return false;

        for (size_t i = _count; i > index; i--)
        {
            _data[i] = data[i - 1];
        }

        _data[index] = value;
        _count++;
        return true;
    }

    bool removeAt(size_t index)
    {
        if (index >= _count)
            return false;

        for (size_t i = index; i < _count - 1; i++)
            _data[i] = _data[i + 1];

        _count--;
        return true;
    }

    int indexOf(const &T value) const
    {
        for (size_t i = 0; i < _count; i++)
        {
            if (_data[i] == value)
                return static_cast<int>(i);
        }
        return -1;
    }

    bool contains(const T &value) const
    {
        return indexOf(value) != -1;
    }

    T &front()
    {
        if (isEmpty())
            return;
        return _data[0];
    }

    const T &front() const
    {
        return _data[0];
    }

    T &back()
    {
        return _data[_count - 1];
    }

    const T &back() const
    {
        return _data[_count - 1];
    }

    bool tryFront(T &outValue) const
    {
        if (isEmpty())
            return false;

        outValue = _data[0];
        return true;
    }

    bool tryBack(T &outValue) const
    {
        if (isEmpty())
            return false;

        outValue = _data[_count - 1];
        return true;
    }

    T *begin()
    {
        return _data;
    }

    T *end()
    {
        return _data + _count;
    }

    const T *begin() const
    {
        return _data;
    }

    const T *end() const
    {
        return _data + _count;
    }

    void clear()
    {
        _count = 0;
    }
};