#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

public:
    BrowserHistory() {
        currentPage = "Home";
        cout << "Starting at: " << currentPage << endl;
    }


    void visitPage(const string& page) {
        if (!currentPage.empty()) {
            backStack.push(currentPage);
        }
        currentPage = page;

        while (!forwardStack.empty()) {
            forwardStack.pop();
        }
        cout << "Visited: " << currentPage << endl;
    }


    void goBack() {
        if (backStack.empty()) {
            cout << "No pages in back history." << endl;
            return;
        }
        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();
        cout << "Back to: " << currentPage << endl;
    }

    void goForward() {
        if (forwardStack.empty()) {
            cout << "No pages in forward history." << endl;
            return;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();
        cout << "Forward to: " << currentPage << endl;
    }

    void displayCurrentPage() const {
        cout << "Current page: " << currentPage << endl;
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit Page\n2. Back\n3. Forward\n4. Display Current Page\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                browser.visitPage(page);
                break;
            case 2:
                browser.goBack();
                break;
            case 3:
                browser.goForward();
                break;
            case 4:
                browser.displayCurrentPage();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
