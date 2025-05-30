#pragma once

class Company;

class Worker {
public:
    Worker();
    Worker(const char* firstName, const char* lastName, double salary, Worker* boss = nullptr);
    Worker(const Worker& other);
    Worker& operator=(const Worker& other);
    ~Worker();

    void setFirstName(const char* fname);
    void setLastName(const char* lname);
    void setSalary(double s);
    void setBoss(Worker* b);
    void setCompany(Company* c);

    const char* getFirstName() const;
    const char* getLastName() const;
    double getSalary() const;
    int getId() const;
    Worker* getBoss() const;
    Company* getCompany() const;

    bool isBoss() const;
    void print() const;

private:
    static int nextId;
    int id;
    char* firstName;
    char* lastName;
    double salary;
    Worker* boss;
    Company* company;

    void copy(const Worker& other);
    void freeDyn();
};
