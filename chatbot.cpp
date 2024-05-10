#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

string getResponse(const string& userInput) {
    string response;
    string lowerInput = toLowerCase(userInput);

    if (lowerInput.find("hello") != string::npos || lowerInput.find("hi") != string::npos) {
        response = "Hello! How can I help you today?";
    } else if (lowerInput.find("how are you") != string::npos || lowerInput.find("how's it going") != string::npos) {
        response = "I'm just a chatbot, but I'm doing well. Thanks for asking!";
    } else {
        response = "I'm sorry, I didn't understand that. Can you please rephrase?";
    }

    return response;
}

int main() {
    string userInput;

    cout << "Chatbot: Hello! How can I assist you today?" << endl;
    cout << "You: ";
    getline(cin, userInput);

    while (userInput != "exit") {
        string response = getResponse(userInput);
        cout << "Chatbot: " << response << endl;

        cout << "You: ";
        getline(cin, userInput);
    }

    cout << "Chatbot: Goodbye! Have a great day." << endl;

    return 0;
}

