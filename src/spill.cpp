/**
 * @file spill.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief Moves the contents of each directory in the current directory to the current directory.
 * @version See Git tags for version information.
 * @date 2021.11.26
 *
 * @copyright Copyright (c) 2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <cstdio>
#include <iostream>
#include <filesystem>
#include <time.h>

// Spills the contents of files into the current directory.
// Currently has the issue of not being able to merge same-named directories.

// Renames src to dest. In the event of name directory name conflicts it merges the directories.
int redir(std::string src, std::string dest)
{
    // If our destination path already exists.
    if (std::filesystem::exists(dest))
    {
        // TODO: It should be invalid for src to be a file at this point... although directory_iterator may throw for us.
        // In this case, there already exists a file with the desired name. Either an overwrite or rename must occur.
        // Here we choose to error out and crash.
        if (!std::filesystem::is_directory(dest))
        {
            std::cout << "ERROR: The destination " << dest << " already exists and is a file!" << std::endl;
            return -1;
        }

        // Iterate through all files & directories in source path.
        for (const auto &entry : std::filesystem::directory_iterator(src))
        {
            // 
            std::string filename = entry.path().string();
            filename = filename.substr(filename.find_last_of("/\\"));

            std::string src_path = src + "\\" + filename;
            std::string dest_path = dest + "\\" + filename;

            if (entry.is_directory())
            {
                redir(src_path, dest_path);
            }
            else
            {
                std::filesystem::rename(src_path, dest_path);
            }
        }
    }
    // The destination is new, rename.
    else
    {
        std::filesystem::rename(src, dest);
    }

    // If the source path is still around, delete it.
    if (std::filesystem::exists(src))
    {
        std::filesystem::remove(src);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    for (const auto &entry : std::filesystem::directory_iterator("."))
    {
        if (entry.is_directory())
        {
            std::cout << "Spilling " << entry.path() << " into " << std::filesystem::current_path() << std::endl;

            for (const auto &sub_entry : std::filesystem::directory_iterator(entry.path()))
            {
                // First get the file's path, then the file's name.
                std::string filename = sub_entry.path().string();
                filename = filename.substr(filename.find_last_of("/\\"));

                std::cout << "Renaming " << sub_entry.path() << " as " << std::filesystem::current_path().string() + filename << std::endl;

                redir(sub_entry.path().string(), std::filesystem::current_path().string() + filename);
            }

            std::filesystem::remove(entry.path());
        }
    }

    // Operation complete.
    std::cout << "Everything is OK." << std::endl;

    return 0;
}