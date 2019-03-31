#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

bool errorreturn(const std::string & errorobject, const std::string & errormessage, std::ostream & errorstream)
{
    errorstream << ">>"<< errorobject << "<<, " << errormessage;
    return false;
}

std::string trim(const std::string & s)
{
    size_t l = s.length();
    if (l == 0)
        return s;
    size_t b = s.find_first_not_of(" \t\r\n\0");
    if (b == std::string::npos)
        b = 0;
    size_t e = s.find_last_not_of(" \t\r\n\0");
    if (e == std::string::npos)
        return s.substr(b);
    return s.substr(b, e-b+1);
}

std::string makelower(const std::string & s)
{
    std::string str = s;
    for( std::string::iterator i = str.begin(); i != str.end(); ++i)
        if (tolower(*i) != (int)*i)
            *i = (char)tolower(*i);
    return str;
}

std::string value_for_key(const std::string & s, const std::string & k)
{
    size_t p = s.find('=');
    if (p == std::string::npos || trim(makelower(s.substr(0,p))) != k)
        return "";
    p = s.find_first_not_of(" \t\n\r\0", p+1);
    // check for empty value and return space char
    if (p == std::string::npos)
        return " ";

    return s.substr(p);
}

bool getini(const std::string & inifile, const std::string & section, const std::string & key, std::string & value, std::ostream & error_out)
{
    std::string   s, k;
    std::string   sec = std::string("[") + makelower(section) + "]";
    std::ifstream file( inifile.c_str() );
    if (!file)
       return errorreturn(key, "file could not be opened", error_out);
    k = trim(makelower(key));
    bool found_section  = false;
    while (std::getline(file, s))
    {
       if (! found_section)
       {
          if (trim(makelower(s)) == sec)
              found_section = true;
          continue;
       }
       // check for next section
       s = trim(s);
       int l;
       if ((l = s.length()) > 1 && s[0] == '[' && s[l-1] == ']')
           // break loop if next section begins
           break;
       value = value_for_key(trim(s), k);
       if (value.length())
       {
           // close file before return
           file.close();
           return true;
       }
    }
    file.close();
    return found_section
        ? errorreturn(key, "key not found", error_out)
        : errorreturn(section, "section not found", error_out);
}