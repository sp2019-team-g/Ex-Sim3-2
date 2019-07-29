void ErrorHandler::HandleRunTimeError(const std::runtime_error & e)
{
    std::cout << "Error caught:  " << e.what() << std::endl;
}

void ErrorHandler::HandleUnknownError()
{
    std::cout << "Unknown error caught" << std::endl;
}
