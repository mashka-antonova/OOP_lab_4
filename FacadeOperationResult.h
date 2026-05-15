#pragma once

#include <string>

class FacadeOperationResult {
private:
    std::string errorMessage;
    bool isSuccess;

public:
    FacadeOperationResult(bool success, const std::string& error);
    std::string GetErrorMessage() const;
    bool IsSuccess() const;
};
