#include <bits/stdc++.h>
using namespace std;

//bool option=true;
struct Task{
    string taskName;
    bool completed;
};

vector<Task>tasks;

void addTask(){
    string task;
cout<<"Enter the task:";
cin.ignore();
    getline(cin,task);
    tasks.push_back({task, false});
    cout<<"Task added: "<<task<<endl;
    /*option =0;
    cout<<"Do yo want to return (true/false)";
    cin>>option;*/
}
void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks found\n";
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            string status = tasks[i].completed ? "Completed" : "Pending";
            cout << i + 1 << "- " << tasks[i].taskName << " - " << status << endl;
        }
    }

}
void completeTask(){
    showTasks();
    int num;
    cout<<"Enter the task number to mark it as completed:";
    cin>>num;
    if(num >=1&&num<=tasks.size()){
        tasks[num-1].completed=true;
        cout<<"Task marked as completed.\n";
    }
    else
        cout<<"Invalid task number.\n";

}
void removeTask(){
    showTasks();
    int num;
    cout<<"Enter the task number to remove it:";
    cin>>num;
    if(num >=1&&num<=tasks.size()){
        cout<<"Task removed "<<tasks[num-1].taskName<<endl;
      tasks.erase(tasks.begin()+num-1);
        cout<<"Task marked as completed.\n";
    }
    else
        cout<<"Invalid task number.\n";



}

int main(){
    
    cout<<endl<<"TO-DO LIST\n";
while (true){
    cout<<"\n Options:\n";
    cout<<"1- Add task.\n";
    cout<<"2- View tasks. \n";
    cout<<"3- Mark as complete. \n";
    cout<<"4- Remove task. \n";
    cout<<"5- Quit. \n";
    int choice;
    cout<<"Enter your choice:";
    cin>>choice;

    switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            showTasks();
            break;
        case 3:
            completeTask();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            return 0;
        default:
            cout<<"Invalid choice please try again! \n";

    }

}



}
