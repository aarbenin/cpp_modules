#include "Contact.hpp"

Contact::Contact(const std::string &fName, const std::string &lName,
                 const std::string &nName, const std::string &phone,
                 const std::string &secret)
    : firstName(fName),
      lastName(lName),
      nickname(nName),
      phoneNumber(phone),
      darkestSecret(secret)
{
}
std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
