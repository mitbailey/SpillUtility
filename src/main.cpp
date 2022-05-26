/**
 * @file main.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version See Git tags for version information.
 * @date 2022.05.25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <filesystem>
#include "spill.hpp"

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        std::cout << "Usage: [Directory to Spill] [Directory to Place Contents]" << std::endl;
        return -1;
    }

    std::string spillable;
    std::string dumpable = std::filesystem::current_path().string();

    switch (argc)
    {
    case 3:
    {
        dumpable = argv[2];
    }
    case 2:
    {
        spillable = argv[1];
    }
    }

    if (!spillable.empty()) // Spill one specific directory.
    {
        std::cout << "Spilling " << spillable << " into " << dumpable << std::endl;

        for (const auto &sub_entry : std::filesystem::directory_iterator(spillable))
        {
            // First get the file's path, then the file's name.
            std::string filename = sub_entry.path().string();
            filename = filename.substr(filename.find_last_of("/\\"));

            std::cout << "Renaming " << sub_entry.path() << " as " << std::filesystem::current_path().string() + filename << std::endl;

            redir(sub_entry.path().string(), dumpable + filename);
        }

        std::filesystem::remove(spillable);
    }
    else // Spill all in local directory.
    {
        for (const auto &entry : std::filesystem::directory_iterator("."))
        {
            if (entry.is_directory())
            {
                std::cout << "Spilling " << entry.path() << " into " << dumpable << std::endl;

                for (const auto &sub_entry : std::filesystem::directory_iterator(entry.path()))
                {
                    // First get the file's path, then the file's name.
                    std::string filename = sub_entry.path().string();
                    filename = filename.substr(filename.find_last_of("/\\"));

                    std::cout << "Renaming " << sub_entry.path() << " as " << std::filesystem::current_path().string() + filename << std::endl;

                    redir(sub_entry.path().string(), dumpable + filename);
                }

                std::filesystem::remove(entry.path());
            }
        }
    }

    // Operation complete.
    std::cout << "Everything is OK." << std::endl;

    return 0;
}