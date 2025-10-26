/* Имя игрового персонажа состоит из одного слова и максимум 7 символов. 
При этом первая буква должна быть строчная, остальные - прописные. 
Напишите функцию, которая будет любое введенное слово выводить в требуемом формате.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string ENTER_NAME = "Enter character name: ";

string formatName(const string& srcName) {
    string resultName = srcName;

    if (resultName.length() > 7) resultName = resultName.substr(0, 7);

    resultName[0] = tolower(resultName[0]);
    for (int i = 1; i < resultName.length(); ++i) resultName[i] = toupper(resultName[i]);

    return resultName;
}

int main() {
    string inputName;
    
    cout << ENTER_NAME;
    cin >> inputName;
    
    string formattedName = formatName(inputName);
    cout << formattedName << endl;
    
    return 0;
}