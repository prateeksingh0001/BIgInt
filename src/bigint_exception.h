#ifndef SYMENGINE_EXCEPTION_H
#define SYMENGINE_EXCEPTION_H

typedef enum {
    BIGINT_NO_EXCEPTION = 0,
    BIGINT_DIV_BY_ZERO = 1,
    BIGINT_NOT_IMPLEMENTED = 2,
    BIGINT_RUNTIME_ERROR = 3,
} bigint_exceptions_t;

#include <exception>
#include <string>

class BigIntException : public std::exception
{
    std::string m_msg;
    bigint_exceptions_t ec;

public:
    BigIntException(const std::string &msg, bigint_exceptions_t error)
            : m_msg(msg), ec(error)
    {
    }

    BigIntException(const std::string &msg)
        : BigIntException(msg, BIGINT_RUNTIME_ERROR)
    {
    }
    const char *what() const throw()
    {
        return m_msg.c_str();
    }
    bigint_exceptions_t error_code()
    {
        return ec;
    }
};

class DivisionByZeroError : public BigIntException
{
public:
    DivisionByZeroError(const std::string &msg)
        : BigIntException(msg, BIGINT_DIV_BY_ZERO)
    {
    }
};

class NotImplementedError : public BigIntException
{
public:
    NotImplementedError(const std::string &msg)
        : BigIntException(msg, BIGINT_NOT_IMPLEMENTED)
    {
    }
};

#endif // SYMENGINE_EXCEPTION_H
