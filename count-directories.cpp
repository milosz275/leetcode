#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void count_directories()
{
    set<string> ignored_dirs = {"docs", ".github", ".vscode"};
    ifstream gitignore(".gitignore");
    string line;

    while (getline(gitignore, line))
        if (!line.empty() && line[0] != '#')
            ignored_dirs.insert(line);

    int count = 0;
    for (const auto& entry : fs::directory_iterator("."))
    {
        if (entry.is_directory())
        {
            string dir_name = entry.path().filename().string();
            if (ignored_dirs.find(dir_name) == ignored_dirs.end())
            {
                count++;
                cout << count << ": " << dir_name << '\n';
            }
        }
    }
    cout << "Number of directories: " << count << '\n';
}

int main()
{
    count_directories();
    return 0;
}

// Run:
// g++ count-directories.cpp && ./a.out
// to print how many task directories are in the root directory
