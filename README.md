# cpp

## Namespace
- 

```bash
namespace first {
    int x = 5;
}
namespace second {
    int x = 10;
}
int main()
{
    int x = 0;

    std::cout << first::x; // 5
}

# int main()
# {
#     using namespace second;

#     std::cout << x; // 10
# }
```