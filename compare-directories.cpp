#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <filesystem>
#include <regex>
#include <algorithm>
#include <iterator>

using namespace std;
namespace fs = std::filesystem;

set<string> get_problem_directories_from_readme(const string& readme_path)
{
    set<string> problem_dirs;
    ifstream readme_file(readme_path);
    string line;
    regex problem_regex(R"(\[(C|C\+\+)\]\(([^)]+)\))");

    // skip until "## All Problems"
    bool start_parsing = false;
    while (getline(readme_file, line))
    {
        if (line == "## All Problems")
        {
            start_parsing = true;
            break;
        }
    }

    while (start_parsing && getline(readme_file, line))
    {
        smatch match;
        if (regex_search(line, match, problem_regex))
        {
            string path = match[2].str();
            size_t pos = path.find('/');
            if (pos != string::npos)
                problem_dirs.insert(path.substr(0, pos));
        }
    }

    return problem_dirs;
}

set<string> get_actual_directories(const set<string>& ignored_dirs)
{
    set<string> actual_dirs;

    for (const auto& entry : fs::directory_iterator("."))
    {
        if (entry.is_directory())
        {
            string dir_name = entry.path().filename().string();
            if (ignored_dirs.find(dir_name) == ignored_dirs.end())
                actual_dirs.insert(dir_name);
        }
    }

    return actual_dirs;
}

set<string> set_difference(const set<string>& set1, const set<string>& set2)
{
    set<string> result;
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                        std::inserter(result, result.end()));
    return result;
}

int main()
{
    set<string> ignored_dirs = {"docs", ".github", ".vscode", ".git"};
    ifstream gitignore(".gitignore");
    string line;

    while (getline(gitignore, line))
        if (!line.empty() && line[0] != '#')
            ignored_dirs.insert(line);

    set<string> problem_dirs = get_problem_directories_from_readme("README.md");
    set<string> actual_dirs = get_actual_directories(ignored_dirs);

    set<string> excessive_dirs = set_difference(actual_dirs, problem_dirs);
    set<string> missing_dirs = set_difference(problem_dirs, actual_dirs);

    cout << "Missing directories:" << endl;
    int i = 1;
    for (const auto& dir : missing_dirs)
        cout << i++ << ": " << dir << endl;
    if (i == 1)
        cout << "(empty)" << endl;

    cout << "Excessive directories:" << endl;
    i = 1;
    for (const auto& dir : excessive_dirs)
        cout << i++ << ": " << dir << endl;
    if (i == 1)
        cout << "(empty)" << endl;

    return 0;
}

// Run:
// g++ count-directories.cpp && ./a.out
// to print missing and excessive directories comparing actual dirs and README.md "All problems" list
