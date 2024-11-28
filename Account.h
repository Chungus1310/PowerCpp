#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string username;
    std::string status;
public:
    Account(const std::string& un, const std::string& st = "Regular");
    ~Account();
    std::string getStatus() const;
};

#endif // ACCOUNT_H