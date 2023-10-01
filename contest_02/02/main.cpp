bool compare(const std::string& left, const std::string& right)
{
    bool equal = std::count(left.begin(), left.end(), '1') > std::count(right.begin(), right.end(), '1');
    bool bigger = std::count(left.begin(), left.end(), '1') == std::count(right.begin(), right.end(), '1') && std::stoi(left) < std::stoi(right);

    return equal || bigger;
}
