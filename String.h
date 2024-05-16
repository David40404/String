#pragma once
#include <iostream>

namespace String {
  class String {
  	char* m_str;
  	size_t m_length;
  public:
  	String(size_t length = 0) : m_length(length) {
  		m_str = new char[m_length];
  
  		for (size_t i = 0; i < m_length; ++i) {
  			m_str[i] = '\0';
  		}
  	}
  
  	String(size_t length, char ch) : m_length(length+1) {
  		m_str = new char[m_length];
  
  		for (size_t i = 0; i < m_length; ++i) {
  			m_str[i] = ch;
  		}
  
  		m_str[m_length - 1] = '\0';
  	}
  
  	String(const char* str) : m_length(strlen(str)+1) {
  		m_str = new char[m_length];
  
  		if (m_str != NULL) {
  			strncpy(m_str, str, m_length);
  		}
  	}
  
  	~String() {
  		delete[] m_str;
  	}

    char* data() {
      return m_str;
    }
  
  	char* c_str() {
  		return m_str;
  	}
  
  	size_t length() {
  		return m_length;
  	}
  
  	void to_upper() {
  		for (int i = 0; i < m_length; i++) {
  			m_str[i] = toupper(m_str[i]);
  		}
  	}
  
  	void to_lower() {
  		for (int i = 0; i < m_length; i++) {
  			m_str[i] = tolower(m_str[i]);
  		}
  	}
  
  	char& at(size_t index) {
  		return m_str[index % (m_length - 1)];
  	}
  
  	char& operator[](size_t index) {
  		return m_str[index];
  	}
  
  	char& back() {
  		return m_str[m_length - 2];
  	}
  
  	String& operator=(const char* str) {
  		m_length = strlen(str) + 1;
  
  		delete[] m_str;
  
  		m_str = new char[m_length];
  
  		if (m_str != NULL) {
  			strncpy(m_str, str, m_length);
  		}
  	}
  
  	String& operator=(const String& str) {
  		m_length = str.m_length;
  
  		delete[] m_str;
  
  		m_str = new char[m_length];
  
  		if (m_str != NULL) {
  			strncpy(m_str, str.m_str, m_length);
  		}
  	}
  
  	friend std::ostream& operator<< (std::ostream& out, const String& str) {
  		out << str.m_str;
  		return out;
  	}
  
  	friend istream& operator>>(istream& in, String& str) {
  		char buf[8192];
  
  		in.getline(buf, 8192);
  
  		delete[] str.m_str;
  
  		str.m_length = strlen(buf) + 1;
  		str.m_str = new char[str.m_length];
  
  		strncpy(str.m_str, buf, str.m_length);
  
  		return in;
  	}
  };
}
