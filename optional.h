#pragma once

#if __cplusplus >= 201703L
#include <optional>
template<class T>
using optional = std::optional<T>;

#else
template<class T>
class optional
{
public:
    optional() {}
    optional(const T& val) : _value(val), _state(true) {}
    const T& value() const {
        return _value;
    }
    T& value() {
        return _value;
    }
    bool has_value() const {
        return _state;
    }
    operator bool() {
        return _state;
    }
    operator bool() const {
        return _state;
    }
    void reset() {
        _value.T::~T();
        _state = false;
    }
    template<class U>
    const T value_or(const U& default_value) {
        if (_state) {
            return _value;
        } else {
            return default_value;
        }
    }
private:
    T _value {};
    bool _state {false};
};
#endif

