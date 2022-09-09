#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
class ToDoList
{
private:
    const std::string m_Title;
    mutable std::vector<std::pair<bool,std::string>> m_Todos;
public:
    explicit ToDoList(const std::string& title):m_Title{title}{};
    inline void add(const std::string& todo)const{
        m_Todos.push_back(std::make_pair(false,todo));
    }
    inline const std::string& getTitle()const{return m_Title;}
    inline const std::vector<std::pair<bool,std::string>>& getTodos()const{return m_Todos;}
    inline void print()const{
        std::cout<<m_Title<<std::endl;
        for(auto& todo : m_Todos)
            std::cout<<"\t"<<((todo.first) ? "[*] " : "[ ] ")<<todo.second<<std::endl;
    }
    inline void setChecked(const unsigned int& index,const bool& state){
        m_Todos[index].first =state;
    }
    inline void erase(const unsigned int& index){
        m_Todos.erase(m_Todos.begin()+index);
    }
};

class Serialization
{
public:
    static void save2disk(const ToDoList& todoList, const std::string& filename){
        std::ofstream ofs(filename);
        ofs<<todoList.getTitle()<<std::endl;
        for(auto& todo : todoList.getTodos())
            ofs<<"\t"<<((todo.first) ? "[*] " : "[ ] ")<<todo.second<<std::endl;
    }
    // static void save2cloud(const ToDoList& todoList){
    //     //...
    // }
};

int main(){
    ToDoList todoList("New");
    todoList.add("Coffee!");
    todoList.print();
    todoList.setChecked(0,true);
    todoList.print();
    todoList.add("Coding!");
    todoList.print();
    todoList.setChecked(1,true);
    todoList.print();
    todoList.erase(1);
    todoList.print();
    todoList.add("Coding!");
    todoList.print();

    Serialization::save2disk(todoList,"out.txt");
    return 0;
}