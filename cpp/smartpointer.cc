#include<iostream>
#include<memory>

std::unique_ptr<int>  returnUniquePtr()
{
  std::unique_ptr<int> ret(new int(10));

  return ret;
}

int main()
{
  std::cout << *(returnUniquePtr()) << std::endl;

  return 0;
}
