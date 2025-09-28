#include <iostream>

#include <iostream>
#include <string>


int main()
{
    double floating_point_value = 0.3768; // Example floating-point value
    int fractional_bits = 15;
    int fixed_point_value = static_cast<int>(floating_point_value * (1 << fractional_bits) + 0.5); // Add 0.5 for rounding
    // fixed_point_value = (int)(0.3768 * 32768 + 0.5)

    // double fixed_point_value = 1234.4321; 
    // int fractional_bits = 8;
    // double floating_point_value = static_cast<double>(fixed_point_value) / (1 << fractional_bits);
    // In Q15, 1 << 15 is 32768.
    // So, floating_point_value = 12345 / 32768.0
    std::cout << fixed_point_value << std::endl;
}
