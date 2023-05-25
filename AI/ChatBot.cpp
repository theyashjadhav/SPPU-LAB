#include <iostream>
#include <string>
using namespace std;
string getResponse(const string &userMessage)
{
    // Add your own custom logic here to generate appropriate responses
    if (userMessage == "hi" || userMessage == "hello")
    {
        return "Hello! How can I assist you today?";
    }
    else if (userMessage == "how are you?" || userMessage == "how are you doing?")
    {
        return "I'm a chatbot, so I don't have feelings, but I'm here to help you!";
    }
    else if (userMessage == "bye")
    {
        return "Goodbye! Have a great day!";
    }
    else
    {
        return "I'm sorry, I didn't understand that. Can you please rephrase your message?";
    }
}
int main()
{
    cout << "Chatbot: Hello! How can I assist you today?" << endl;
    while (true)
    {
        cout << "User: ";
        string userMessage;
        getline(cin, userMessage);
        string response = getResponse(userMessage);
        cout << "Chatbot: " << response << endl;
        if (userMessage == "bye")
        {
            break;
        }
    }
    return 0;
}
