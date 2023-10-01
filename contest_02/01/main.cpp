#include <math.h>

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(abs(n)); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
