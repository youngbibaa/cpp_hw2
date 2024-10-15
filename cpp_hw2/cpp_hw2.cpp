#include <iostream>
using namespace std;

class Phonebook
{
private:
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilephone[20];
    char contactInfo[256];
    uint16_t contactCount;

public:
    int id;
    Phonebook() : fullName(nullptr) {}
    Phonebook(int id, const char* fullName, const char* homePhone, const char* workPhone,
        const char* mobilephone, const char* contactInfo) : id { id } 
    {
        Phonebook::fullName = new char[strlen(fullName) + 1];
        strcpy_s(Phonebook::fullName, strlen(fullName) + 1, fullName);

        strcpy_s(Phonebook::homePhone, homePhone);
        strcpy_s(Phonebook::workPhone, workPhone);
        strcpy_s(Phonebook::mobilephone, mobilephone);
        strcpy_s(Phonebook::contactInfo, contactInfo);

        contactCount++;
    }

    ~Phonebook() {
        delete[] fullName;
        fullName = nullptr;
    }

    static void getContact(Phonebook& phonebook){
        cout << "id: " << phonebook.id << endl;
        for (int i = 0; i < strlen(phonebook.fullName); i++) {
            cout << phonebook.fullName[i];
        }
        cout << endl;
        for (int i = 0; i < strlen(phonebook.homePhone); i++) {
            cout << phonebook.homePhone[i];
        }
        cout << endl;
        for (int i = 0; i < strlen(phonebook.workPhone); i++) {
            cout << phonebook.workPhone[i];
        }
        cout << endl;
        for (int i = 0; i < strlen(phonebook.mobilephone); i++) {
            cout << phonebook.mobilephone[i];
        }
        cout << endl;
        for (int i = 0; i < strlen(phonebook.contactInfo); i++) {
            cout << phonebook.contactInfo[i];
        }
        cout << endl;
    }
};



int main()
{
    setlocale(LC_ALL, "rus");

    char* fullName = new char[256];
    char homePhone[20];
    char workPhone[20];
    char mobilephone[20];
    char contactInfo[256];

    uint16_t choice = 1;
    uint16_t count = 0;
    Phonebook* contacts = new Phonebook[512];

    while (choice != 0) {
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "------------Меню-------------" << endl;
        cout << "1. Добавить новый контакт" << endl;
        cout << "2. Удалить контакт" << endl;
        cout << "3. Поиск контакта" << endl;
        cout << "0. Выход" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;

        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            count++;

            cout << "Введите ФИО: ";
            cin.getline(fullName, 256);

            cout << "Введите домашний телефон: ";
            cin >> homePhone;

            cout << "Введите рабочий телефон: ";
            cin >> workPhone;

            cout << "Введите мобильный телефон: ";
            cin >> mobilephone;

            cout << "Введите информацию: ";
            cin >> contactInfo;

            Phonebook phonebook{ count, fullName, homePhone, workPhone, mobilephone, contactInfo };
            contacts[count-1] = phonebook;
        }
        else if (choice == 2) {
            int idDelete;
            cout << "Введите id для удаления контакта: ";
            cin >> idDelete;
            for (int i = 0; i < count; i++)
            {
                if (contacts[i].id == idDelete) {
                    contacts[i].~Phonebook();
                }
            }
            for (uint16_t i = idDelete; i < count - 1; ++i) {
                contacts[i] = contacts[i + 1];
            }

            count--;
        }
        else if(choice == 3){
            int idFind;
            cout << "Введите id для поиска: ";
            cin >> idFind;
            for (int i = 0; i < count; i++)
            {
                if (contacts[i].id == idFind) {
                    Phonebook::getContact(contacts[i]);
                }
            }
        }
    }
}
