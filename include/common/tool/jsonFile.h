/**
 * @file  jsonFile.h
 * @author  qinmoM
 * @version  v3
 */

#pragma once

#include "json.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

/**
 *              jsons handle
 * @brief  A class handles all files
 * @details   Create an object for reading and writing json files, and read/write the files based on the parameters.
 */
class jsonHandle
{
public:
    jsonHandle();
    ~jsonHandle();

public:
    /// @brief  Read json file data
    /// @param file_path  file path
    /// @param json_object  json object for reception
    /// @return  Return true if read successful ;  return false if file opening fails or the format is incorrect.
    bool read(const std::string& file_path, nlohmann::json& json_object) const;

    /// @brief  Read ordered_json file data
    /// @param file_path  file path
    /// @param json_object  ordered_json object for reception
    /// @return  Return true if read successful ;  return false if file opening fails or the format is incorrect.
    bool read(const std::string& file_path, nlohmann::ordered_json& json_object) const;

    /// @brief  Write json file data (Cover)
    /// @param file_path  file path
    /// @param json_object  json object to be written into
    /// @return  Return true if write successful;  Otherwise, return false.
    bool write(const std::string& file_path, const nlohmann::json& json_object) const;

    /// @brief  Write ordered_json file data (Cover)
    /// @param file_path  file path
    /// @param json_object  ordered_json object to be written into
    /// @return  Return true if write successful;  Otherwise, return false.
    bool write(const std::string& file_path, const nlohmann::ordered_json& json_object) const;

};

/**
 *              jsons handle
 * @brief  One class corresponds to one files
 * @details  Create an object for reading and writing json files, with one object corresponding to one file.
 */
class jsonFile
{
public:
    jsonFile(const std::string& file_path);
    ~jsonFile();

public:
    /// @brief  Read json file data
    /// @param json_object  json object for reception
    /// @return  Return true if read successful ;  return false if file opening fails or the format is incorrect.
    bool read(nlohmann::json& json_object) const;

    /// @brief  Read ordered_json file data
    /// @param json_object  ordered_json object for reception
    /// @return  Return true if read successful ;  return false if file opening fails or the format is incorrect.
    bool read(nlohmann::ordered_json& json_object) const;

    /// @brief  Write json file data (Cover)
    /// @param json_object  json object to be written into
    /// @return  Return true if write successful;  Otherwise, return false.
    bool write(const nlohmann::json& json_object) const;

    /// @brief  Write ordered_json file data (Cover)
    /// @param json_object  ordered_json object to be written into
    /// @return  Return true if write successful;  Otherwise, return false.
    bool write(const nlohmann::ordered_json& json_object) const;

private:
    std::string file_path_;

};

//          jsonHandle implementation

jsonHandle::jsonHandle() = default;

jsonHandle::~jsonHandle() = default;

bool jsonHandle::read(const std::string& file_path, nlohmann::json& json_object) const
{
    std::ifstream ifs(file_path);

    if (!ifs.is_open())
    {
        std::cerr << file_path << ", json file cannot be opened!" << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    try
    {
        json_object = nlohmann::json::parse(buffer.str());
        return true;
    }
    catch (nlohmann::json::parse_error& e)
    {
        std::cerr << "Json file parse error in " << file_path << " : " << e.what() << '\n';
        return false;
    }
}

bool jsonHandle::read(const std::string& file_path, nlohmann::ordered_json& json_object) const
{
    std::ifstream ifs(file_path);

    if (!ifs.is_open())
    {
        std::cerr << file_path << ", json file cannot be opened!" << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    try
    {
        json_object = nlohmann::ordered_json::parse(buffer.str());
        return true;
    }
    catch (nlohmann::json::parse_error& e)
    {
        std::cerr << "Json file parse error in " << file_path << " : " << e.what() << '\n';
        return false;
    }
}

bool jsonHandle::write(const std::string& file_path, const nlohmann::json& json_object) const
{
    std::ofstream ofs(file_path);
    if (!ofs.is_open())
    {
        std::cerr << file_path << ", json file cannot be opened!" << std::endl;
        return false;
    }
    ofs << json_object.dump(4);
    ofs.close();
    return true;
}

bool jsonHandle::write(const std::string& file_path, const nlohmann::ordered_json& json_object) const
{
    std::ofstream ofs(file_path);
    if (!ofs.is_open())
    {
        std::cerr << file_path << ", json file cannot be opened!" << std::endl;
        return false;
    }
    ofs << json_object.dump(4);
    ofs.close();
    return true;
}

//          jsonFile implementation

jsonFile::jsonFile(const std::string& file_path)
    : file_path_(file_path)
{ }

jsonFile::~jsonFile() = default;

bool jsonFile::read(nlohmann::json& json_object) const
{
    std::ifstream ifs(file_path_);

    if (!ifs.is_open())
    {
        std::cerr << file_path_ << ", json file cannot be opened!" << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();
    
    try
    {
        json_object = nlohmann::json::parse(buffer.str());
        return true;
    }
    catch (nlohmann::json::parse_error& e)
    {
        std::cerr << "Json file parse error in " << file_path_ << " : " << e.what() << '\n';
        return false;
    }
}

bool jsonFile::read(nlohmann::ordered_json& json_object) const
{
    std::ifstream ifs(file_path_);

    if (!ifs.is_open())
    {
        std::cerr << file_path_ << ", json file cannot be opened!" << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();
    
    try
    {
        json_object = nlohmann::ordered_json::parse(buffer.str());
        return true;
    }
    catch (nlohmann::json::parse_error& e)
    {
        std::cerr << "Json file parse error in " << file_path_ << " : " << e.what() << '\n';
        return false;
    }
}

bool jsonFile::write(const nlohmann::json& json_object) const
{
    std::ofstream ofs(file_path_);
    if (!ofs.is_open())
    {
        std::cerr << file_path_ << ", json file cannot be opened!" << std::endl;
        return false;
    }
    ofs << json_object.dump(4);
    ofs.close();
    return true;
}

bool jsonFile::write(const nlohmann::ordered_json& json_object) const
{
    std::ofstream ofs(file_path_);
    if (!ofs.is_open())
    {
        std::cerr << file_path_ << ", json file cannot be opened!" << std::endl;
        return false;
    }
    ofs << json_object.dump(4);
    ofs.close();
    return true;
}
