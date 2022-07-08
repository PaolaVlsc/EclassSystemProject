//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_COURSE_H
#define ECLASSSYSTEMPROJECT_COURSE_H




#include <string>

using std::string;

class Course {
private:
    string courseCode;
    string courseName;
    unsigned int courseSemester;

public:
    Course(const string &courseCode, const string &courseName, unsigned int courseSemester);

    // Copy Constructor
    Course(const Course &);

    virtual ~Course();

    // setters
    void setCourseCode(const string &courseCode);

    void setCourseName(const string &courseName);

    void setCourseSemester(unsigned int courseSemester);

    // getters
    const string &getCourseCode() const;

    const string &getCourseName() const;

    unsigned int getCourseSemester() const;
};





#endif //ECLASSSYSTEMPROJECT_COURSE_H
