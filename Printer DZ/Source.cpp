#include <iostream>
#include <string>
using namespace std;

template<class T>
class Queue
{
private:
    T* arr;
    int size;
    int counter;
public:
    Queue() : size(0), arr(nullptr), counter(0)
    {   }
    Queue(int size)
    {
        this->size = size;
        arr = new T[this->size];
        counter = 0;
    }
    void AddElement(T element)
    {
        if (this->CheckQueue() != false)
        {
            this->arr[this->counter] = element;
            this->counter++;
        }
    }
    void DeleteElementQueue()
    {
        if (this->counter != 0)
        {
            T* tmp = new T[this->counter]();
            for (int i = 0; i < this->counter; i++)
            {
                tmp[i] = this->arr[i];
                this->arr[i] = 0;
            }
            for (int i = 0; i < this->counter - 1; i++)
            {
                this->arr[i] = tmp[i + 1];
            }
            this->counter--;
            delete[] tmp;
        }
        else
        {
            this->CheckQueue();
        }
    }
    void DeleteElementQueuePriority()
    {
        if (this->counter != 0)
        {
            T* tmp = new T[this->counter - 1];
            T temp = this->arr[0];
            int count = 0;
            int value = 0;
            for (int i = 0; i < this->counter; i++)
            {
                if (temp < arr[i])
                {
                    temp = arr[i];
                }
            }
            for (int i = 0; i < this->counter; i++)
            {
                if (arr[i] == temp)
                    value++;
            }
            for (int i = 0; i < this->counter; i++)
            {
                if (this->arr[i] != temp)
                {
                    tmp[count] = this->arr[i];
                    count++;
                }
                if (this->arr[i] == temp && value > 1)
                {
                    tmp[count] = this->arr[i];
                    count++;
                    value--;
                }
            }
            for (int i = 0; i < this->counter - 1; i++)
            {
                this->arr[i + 1] = tmp[i];
            }
            this->arr[0] = temp;
            DeleteElementQueue();
            delete[] tmp;
            count = 0;
        }
        else
        {
            this->CheckQueue();
        }
    }
    bool CheckQueue()
    {
        if (this->counter < this->size)
        {    return 1;     }
        else
        {   return 0;     }
    }
    void ShowQueue() const
    {
        for (int i = 0; i < this->counter; i++)
        {
            cout << this->arr[i] << "   ";
        }
        cout << endl;
    }
    ~Queue()
    {
        delete[] arr;
    }
};
class Time
{
private:
    int minutes;
    int hours;
    int seconds;
public:
    Time() :minutes(0), hours(0), seconds(0)
    {   }
    Time(int h, int m, int s)
    {
        this->hours = h;
        this->minutes = m;
        this->seconds = s;
    }
    void ShowTime()
    {
        cout << "Time: ";
        if (hours < 10)
            cout << "0" << hours << ":";
        else
            cout << hours << ":";
        if (minutes < 10)
            cout << "0" << minutes << ":";
        else
            cout << minutes << ":";
        if (seconds < 10)
            cout << "0" << seconds;
        else
            cout << seconds;
        cout << endl;
    }
    void SetHours(int h)
    {
        if (h <= 12 && h >= 0 || h <= 24 && h >= 0)
        {
            this->hours = h;
        }
    }
    void SetMinutes(int m)
    {
        if (m <= 60 && m >= 0)
        {
            this->minutes = m;
        }
    }
    void SetSeconds(int s)
    {
        if (s <= 60 && s >= 0)
        {
            this->seconds = s;
        }
    }
    int GetHours()
    {
        return this->hours;
    }
    int GetMinutes()
    {
        return this->minutes;
    }
    int GetSeconds()
    {
        return this->seconds;
    }
};
class Document
{
private:
    string name;
    int sizee;
    Time* time;
    int priority;
public:
    Document() :name(""), sizee(0), time(0), priority(0)
    {   }
    Document(string name, int sizee, Time* time, int priority)
    {
        this->name = name;
        this->sizee = sizee;
        this->time = time;
        this->priority = priority;
    }
    void Show()
    {
        cout << "Name: " << this->GetName() << endl;
        cout << "Size: " << this->Getsizee() << endl;
        this->time->ShowTime();
        cout << "Priority: " << this->GetPriority() << endl;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()
    {
        return this->name;
    }
    void Setsizee(int sizee)
    {
        this->sizee = sizee;
    }
    int Getsizee()
    {
        return this->sizee;
    }
    void SetTime(int h, int m, int s)
    {
        this->time->SetHours(h);
        this->time->SetMinutes(m);
        this->time->SetSeconds(s);
    }
    Time& GetTime()
    {
        return *time;
    }
    void SetPriority(int priority)
    {
        this->priority = priority;
    }
    int GetPriority()
    {
        return this->priority;
    }
    ~Document()
    {
        delete[] time;
    }
};
int main()
{
    string symbol = "";
    Time time(12, 52, 35);
    Document u = { "Salary", 29,  &time, 15 };
    u.Show();
    Time time1(9, 24, 27);
    Document u1 = { "Bookkeeping", 28,  &time1, 25 };
    u1.Show();
    Time time2(8, 13, 21);
    Document u2 = { "Office document", 35, &time2, 8 };
    u2.Show();
    cout << "Send document to printer enter y:" << endl;
    cin >> symbol;
    if (symbol == "y")
    {
        system("cls");
        Queue<int> printer(3);
        printer.AddElement(u.GetPriority());
        printer.AddElement(u1.GetPriority());
        printer.AddElement(u2.GetPriority());
        printer.ShowQueue();
        printer.DeleteElementQueuePriority();
        printer.ShowQueue();
        printer.DeleteElementQueuePriority();
        printer.ShowQueue();
        printer.DeleteElementQueuePriority();
        printer.ShowQueue();
    }
    else
    {
        cout << "You canceled print documents" << endl;
    }
    
    system("pause");
    return 0;
}