aaoaaaaaaaaeqaa

# cpp

## Namespace
- you should avoid using it with `std::` cause this one has many entities 

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

    std::cout << first::x; # 5
}

# int main()
# {
#     using namespace second;

#     std::cout << x; // 10
# }
```
- better way to do it
```bash
int main()
{
    using std::cout;

    cout << "hello world\n"; 
}
```

## typedef and aliases
```bash
typedef std::string text_t;

int main()
{
    # using text_t = std::string;       // another way to do it

    text_t madani = "madani";

    std::cout << "what is " << madani << "\n";
}
```
