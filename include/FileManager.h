#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

class FileManager
{
    public:
        FileManager(void);
        ~FileManager(void);

        void loadContent(const char* filename,
                         std::vector<std::vector<std::string> >& attr,
                         std::vector<std::vector<std::string> >& contents);

        void loadContent(const char* filename,
                         std::vector<std::vector<std::string> >& attr,
                         std::vector<std::vector<std::string> >& contents,
                         std::string id);
    protected:
    private:
        std::vector<std::string> tempAttr;
        std::vector<std::string> tempContent;
        bool idFound;

};

#endif // FILEMANAGER_H
