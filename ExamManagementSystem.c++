#include <iostream>
#include <string>

using namespace std;

class Exam
{
public:
    string subject;
    string date;
    string time;
    int duration;
    string location;

    Exam(const string &sub, const string &dt, const string &t, int dur, const string &loc)
        : subject(sub), date(dt), time(t), duration(dur), location(loc) {}
};

class Node
{
public:
    Exam data;
    Node *left;
    Node *right;

    Node(const Exam &exam) : data(exam), left(nullptr), right(nullptr) {}
};

class ExamManagementSystem
{
private:
    Node *root;

    Node *insert(Node *root, const Exam &exam)
    {
        if (root == nullptr)
        {
            return new Node(exam);
        }

        if (exam.subject < root->data.subject)
        {
            root->left = insert(root->left, exam);
        }
        else if (exam.subject > root->data.subject)
        {
            root->right = insert(root->right, exam);
        }

        return root;
    }

    Node *search(Node *root, const std::string &subject)
    {
        if (root == nullptr || root->data.subject == subject)
        {
            return root;
        }

        if (subject < root->data.subject)
        {
            return search(root->left, subject);
        }

        return search(root->right, subject);
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *remove(Node *root, const std::string &subject)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (subject < root->data.subject)
        {
            root->left = remove(root->left, subject);
        }
        else if (subject > root->data.subject)
        {
            root->right = remove(root->right, subject);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data.subject);
        }

        return root;
    }

public:
    ExamManagementSystem() : root(nullptr) {}

    void addExam(const Exam &exam)
    {
        root = insert(root, exam);
    }

    Exam *findExam(const string &subject)
    {
        Node *result = search(root, subject);
        return (result != nullptr) ? &(result->data) : nullptr;
    }

    void updateExam(const string &subject, const Exam &newExam)
    {
        root = remove(root, subject);
        root = insert(root, newExam);
    }

    void deleteExam(const string &subject)
    {
        root = remove(root, subject);
    }
};

int main()
{
    int choice;
    ExamManagementSystem ems;

    while (true)
    {
        cout << "-----------Exam Management System-----------\n";
        cout << "1. Create Exam\n";
        cout << "2. Find Exam\n";
        cout << "3. Update Exam\n";
        cout << "4. Delete Exam\n";
        cout << "5. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string inputSubject, inputDate, inputTime, inputLocation;
            int inputDuration;
            cout << "Enter subject: ";
            cin >> inputSubject;
            cout << "Enter date: ";r
            cin >> inputDate;
            cout << "Enter time: ";
            cin >> inputTime;
            cout << "Enter duration: ";
            cin >> inputDuration;
            cout << "Enter location: ";
            cin >> inputLocation;
            ems.addExam(Exam(inputSubject, inputDate, inputTime, inputDuration, inputLocation));
            break;
        }
        case 2:
        {
            string inputSubject;
            cout << "Enter subject: ";
            cin >> inputSubject;
            Exam *exam = ems.findExam(inputSubject);
            if (exam != nullptr)
            {
                cout << "Exam Found:\n";
                cout << "Subject: " << exam->subject << "\n";
                cout << "Date: " << exam->date << "\n";
                cout << "Time: " << exam->time << "\n";
                cout << "Duration: " << exam->duration << "\n";
                cout << "Location: " << exam->location << "\n";
            }
            else
            {
                cout << "Exam Not Found\n";
            }
            break;
        }
        case 3:
        {
            string inputSubject, inputDate, inputTime, inputLocation;
            int inputDuration;
            cout << "Enter subject: ";
            cin >> inputSubject;

            Exam *exam = ems.findExam(inputSubject);
            if (exam != nullptr)
            {
                cout << "Enter date: ";
                cin >> inputDate;
                cout << "Enter time: ";
                cin >> inputTime;
                cout << "Enter duration: ";
                cin >> inputDuration;
                cout << "Enter location: ";
                cin >> inputLocation;
                ems.updateExam(inputSubject, Exam(inputSubject, inputDate, inputTime, inputDuration, inputLocation));
                cout << "Exam updated.\n";
            }
            else
            {
                cout << "Exam not found.\n";
            }
            break;
        }
        case 4:
        {
            string inputSubject;
            cout << "Enter subject: ";
            cin >> inputSubject;
            Exam *exam = ems.findExam(inputSubject);
            if (exam != nullptr)
            {
                ems.deleteExam(inputSubject);
                cout << "Exam deleted.\n";
            }
            else
            {
                cout << "Exam not found.\n";
            }
            break;
        }
        case 5:
            return 0;
        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }
    }
    return 0;
}
