#pragma once
#include <fstream>
#include "DataSource.h"

template <typename T>
class FileDataSource : public DataSource<T> {
public:
    FileDataSource(const char* fileName);
    FileDataSource(const FileDataSource& other);
    FileDataSource& operator=(const FileDataSource& other) = delete;
    ~FileDataSource() noexcept;

    virtual T getNext() override;
    virtual DataSourceArray<T> getNext(size_t count) override;
    virtual bool hasNext() override;
    virtual bool reset() override;
    virtual DataSource<T>* clone() const override;

private:
    const char* fileName;
    std::ifstream file;
    bool hasEnough;
};
