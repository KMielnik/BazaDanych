#include "schoolClass.hpp"
#include <string>
#include <algorithm>
#include <vector>

void schoolClass::dodajUcznia(std::string imie,
                              std::string nazwisko,
                              std::string pesel)
{
  student uczen;
  uczen.imie = imie;
  uczen.nazwisko = nazwisko;
  uczen.pesel = pesel;
  uczniowie.push_back(uczen);

  sortujUczniow();

}

void schoolClass::dodajBlanka()
{
  student uczen;
  uczen.imie = "";
  uczen.nazwisko = "";
  uczen.pesel = "";
  uczniowie.push_back(uczen);

  for(unsigned int i=0;i<uczniowie.size();i++)
    uczniowie.at(i).nrDziennika = i+1;
}

void schoolClass::sortujUczniow()
{
  std::sort(uczniowie.begin(),uczniowie.end(),
            [](const student  &a, const student &b)
             { return a.nazwisko < b.nazwisko; });

  for(unsigned int i=0;i<uczniowie.size();i++)
    uczniowie.at(i).nrDziennika = i+1;
}

void schoolClass::edytujImieUcznia( int id, std::string wartosc )
{
  uczniowie.at(id).imie = wartosc;
}

void schoolClass::edytujNazwiskoUcznia( int id, std::string wartosc )
{

  uczniowie.at(id).nazwisko = wartosc;
}

void schoolClass::edytujPeselUcznia( int id, std::string wartosc )
{
  uczniowie.at(id).pesel = wartosc;
}

void schoolClass::usunUcznia(std::string nazwisko)
{
  for(unsigned int i=0;i<uczniowie.size();i++)
    if(uczniowie.at(i).nazwisko == nazwisko)
      uczniowie.erase(uczniowie.begin() + i);
}

void schoolClass::usunUcznia( int ID )
{
  uczniowie.erase(uczniowie.begin() + ID);
}

void schoolClass::usunWszystkichUczniow()
{
  for(unsigned int i=0;i<uczniowie.size();i++)
    uczniowie.erase(uczniowie.begin() + i);
}

unsigned int schoolClass::znajdzUcznia(std::string nazwisko)
{
  for(unsigned int i=0;i<uczniowie.size();i++)
    if(uczniowie.at(i).nazwisko == nazwisko)
      return i;
  return -1;

}

std::vector<student> schoolClass::wyswietl()
{
  return uczniowie;
}
