#pragma once

#include  <iostream>

class String
{
    int length;
    int maxSize;
    char* buffer;

public:
    String(int maxSize) : length(0), maxSize(maxSize), buffer(new char[maxSize + 1]) {}

    // Move constructor
    String(String&& other) noexcept : length(other.length), maxSize(other.maxSize), buffer(other.buffer)
    {
        other.buffer = nullptr;
        other.length = 0;
        other.maxSize = 0;
    }

    ~String()
    {
        delete[] buffer;
    }

    String operator+(const String& other) const
    {
        String result(maxSize + other.maxSize);
        int i = 0;
        for (; i < length; ++i)
        {
            result.buffer[i] = buffer[i];
        }
        for (int j = 0; j < other.length; ++j)
        {
            result.buffer[i + j] = other.buffer[j];
        }
        result.length = length + other.length;
        result.buffer[result.length] = '\0';
        return result;
    }

    char& operator[](int index)
    {
        return buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str)
    {
        os << str.buffer;
        return os;
    }

    bool operator<(const String& other) const
    {
        int result = 0;
        int i = 0;
        while (result == 0 && i < length && i < other.length)
        {
            result = buffer[i] - other.buffer[i];
            ++i;
        }
        if (result == 0)
        {
            result = length - other.length;
        }
        return result < 0;
    }

    bool operator>(const String& other) const
    {
        return other < *this;
    }

    bool operator<=(const String& other) const
    {
        return !(other < *this);
    }

    bool operator>=(const String& other) const
    {
        return !(*this < other);
    }

    bool operator==(const String& other) const
    {
        if (length != other.length)
        {
            return false;
        }
        for (int i = 0; i < length; ++i)
        {
            if (buffer[i] != other.buffer[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const String& other) const
    {
        return !(*this == other);
    }

    void append(const char* text)
    {
        int i = 0;
        while (text[i] != '\0' && length < maxSize)
        {
            buffer[length++] = text[i++];
        }
        buffer[length] = '\0';
    }

    void appendLine(const char* text)
    {
        append(text);
        append("\n");
    }

    void print(std::ostream& os) const
    {
        os << buffer << std::endl;
    }
};