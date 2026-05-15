#include "FacadeOperationResult.h"

FacadeOperationResult::FacadeOperationResult(bool success, const std::string& error) {
    isSuccess = success;
    errorMessage = error;
}

std::string FacadeOperationResult::GetErrorMessage() const {
    return errorMessage;
}

bool FacadeOperationResult::IsSuccess() const {
    return isSuccess;
}
