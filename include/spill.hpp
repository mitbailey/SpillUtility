/**
 * @file spill.hpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version See Git tags for version information.
 * @date 2022.05.25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SPILL_HPP
#define SPILL_HPP

/**
 * @brief Attempts to rename a directory from src to dest.
 * 
 * @param src Original directory path.
 * @param dest New directory path.
 * @return int 0 on success, -1 on failure.
 */
int redir(std::string src, std::string dest);

#endif // SPILL_HPP