#include "colorapi.hpp"
#include "utils.hpp"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

void newtask(std::string name,int time,std::vector<std::string>tasks)
{
std::ofstream file(name+".tsk");
file<<time<<std::endl;
for (size_t i = 0; i < tasks.size(); i++)
{
file<<tasks[i]<<std::endl;
}
file.close();
}

std::vector<std::string> readtask(const std::string& name)
{
std::vector<std::string> lines;
std::ifstream file(name+".tsk");

if (!file){return {};}

std::string line;
while (std::getline(file,line))
{
lines.push_back(line);
}

file.close();

return lines;
}



void printtasks(int done,std::vector<std::string>tasks,std::vector<int>times)
{
for (size_t i = 1; i < tasks.size(); i++)
{


if (done>i)
{settextcolor(2);}
else
{settextcolor(1);}

std::cout<<tasks[i];
settextcolor(7);

if (times.size()>i)
{
if (times[i]>=0)
{std::cout<<" [+"<<times[i];}
else
{std::cout<<" ["<<times[i];}
std::cout<<"]";
}
std::cout<<std::endl;
}
settextcolor(7);

}



void makeatask()
{
clearscreen();
std::string name;
int timetodo;
int size;

std::vector<std::string>tasks;

std::cout<<"name of your task: ";
std::cin>>name;

std::cout<<"time to do your task(seconds): ";
std::cin>>timetodo;

std::cout<<"size of your task: ";
std::cin>>size;

std::string task;
for (size_t i = 0; i < size; i++)
{

std::cout<<"task "<<i<<": ";
std::cin>>task;
tasks.push_back(task);
}

newtask(name,timetodo,tasks);
}

void loadtask()
{
clearscreen();
std::string name;

std::cout<<"name of your task: ";
std::cin>>name;

std::vector<std::string>tasks=readtask(name);

clock_t st_time;
clock_t end_time;

int tasks_done=1;
int time_to_do_it=std::stoi(tasks[0]) / (tasks.size()-1);


std::vector<int>times;


while (tasks_done<=tasks.size()-1)
{
clearscreen();
printtasks(tasks_done-1,tasks,times);

st_time=clock();
std::cin.ignore();
end_time=clock();
times.push_back(time_to_do_it-((end_time-st_time)/1000));


tasks_done++;

}



}



int main()
{
int choice=0;
enableANSI();

while (true){
clearscreen();

settextcolor(1);
std::cout<<"1-create a task"<<std::endl;
std::cout<<"2-load a task"<<std::endl;
std::cout<<"@: ";
settextcolor(7);
std::cin>>choice;


switch (choice)
{
case 1:
makeatask();

break;

case 2:
loadtask();
break;


default:
    break;
}


}
settextcolor(7);
return 0;
}